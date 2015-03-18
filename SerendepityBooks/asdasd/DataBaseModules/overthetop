


#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
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
			return 2;
		case ('s') :
			return 3;
		case ('d') :
			return 4;
		case ('f') :
			return 5;
		case ('g') :
			return 6;
		case ('h') :
			return 7;
		case ('j') :
			return 8;
		case ('k') :
			return 9;
		case ('l') :
			return 10;
		case ('z') :
			return 3;
		case ('x') :
			return 4;
		case ('c') :
			return 5;
		case ('v') :
			return 6;
		case ('b') :
			return 7;
		case ('n') :
			return 8;
		case ('m') :
			return 9;
		case (',') :
			return 10;


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
			return 2;
		case ('S') :
			return 3;
		case ('D') :
			return 4;
		case ('F') :
			return 5;
		case ('G') :
			return 6;
		case ('H') :
			return 7;
		case ('J') :
			return 8;
		case ('K') :
			return 9;
		case ('L') :
			return 10;
		case ('Z') :
			return 3;
		case ('X') :
			return 4;
		case ('C') :
			return 5;
		case ('V') :
			return 6;
		case ('B') :
			return 7;
		case ('N') :
			return 8;
		case ('M') :
			return 9;

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
		int deltaSum = 0;
		for (int k = 0;( k < searchHashT.hashTableSize) && (k < hashT.hashTableSize); k++)
		{
			int hashTHashSearch = searchHashT.hashList[k];
			int hashTHashBase = hashT.hashList[k];
			cout << "hashTHashSearch is: " << hashTHashSearch << endl;
			cout << "hashTHashBase is: " << hashTHashBase << endl;
			deltaSum += abs((double)(hashTHashSearch - hashTHashBase));
		}
		cout << "Delta sum for base: " << listOfBooks[i].Title << ", is " << deltaSum << endl;
		deltaList.push_back(deltaSum);
	}
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
