#include "DatabaseModule.h"
#include <fstream>

DatabaseModule::DatabaseModule()
{
	fstream infile;
	infile.open("sweet.txt");
	int i = 0;
	while (!infile.eof())
	{
		Book testBook;
		string bookTitle;
		//cout << "Set title of book" << i << ": ";
		getline(infile, bookTitle);
		testBook.Title = bookTitle;
		testBook.QuantityOnHand = i;
		testBook.WholesaleCost = i * 3;
		testBook.RetailPrice = i * 5;
		addBookToList(testBook);
		i++;
	}
	infile.close();
	cout << "Composing hash table" << endl;
	composeHashTable();
}


DatabaseModule::~DatabaseModule()
{

}

void DatabaseModule::Loop()
{
	bool Done = false;
	while (!Done)
	{
		char Choice;
		cout << "1. Look Up a Book\n";
		cout << "2. Add a Book\n";
		cout << "3. Edit a Book's Record\n";
		cout << "4. Delete a Book\n";
		cout << "5. Return to the Main Menu\n";
		cin >> Choice;
		cin.ignore();
		switch (Choice)
		{
		case '1':
			DisplayBook(SearchForBook());
			break;
		case '2':
			AddBook();
			break;
		case '3':
			EditBook();
			break;
		case '4':
			deleteBook();
			break;
		case '5':
			Done = true;
			break;
		default:
			cout << "Bad input\n";
			break;
		}
	}
}

double DatabaseModule::PurchaseBook(Book BK, unsigned int Quant)
{
	if (BK.QuantityOnHand >= Quant)
	{
		BK.QuantityOnHand -= Quant;
		return Quant * BK.RetailPrice;
	}
	else
		return 0;
}



Book DatabaseModule::SearchForBook()
{
	char choice = '0';
	Book BK;
	BK.ISBN = "0";
	while (choice == '0') //loop until valid choice
	{
		cout << "1. ISBN \n2. Title" << endl;
		cin >> choice;
		cin.ignore();
	}
	switch (choice)
	{
	case '1':
		//search for book using isbn
		while (BK.ISBN == "0")
		{
			string ISBN;
			cout << "Enter ISBN";
			getline(cin, ISBN);
			if (BK.ISBN == "0")
			{
				cout << "Sorry this book could not be found\n";
			}
		}
		break;
	case '2':
		//search for book using title
		while (BK.ISBN == "0")
		{
			string Title;
			cout << "Enter Title";
			getline(cin, Title);
			searchByTitleWithString(Title);
			if (BK.ISBN == "0")
			{
				cout << "Sorry this book could not be found\n";
			}
		}
	}
	return BK;
}

void DatabaseModule::EditBook()
{
	char choice;
	bool Done = false;
	cout << "Which Book\n";
	Book BK = SearchForBook();

	while (!Done)
	{
		cout << "What would you like to edit\n";
		cout << "1. ISBN \n	2. Title \n	3. Author \n 4. Publisher \n	5. DateAdded \n 6. Quantity \n 7. Wholsale Cost \n	8. Retail Price \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			getline(cin, BK.ISBN);
			break;
		case 2:
			getline(cin, BK.Title);
			break;
		case 3:
			getline(cin, BK.Author);
			break;
		case 4:
			getline(cin, BK.Publisher);
			break;
		case 5:
			//BK.DateAdded.InputDay();
			cout << "input day module not found" << endl;
			break;
		case 6:
			cin >> BK.QuantityOnHand;
			cin.ignore();
			break;
		case 7:
			cin >> BK.WholesaleCost;
			cin.ignore();
			break;
		case 8:
			cin >> BK.RetailPrice;
			cin.ignore();
			break;
		default:
			cout << "Please enter a valid choice\n";
		}

		cout << "Press q to stop editing\n";
		cin >> choice;
		if (choice == 'q')
			Done = true;
	}
}


Book DatabaseModule::AddBook()
{
	Book BK;

	cout << "Enter ISBN:";
	cin >> BK.ISBN;
	cin.ignore();

	cout << "Enter Title:";
	getline(cin, BK.Title);

	cout << "Enter Author:";
	getline(cin, BK.Author);

	cout << "Enter Publisher:";
	getline(cin, BK.Publisher);

	cout << "Enter Date Added:";
	//BK.DateAdded.InputDay();
	cout << "input day module not found" << endl;

	cout << "Enter Quantity On Hand:";
	cin >> BK.QuantityOnHand;
	cin.ignore();

	cout << "Wholesale Cost:";
	cin >> BK.WholesaleCost;
	cin.ignore();

	cout << "RetailPrice:";
	cin >> BK.RetailPrice;
	cin.ignore();

	addBookToList(BK);
	composeHashTable();

	return BK;
}

void DatabaseModule::addBookToList(Book book2Add)
{
	listOfBooks.push_back(book2Add);
}

void DatabaseModule::composeHashTable() {
	Book bookToAnalyze;
	DBHashTable.clear();

	for (int i = 0; i < listOfBooks.size(); i++)
	{
		HashTable hashT;
		HashTable hashTISBN;
		hashT.hashTableSize = 0;
		bookToAnalyze = listOfBooks[i];
		cout << "Processing: " << bookToAnalyze.Title << endl;
		//Title
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
		//ISBN
		string ISBN = bookToAnalyze.ISBN;
		hash = 0;
		for (int k = 0; k < ISBN.length(); k++)
		{
			int adjustChar = getAdjustedChar(ISBN.at(k));
			hash += adjustChar;
			cout << "\tChar #" << k << ", adusted: " << adjustChar << ", hash: " << hash << endl;
			hashTISBN.hashList.push_back(hash);
			hashTISBN.hashTableSize++;
		}
		DBHashTableISBN.push_back(hashTISBN);
	}
}

int DatabaseModule::getAdjustedChar(char passedChar) {
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

	case('1') :
		return 1;
	case('2') :
		return 2;
	case('3') :
		return 3;
	case('4') :
		return 4;
	case('5') :
		return 5;
	case('6') :
		return 6;
	case('7') :
		return 7;
	case('8') :
		return 8;
	case('9') :
		return 9;
	case('0') :
		return 10;


	case('-') :
		return 0;

	case (' ') :
		return 0;

	default:
		return 0;
	}
}

void DatabaseModule::searchByTitleWithString(string searchQuery)
{
	vector <int> deltaList;
	HashTable searchHashT = composeHashForCompare(searchQuery);
	for (int i = 0; i < DBHashTable.size(); i++)
	{
		HashTable hashT = DBHashTable[i];
		if (searchHashT.hashTableSize > hashT.hashTableSize)
		{
			continue;
		}
		string stringBase = listOfBooks[i].Title;
		int deltaSum = 0, charMatcher = 0, charMatcherBase = 0, charMatcherCompare = 0;
		for (int k = 0; (k < searchHashT.hashTableSize) && (k < hashT.hashTableSize); k++)
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
		deltaList.push_back(deltaSum);// *charMatcher);
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

void DatabaseModule::searchByISBNWithString(string searchQuery)
{
	vector <int> deltaList;
	HashTable searchHashT = composeHashForCompare(searchQuery);
	for (int i = 0; i < DBHashTable.size(); i++)
	{
		HashTable hashT = DBHashTableISBN[i];
		if (searchHashT.hashTableSize > hashT.hashTableSize)
		{
			continue;
		}
		string stringBase = listOfBooks[i].ISBN;
		int deltaSum = 0, charMatcher = 0, charMatcherBase = 0, charMatcherCompare = 0;
		for (int k = 0; (k < searchHashT.hashTableSize) && (k < hashT.hashTableSize); k++)
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
		deltaList.push_back(deltaSum);// *charMatcher);
	}

	vector <int> deltaCopy;
	vector <string> listSortForSearch;
	for (int i = 0; i < deltaList.size(); i++)
	{
		int base = deltaList[i];
		string baseTitle = listOfBooks[i].ISBN;
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

HashTable DatabaseModule::composeHashForCompare(string stringToHash)
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

void DatabaseModule::deleteBook()
{
	Book BK = SearchForBook(); //find book
	deleteBookUsingISBN(BK.ISBN); //delete book
	composeHashTable();
}

void DatabaseModule::deleteBookUsingISBN(string ISBN)
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

void DatabaseModule::DisplayBook(Book BK)
{
	cout << "ISBN:" << BK.ISBN << endl;
	cout << "Title:" << BK.Title << endl;
	cout << "Author:" << BK.Author << endl;
	cout << "Publisher:" << BK.Publisher << endl;
	cout << "Date Added:"; BK.DateAdded.PrintDate();//add ostream for date
	cout << "Quantity On Hand:" << BK.QuantityOnHand << endl;
	cout << "Wholesale Cost:" << BK.WholesaleCost << endl;
	cout << "Retail Price:" << BK.RetailPrice << endl;
}