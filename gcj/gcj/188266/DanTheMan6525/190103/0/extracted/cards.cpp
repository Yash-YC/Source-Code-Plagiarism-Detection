#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

double calcDecks(double cardNum, double packSize)
{
	double cardsHad = 0.0;
	double decksNeeded = 0.0;
	for (double i = 0; i < cardNum;)
	{
		double newCardChanceInDeck = (1.0 - (double)i / cardNum) * packSize;
		double decksForNewCard = 1.0 / newCardChanceInDeck;

		double iAdd, deckAdd;
		if (decksForNewCard < 1.0)
		{
			deckAdd = 1.0f;
			iAdd = newCardChanceInDeck;
			
		}
		else
		{
			deckAdd = decksForNewCard;
			iAdd = 1.0f;
		}
		if (i + iAdd > cardNum)
		{
			deckAdd = deckAdd * (cardNum - i) / iAdd;
			decksNeeded += deckAdd;
			break;
		}
		else
		{
			decksNeeded += deckAdd;
			i += iAdd;
		}
	}
	return decksNeeded;
}
int main()
{
	string INFILE = "C:\\CodeJam\\Cards\\C-small-attempt2.in";
	//string INFILE = "C:\\CodeJam\\Cards\\test-in.txt";
	string OUTFILE = INFILE + ".out.txt";

	ifstream inFile(INFILE.c_str());
	ofstream outFile(OUTFILE.c_str());


	int t;
	inFile >> t;
	for (int caseId = 1; caseId <= t; caseId++)
	{
		int cards, packs;
		inFile >> cards >> packs;
		outFile << "Case #" << caseId << ": " << calcDecks(cards,packs) << endl;
	}
	return 0;
}