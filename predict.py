









import sys
import os
import tensorflow as tf

model = tf.keras.models.load_model('events.out.tfevents.1570876197.HP')
with open("train/.syuuuuu/RoundOneA.java", 'r', errors='ignore') as file:
   sent = file.read().replace('\n', '')
print(sent)

# we can start to predict the results for each of the 4 sentences
res = model.predict([get_tf_record(sent)])
print(str(len(res[0]))+" "+str(len(categories)))