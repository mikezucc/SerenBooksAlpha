


#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
//#include "Date.h"

using namespace std;

struct Book {

public:

	string ISBN;
	string Title;
	string Author;
	int dateAdded;
	unsigned int quantity;
	double wholesale;
	double retail;

	Book() { ISBN = ""; Title = ""; Author = ""; dateAdded = 0; quantity = 0; wholesale = 0; retail = 0; };
};

struct HashTable {
	vector <int> hashList;
	int hashTableSize;
};

class DataBaseMASTER
{
private:
	vector <Book> listOfBooks;
	vector <HashTable> DBHashTable;
public:
	void addBookToList(Book);
	void composeHashTable();
	void deleteBookUsingISBN(string);
	int getAdjustedChar(char);
	void searchWithString(string);
	HashTable composeHashForCompare(string);
	vector <int> matchVectorMatrix;
};

void DataBaseMASTER::addBookToList(Book book2Add)
{
	listOfBooks.push_back(book2Add);
}

void DataBaseMASTER::deleteBookUsingISBN(string ISBN)
{
	bool foundBook = false;
	int idx = 0;
	vector <Book> newListOfBooks;
	while (idx < listOfBooks.size())
	{
		Book compareBook = listOfBooks[idx++];
		if (compareBook.ISBN == ISBN)
		{
			foundBook = true;
		}
		else
		{
			newListOfBooks.push_back(compareBook);
		}
	}
	listOfBooks = newListOfBooks;
}

int DataBaseMASTER::getAdjustedChar(char passedChar) {
	switch (passedChar)
	{
		case ('q') :
			return 1;
		case ('w') :
			return 2;
		case ('e') :
			return 3;
		case ('r') :
			return 4;
		case ('t') :
			return 5;
		case ('y') :
			return 6;
		case ('u') :
			return 7;
		case ('i') :
			return 8;
		case ('o') :
			return 9;
		case ('p') :
			return 10;
		case ('a') :
			return 1;
		case ('s') :
			return 2;
		case ('d') :
			return 3;
		case ('f') :
			return 4;
		case ('g') :
			return 5;
		case ('h') :
			return 6;
		case ('j') :
			return 7;
		case ('k') :
			return 8;
		case ('l') :
			return 9;
		case ('z') :
			return 1;
		case ('x') :
			return 2;
		case ('c') :
			return 3;
		case ('v') :
			return 4;
		case ('b') :
			return 5;
		case ('n') :
			return 6;
		case ('m') :
			return 7;
		case (',') :
			return 8;


		case ('Q') :
			return 1;
		case ('W') :
			return 2;
		case ('E') :
			return 3;
		case ('R') :
			return 4;
		case ('T') :
			return 5;
		case ('Y') :
			return 6;
		case ('U') :
			return 7;
		case ('I') :
			return 8;
		case ('O') :
			return 9;
		case ('P') :
			return 10;
		case ('A') :
			return 1;
		case ('S') :
			return 2;
		case ('D') :
			return 3;
		case ('F') :
			return 4;
		case ('G') :
			return 5;
		case ('H') :
			return 6;
		case ('J') :
			return 7;
		case ('K') :
			return 8;
		case ('L') :
			return 9;
		case ('Z') :
			return 1;
		case ('X') :
			return 2;
		case ('C') :
			return 3;
		case ('V') :
			return 4;
		case ('B') :
			return 5;
		case ('N') :
			return 6;
		case ('M') :
			return 7;

		default :
			return 100;
	}
}

void DataBaseMASTER::composeHashTable() {
	Book bookToAnalyze;
	DBHashTable.clear();

	for (int i = 0; i < listOfBooks.size(); i++)
	{
		HashTable hashT;
		hashT.hashTableSize = 0;
		bookToAnalyze = listOfBooks[i];
		cout << "Processing: " << bookToAnalyze.Title << endl;
		string title = bookToAnalyze.Title;
		int hash = 0;
		for (int k = 0; k < title.length(); k++)
		{
			int adjustChar = getAdjustedChar(title.at(k));
			hash += adjustChar;
			cout << "\tChar #" << k << ", adusted: " << adjustChar << ", hash: " << hash << endl;
			hashT.hashList.push_back(hash);
			hashT.hashTableSize++;
		}
		DBHashTable.push_back(hashT);
	}
}

HashTable DataBaseMASTER::composeHashForCompare(string stringToHash)
{
	int hash = 0;
	HashTable hashT;
	hashT.hashTableSize = 0;
	for (int k = 0; k < stringToHash.length(); k++)
	{
		int adjustChar = getAdjustedChar(stringToHash.at(k));
		hash += adjustChar;
		hashT.hashList.push_back(hash);
		hashT.hashTableSize++;
	}
	return hashT;
}

void DataBaseMASTER::searchWithString(string searchQuery)
{
	vector <int> deltaList;
	HashTable searchHashT = composeHashForCompare(searchQuery);
	for (int i = 0; i < DBHashTable.size(); i++)
	{
		HashTable hashT = DBHashTable[i];
		string stringBase = listOfBooks[i].Title;
		int deltaSum = 0, charMatcher = 0, charMatcherBase = 0, charMatcherCompare = 0;
		for (int k = 0;( k < searchHashT.hashTableSize) && (k < hashT.hashTableSize); k++)
		{
			char charComp = getAdjustedChar(searchQuery.at(k));
			char charBase = getAdjustedChar(stringBase.at(k));
			charMatcherBase += (int)charBase;
			charMatcherCompare += (int)charComp;
			int hashTHashSearch = searchHashT.hashList[k];
			int hashTHashBase = hashT.hashList[k];
			//cout << "\thashTHashSearch is: " << charComp << endl;
			//cout << "\thashTHashBase is: " << charBase << endl;
			deltaSum += abs((double)(hashTHashSearch - hashTHashBase));
		}
		charMatcher = abs((double)(charMatcherBase - charMatcherCompare));
		//cout << "\t\tDelta sum for base: " << listOfBooks[i].Title << ", is " << deltaSum << endl;
		//cout << "\t\tChar matcher sum for base: " << listOfBooks[i].Title << ", is " << (int)charMatcher << endl;
		deltaList.push_back(deltaSum*charMatcher);
	}

	vector <int> deltaCopy;
	vector <string> listSortForSearch;
	for (int i = 0; i < deltaList.size(); i++)
	{
		int base = deltaList[i];
		string baseTitle = listOfBooks[i].Title;
		vector <int> temp;
		vector <string> tempTitle;
		if (deltaCopy.size() == 0)
		{
			deltaCopy.push_back(base);
			listSortForSearch.push_back(baseTitle);
			//cout << "Appending B: " << base << endl;
		}
		else
		{
			bool gradient = true;
			//cout << endl;
			for (int k = 0; k < deltaCopy.size(); k++)
			{
				//cout << "for k: " << k << endl;
				int compare = deltaCopy[k];
				string compareTitle = listSortForSearch[k];
				if (compare >= base && gradient)
				{
					temp.push_back(base);
					tempTitle.push_back(baseTitle);
					gradient = false;
					//cout << "Appending B: " << base << endl;
				}
				//cout << "Appending C: " << compare << endl;
				temp.push_back(compare);
				tempTitle.push_back(compareTitle);
			}
			if (gradient)
			{
				temp.push_back(base);
				tempTitle.push_back(baseTitle);
			}
			deltaCopy = temp;
			listSortForSearch = tempTitle;
		}
	}
	for (int k = 0; k < deltaCopy.size(); k++)
	{
		//cout << "ORDERED DELTA COPY >> " << deltaCopy[k] << endl;
		cout << "ORDERED DELTA COPY TITLE >> " << listSortForSearch[k] << ", with relScore: " << deltaCopy[k] << endl;
	}
	cout << endl;
}

int main()
{
	DataBaseMASTER dbmaster;
	for (int i = 0; i < 5; i++)
	{
		Book testBook;
		string bookTitle;
		cout << "Set title of book" << i << ": ";
		getline(cin, bookTitle);
		testBook.Title = bookTitle;
		dbmaster.addBookToList(testBook);
	}

	cout << "Composing hash table" << endl;
	
	dbmaster.composeHashTable();

	cout << "Ready to begin queries? (y/n) ";
	char yn;
	cin >> yn;
	if (yn)
	{
		bool continueQuery = true;
		while (continueQuery)
		{
			string searchQuery = "";
			cout << "Enter string: ";
			cin.ignore();
			getline(cin, searchQuery);
			dbmaster.searchWithString(searchQuery);
			cout << "Try another? ";
			char yn;
			cin >> yn;
			if (yn == 'n')
			{
				continueQuery = false;
			}
			system("CLS");
		}
	}

	system("pause");
}
