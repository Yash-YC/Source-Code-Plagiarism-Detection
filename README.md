# Source-Code-Plagiarism-Detection

Referencce From Cyber Security Threats Detection in Internet of Things using Deep Learning Approach.

In this paper author is describing concept to detect plagiarism from software logic to detect piracy, some malicious programmer may copy logic from genuine software’s and create new program with Same logic and make available for download with cheaper rate, due to this copying of logic can put software market in huge loss, to overcome from such issue author has introduce DEEP Convolution Neural Network Approach to detect pirated software’s.

All existing techniques are design to detect piracy from specific language and they cannot detect piracy if coding done in different languages. But this propose technique works on TFIDF concept where any programming language logic will convert into words and then perform below steps to form vector.

- Pre-processing: in this step programs will be read and then convert into words array list and then remove all stop words, special characters from this word list.

- Tokenize: in this step stemming technique will be applied on all words to get its root words such as ‘coming’ will change to ‘come’

- TFIDF: in this step a matrix or bag of words vector will be from by taking all unique words and put it in vector column and then that vector row will be filled with count of word available in column. 

If any test programs have similar word then both test and train vector will have 1 value at their same column and similarity will be detected.

- Generate Model: in this model using DNN and SOFTMAX function and ADAM Optimizer we will build training model using TFIDF matrix.

- Predict Model: In this model we will upload test program to detect plagiarism, uploaded test program will be converted to matrix and 
this matrix will be applied on DNN train matrix to predict whether uploaded test program contains pirated copied  code or not.

To implement this project we used dataset from GOOGLE CODE JAM which contains logical programs From programmers.

## Screenshots:

- To run this project double click on ‘run.bat’ file to get below screen

![Text](Screenshot/ss1.png)


