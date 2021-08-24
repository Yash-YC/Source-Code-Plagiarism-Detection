#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <set>

using std::set;

typedef set<unsigned long long> num_set;

unsigned long long convert_from_decimal_to_base(unsigned long long num, int base) {
	unsigned long long new_num = 0;
	unsigned int k = 1;

	while (num > 0) {
		unsigned int rem = num % base;
		new_num += rem * (unsigned long long)pow(10, k - 1);
		num -= rem;
		num /= base;
		//printf("rem = %d, num = %lld, k = %d\n", rem, num, k);
		++k;
	}

	return new_num;
}

unsigned long long compute_sum_of_squares(unsigned long long num, int base) {
	unsigned long long sum = 0;
	while (num > 0) {
		unsigned int rem = num % 10;
		unsigned int square = rem * rem;
		sum += rem * rem;
		num = num / 10;
	}
	return convert_from_decimal_to_base(sum, base);
}

int main(int argc, char *argv[]) {
	FILE *f;
	int num_cases;
	char bases[11];
	char buf[100];
	char *token;

	f = fopen(argv[1], "r");
	fscanf(f, "%d\n", &num_cases);

	for (int i = 0; i < num_cases; ++i) {
		bzero(bases, 11);
		if (!fgets(buf, 100, f))
			break;
		buf[strlen(buf) - 1] = 0;

		token = strtok(buf, " ");
		do {
			int index = atoi(token);
			assert(index >= 2 && index <= 10);
			bases[index] = 1;
			token = strtok(NULL, " ");
		}
		while (token);

		unsigned long long n = 1;
		bool satisfied;
		do {
			satisfied = true;
			++n;
			for (int b = 2; b <= 10; ++b) {
				if (bases[b] != 1)
					continue;
				//printf("Considering number %lld with base %d\n", n, b);

				unsigned long long new_n = convert_from_decimal_to_base(n, b);
				num_set set_of_prev_nums;
				//printf("%lld is %lld in base %d\n", n, new_n, b);
				set_of_prev_nums.insert(new_n);
				while (new_n != 1) {
					new_n = compute_sum_of_squares(new_n, b);
					if (set_of_prev_nums.find(new_n) != set_of_prev_nums.end())
						break;
					set_of_prev_nums.insert(new_n);
					//printf("Considering %lld next\n", new_n);
				}
				if (new_n != 1) {
					//printf("Discarding %lld\n", n);
					satisfied = false;
					break;
				}
			}
		}
		while (!satisfied);
		printf("Case #%d: %lld\n", i, n);
	}
}
