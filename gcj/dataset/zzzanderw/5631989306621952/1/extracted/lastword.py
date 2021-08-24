input = file('A-large.in', 'r')
T = int(input.readline().strip())
for X in range(1,T+1):
	word = list(input.readline().strip())
	answer = ''
	for char in word:
		if answer == '':
			answer = char
		elif char < answer[:1]:
			answer = answer + char
		else:
			answer = char + answer
	print "Case #%d:" % X, answer
