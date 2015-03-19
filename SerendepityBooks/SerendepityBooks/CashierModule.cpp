#include <iostream>
#include <string> 
#include <vector>
#include "CashierHeaders.h"
#include "DatabaseModule.h"


using namespace std;

//int main()
void CashierModule(DatabaseModule dbMod)
{
	int choice;
	string title, ISBN;
	vector<Book> ArrayBook;
	vector<int> quantityList;
	bool add = false;
	int NumBookArr = 1;
	system("CLS");
	cout << "Welcome to the Cashier Module." << endl;
	do
	{
		cout << "Do you wish to buy some books?" << endl;
		cout << "1. Yes \t2. No: ";
		cin >> choice;
		cout << endl;

		if (choice > 2 || choice < 1)
		{
			cout << "invalid Choise, enter a number between 1 - 2!" << endl;
		}

		if (choice == 2)
		{
			return;
		}

	} while (choice > 2 || choice < 1);


	
	do
	{
		system("CLS");
		Book resultBook = dbMod.SearchForBook();
		cout << "Book: " << resultBook.Title << endl;
		ArrayBook.push_back(resultBook);

		int purchaseNum = 0;
		cout << "There are " << resultBook.QuantityOnHand << " books on hand." << endl;
		cout << "Quantity: " << endl;
		cin >> purchaseNum;
		quantityList.push_back(purchaseNum);

		do {
			choice = 0;
			system("CLS");
			cout << "Do you wish to add another book?" << endl
				<< "1. Yes" << endl
				<< "2. No" << endl;
			cin >> choice;
			system("CLS");
		} while (choice > 2 || choice < 1);

		if (choice == 2)
		{
			add = false;
			break;
		}
		else
		{
			Book illa = dbMod.SearchForBook();
			ArrayBook.push_back(illa);
			purchaseNum = 0;
			cout << "There are " << illa.QuantityOnHand << " books on hand." << endl;
			cout << "Quantity: " << endl;
			cin >> purchaseNum;
			quantityList.push_back(purchaseNum);
		}

	} while (add == true);
	
	CategorySetup();

	for (int i = 0; i < ArrayBook.size(); i++)
	{
		ListBook(ArrayBook[i], quantityList[i]);
	}

	cout << "Confirm purchase? (y/n) " << endl;
	char input;
	cin >> input;
	if (input == 'y')
	{
		double totalPrice = 0;
		for (int i = 0; i < ArrayBook.size(); i++)
		{
			totalPrice += dbMod.PurchaseBook(ArrayBook[i], quantityList[i]);
		}
		cout << "Your total charge was: $" << totalPrice << endl;
		cout << "Leaving Module..." << endl;
	}
	else
	{

	}

	
	system("pause");

	
	//return 0;
}
