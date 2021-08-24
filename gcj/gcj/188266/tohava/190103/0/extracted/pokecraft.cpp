#include <iostream>
// #include <tr1/random>
#include <vector>
#include <cassert>

// std::tr1::mt19937 eng;

int g_nBoosterSize;
int g_nTotalTypes;

long long Comb(int n, int k) {
	assert(n >= k);
	long long nProd = 1;
	long long nProd2 = 1;
	for (int i = 1; i <= k; ++i) {
		nProd *= (n + 1 - i);
		nProd2 *= i;
	}
	return nProd / nProd2;
}

double ProbRec(int nCurrentTypes, int nTriesLeft) {
	const int nRemainingTypes = g_nTotalTypes - nCurrentTypes;
	double nRet = 0.0;
	if (nCurrentTypes == 0) {
		return ProbRec(g_nBoosterSize, nTriesLeft - 1);
	} else if (nCurrentTypes == g_nTotalTypes) {
		return nTriesLeft == 0 ? 1.0 : 0.0;
	} else if (nTriesLeft == 0) {
		return 0.0;
	} else {
		for (int i = std::min(g_nBoosterSize, nRemainingTypes); i >= 0; --i) {
			nRet += (Comb(nRemainingTypes, i) * Comb(nCurrentTypes, g_nBoosterSize - i) /
			         (double)Comb(g_nTotalTypes, g_nBoosterSize)) * ProbRec(nCurrentTypes + i, nTriesLeft - 1);
		}
	}
	assert(nRet <= 1.0);
	return nRet;
}

double CalculateSize(int nCardTypes, int nBoosterSize) {
	double nSum = 0;
	for (int i = 1; i < 20; ++i) {
		g_nBoosterSize = nBoosterSize;
		g_nTotalTypes = nCardTypes;
		nSum += i * ProbRec(0, i);
	}
	return nSum;
}

// double CalculateSize(int nCardTypes, int nBoosterSize) {
// 	std::tr1::uniform_int<int> unif(0, nCardTypes - 1);
// 	double nSum = 0.0;
// 	unsigned int nTries, nBoosterCount;
// 	std::vector<int> vecFlags;
// 	const int nTotalTries = 123456789;
// 	for (nTries = 0; nTries < nTotalTries; ++nTries) {
// 		int nCardCount = 0;
// 		vecFlags.resize(0); vecFlags.resize(nCardTypes, 0);
// 		while (nCardCount < nCardTypes) {
// 			for (nBoosterCount = 0; nBoosterCount < nBoosterSize; ++nBoosterCount)
// 			{
// 				unsigned int nCard = (int)(rand() / (RAND_MAX + 1.0) * (double)nCardTypes); // unif(eng);
// 				if (vecFlags[nCard] == 0) {
// 					vecFlags[nCard] = 1; ++nCardCount;
// 					if (nCardCount == nCardTypes) break;
// 				}
// 			}
// 			++nSum;
// 		}
// 	}
// 	return nSum / nTotalTries;
// }

int main() {
	int nCases;
	std::cin >> nCases;
	for (int i = 0; i < nCases; ++i) {
		int nCardTypes, nBoosterSize;
		std::cin >> nCardTypes;
		std::cin >> nBoosterSize;
		std::cout << "Case #" << (i + 1) << ": " << CalculateSize(nCardTypes, nBoosterSize) << std::endl;
	}
}
