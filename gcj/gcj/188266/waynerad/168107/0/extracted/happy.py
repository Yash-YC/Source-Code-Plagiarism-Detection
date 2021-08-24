def sum_of_digits_squared(num,base):
	total = 0
	while num != 0:
		rem = num % base
		total = total + (rem * rem)
		num = num - rem
		num = int(num / base)
	return total

def main():
	filename = "A-small-attempt1"
	infile = open(filename + ".in","r")
	outfile = open(filename + ".out","w")
	test_cases = infile.readline()
	test_cases = int(test_cases)
	for case_num in range(test_cases):
		bases_str = infile.readline()
		bases_s_list = bases_str.split()
		happiness_list = dict()
		bases_list = []
		for base_n_str in bases_s_list:
			base_num = int(base_n_str)
			bases_list.append(base_num)
			happiness_list[base_num] = dict()
		print("bases_list",bases_list)
		start_num = 1
		min_happy_not_found = True
		while min_happy_not_found:
			start_num = start_num + 1
			if start_num % 1000 == 0:
				print("   start_num",start_num)
			is_happy_this_time = []
			for this_base in bases_list:
				num = start_num
				we_did = []
				keep_going = True
				while keep_going:
					if num in happiness_list[this_base]:
						happy = happiness_list[this_base][num]
						if happy:
							happiness_list[this_base][num] = True
							for znum in we_did:
								happiness_list[this_base][znum] = True
							happiness_list[this_base][num] = True
							is_happy_this_time.append(True)
							keep_going = False
						else:
							is_happy_this_time.append(False)
							keep_going = False
					else:
						we_did.append(num)
						happiness_list[this_base][num] = False
						num = sum_of_digits_squared(num,this_base)
						if num == 1:
							for znum in we_did:
								happiness_list[this_base][znum] = True
							happiness_list[this_base][num] = True
							keep_going = False
							is_happy_this_time.append(True)
			all_good = True
			for result in is_happy_this_time:
				if result == False:
					all_good = False
			if all_good:
				min_happy_not_found = False
				min_happy_val = start_num
		print("min happy",min_happy_val)
		outfile.write("Case #" + str(case_num + 1) + ": " + str(min_happy_val) + "\n")
	infile.close()
	outfile.close()

main()
