#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Date.h"
#ifndef Included_NameModel_H
#define Included_NameModel_H
using namespace std;

//enum Type { ISBN, Title };

struct HashTable {
	vector <int> hashList;
	int hashTableSize;
};

class DatabaseModule
{
	private:
		vector <Book> listOfBooks;
		vector <HashTable> DBHashTable;
		vector <HashTable> DBHashTableISBN;
		void addBookToList(Book);
		void composeHashTable();
		void deleteBookUsingISBN(string);
		int getAdjustedChar(char);
		void searchByTitleWithString(string);
		void searchByISBNWithString(string);
		HashTable composeHashForCompare(string);
		vector <int> matchVectorMatrix;
	public:
		DatabaseModule();
		virtual ~DatabaseModule();
		void Loop();
		void Initialize();
		double PurchaseBook(Book, unsigned int);
		Book SearchForBook();
		Book* GetBookForEdit(string, int);
		void EditBook();
		Book AddBook();
		void deleteBook();
		void DisplayBook(Book);
};
#endif