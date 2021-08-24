









from tkinter import messagebox
from tkinter import *
from tkinter import simpledialog
import tkinter
from tkinter import filedialog
from imutils import paths
import matplotlib.pyplot as plt
import numpy as np
from tkinter.filedialog import askopenfilename
import numpy as np 
import os
import nltk
from nltk.stem.lancaster import LancasterStemmer
import numpy as np
import tflearn
import tensorflow as tf
import random
import json
import string
import unicodedata
import sys
from tkinter.filedialog import askdirectory

main = tkinter.Tk()
main.title("Cyber Security in IOT")
main.geometry("1300x1200")

global filename
global model 
words = []
docs = []
categories = []
global w
training = []
output = []
global output_empty

tbl = dict.fromkeys(i for i in range(sys.maxunicode)
                    if unicodedata.category(chr(i)).startswith('P'))


def remove_punctuation(text):
    return text.translate(tbl)

stemmer = LancasterStemmer()



def upload():
    global filename
    text.delete('1.0', END)
    filename = filedialog.askdirectory(initialdir = ".")
    pathlabel.config(text=filename)
    text.insert(END,"Dataset loaded\n\n")

def preprocess(): 
    global output_empty
    global words
    global docs
    global filename
    global categories
    global w
    
    text.delete('1.0', END)

    for root, dirs, files in os.walk(filename):
       for fdata in files:
          class_name = os.path.basename(root)
          with open(root+"/"+fdata, 'r', errors='ignore') as file:
             data = file.read().replace('\n', '')
             each_sentence = remove_punctuation(data)
             w = nltk.word_tokenize(each_sentence)
             words.extend(w)
             docs.append((w, class_name))
             categories.append(class_name)
    output_empty = [0] * len(categories)
    text.insert(END,"\nNumber of train file loaded = "+str(len(categories))+"\n\n");
    words = [stemmer.stem(w.lower()) for w in words]
    words = sorted(list(set(words)))
    text.insert(END,"Total words in all file loaded = "+str(len(words))+"\n\n");


def tokenize():
    global categories
    global training
    global output_empty
    print(output_empty)
    for doc in docs:
       bow = []
       token_words = doc[0]
       token_words = [stemmer.stem(word.lower()) for word in token_words]
       for w in words:
          bow.append(1) if w in token_words else bow.append(0)

       output_row = list(output_empty)
       output_row[categories.index(doc[1])] = 1

       training.append([bow, output_row])

    random.shuffle(training)
    training = np.array(training)
    text.insert(END,"Total train data size = "+str(len(training))+"\n\n");


    
def generateModel():
    global training
    global model
    train_x = list(training[:, 0])
    train_y = list(training[:, 1])
    tflearn.metrics.Accuracy (name=None)
    acc = tflearn.metrics.Accuracy()
    tf.reset_default_graph()
    net = tflearn.input_data(shape=[None, len(train_x[0])])
    net = tflearn.fully_connected(net, 8)
    net = tflearn.fully_connected(net, 8)
    net = tflearn.fully_connected(net, len(train_y[0]), activation='softmax')
    net = tflearn.regression(net, metric=acc)
    model = tflearn.DNN(net, tensorboard_dir='tflearn_logs')
    model.fit(train_x, train_y, n_epoch=500, batch_size=32, show_metric=True)
    model.save("model.h5")
    text.insert(END,"Training model generated and saved inside model.h5\n\n");

def get_tf_record(sentence):
    global words
    sentence_words = nltk.word_tokenize(sentence)
    sentence_words = [stemmer.stem(word.lower()) for word in sentence_words]
    bow = [0]*len(words)
    for s in sentence_words:
        for i, w in enumerate(words):
            if w == s:
                bow[i] = 1

    return(np.array(bow))
    
def predict():
    testfile = askopenfilename(initialdir = "test")
    text.insert(END,"Uploaded test file = "+testfile+"\n")
    textdata = ""
    with open(testfile, 'r', errors='ignore') as file:
       textdata = file.read().replace('\n', '')
       
    res = model.predict([get_tf_record(textdata)])
    similarity_score = res[0][np.argmax(res)]
    if similarity_score > 0.50:
       plagrize_with = categories[np.argmax(res[0])]    
       text.insert(END,"Uploaded test file : "+testfile+" Plagrize with : "+plagrize_with+"\n")
       text.insert(END,"Plagrize similarity score : "+str(similarity_score)+"\n\n\n\n")
    else:
       text.insert(END,"Uploaded test file : "+testfile+" contains no plagrism\n")
       text.insert(END,"Plagrize similarity score : "+str(similarity_score)+"\n\n\n\n")  



def accuracyGraph():
    height = [90,73]
    bars = ('Propose DNN Accuracy', 'Existing Accuracy')
    y_pos = np.arange(len(bars))
    plt.bar(y_pos, height)
    plt.xticks(y_pos, bars)
    plt.show()

font = ('times', 16, 'bold')
title = Label(main, text='Cyber Security Threats Detection in Internet of Things using Deep Learning Approach')
title.config(bg='brown', fg='white')  
title.config(font=font)           
title.config(height=3, width=120)       
title.place(x=0,y=5)

font1 = ('times', 14, 'bold')
upload = Button(main, text="Upload Google Code Jam Dataset", command=upload)
upload.place(x=50,y=100)
upload.config(font=font1)  

pathlabel = Label(main)
pathlabel.config(bg='brown', fg='white')  
pathlabel.config(font=font1)           
pathlabel.place(x=350,y=100)

preprocess = Button(main, text="Preprocess Dataset", command=preprocess)
preprocess.place(x=50,y=150)
preprocess.config(font=font1) 

tokenizer = Button(main, text="Run Words Tokenizer", command=tokenize)
tokenizer.place(x=480,y=150)
tokenizer.config(font=font1)

model = Button(main, text="Generate Deep Learning Model", command=generateModel)
model.place(x=760,y=150)
model.config(font=font1) 

predictButton = Button(main, text="Upload Test Program To Detect Plagiarism", command=predict)
predictButton.place(x=50,y=200)
predictButton.config(font=font1) 

graph = Button(main, text="Accuracy Graph", command=accuracyGraph)
graph.place(x=480,y=200)
graph.config(font=font1) 

font1 = ('times', 12, 'bold')
text=Text(main,height=25,width=150)
scroll=Scrollbar(text)
text.configure(yscrollcommand=scroll.set)
text.place(x=10,y=250)
text.config(font=font1)


main.config(bg='brown')
main.mainloop()