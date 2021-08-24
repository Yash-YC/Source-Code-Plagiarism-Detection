test = int(input())

def theLastWord(word):
	newWord = word[0]

	for x in word[1:]:
		if(ord(x) < ord(newWord[0])):
			newWord = newWord + x
		else:
			newWord = x + newWord

	return newWord

for i in range(1, test+1):
	print("Case #%d: " % (i), theLastWord(input()))