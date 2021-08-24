
def main():
	t = int(raw_input())
	case = 1
	while case <= t:
		s = raw_input().strip()

		result = s[0]
		for c in s[1:]:
			if c >= result[0]:
				result = c + result
			else:
				result += c
		print 'Case #{}: {}'.format(case, result)
		case += 1

if __name__ == '__main__':
	main()