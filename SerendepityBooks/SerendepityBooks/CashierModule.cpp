#include <iostream>
#include <string> 
#include <vector>
#include "CashierHeaders.h"
#include "DatabaseModule.h"


using namespace std;

//int main()
void CashierModule(DatabaseModule dbMod)
{
	int choice;																			//Declare Variables
	string title, ISBN;																	//
	vector<Book> ArrayBook;																//
	vector<int> quantityList;															//		
	bool add = false;																	//
	int NumBookArr = 1;
	system("CLS");
	cout << "Welcome to the Cashier Module." << endl;									//Greet people when they first enter the Cashier
	do
	{
		cout << "Do you wish to buy some books?" << endl;								//Ask the customer if they want to buy a book or leave to the main
		cout << "1. Yes \t2. No: ";
		cin >> choice;
		cout << endl;

		if (choice > 2 || choice < 1)													//input validation
		{
			cout << "invalid Choise, enter a number between 1 - 2!" << endl;
		}

		if (choice == 2)																//if people wish to exit
		{
			return;
		}

	} while (choice > 2 || choice < 1);													//loop if people input invalid choice


	
	do
	{

	} while (true);
	{																					//get book from the user 
		system("CLS");																	//hand over to the databse
		Book resultBook = dbMod.SearchForBook();
		cout << "Book: " << resultBook.Title << endl;
		ArrayBook.push_back(resultBook);

		int purchaseNum = 0;
		cout << "There are " << resultBook.QuantityOnHand << " books on hand." << endl;
		cout << "Quantity: " << endl;													//Get the quantity avaivable
		cin >> purchaseNum;
		quantityList.push_back(purchaseNum);

		do {
			choice = 0;
			system("CLS");
			cout << "Do you wish to add another book?" << endl
				<< "1. Yes" << endl														//ask user if they want to purchase another book		
				<< "2. No" << endl;
			cin >> choice;
			system("CLS");
		} while (choice > 2 || choice < 1);

		if (choice == 2)
		{
			add = false;

		}
		else
		{
			Book illa = dbMod.SearchForBook();
			ArrayBook.push_back(illa);
			purchaseNum = 0;
			cout << "There are " << illa.QuantityOnHand << " books on hand." << endl;	// Get book from the DB moduel, Get amount of books to be purchased
			cout << "Quantity: " << endl;
			cin >> purchaseNum;
			quantityList.push_back(purchaseNum);
		}

	} while (add == true);
	
	CategorySetup();																	//set up category for receipt

	for (int i = 0; i < ArrayBook.size(); i++)
	{
		ListBook(ArrayBook[i], quantityList[i]);										//Display books	
	}

	cout << "Confirm purchase? (y/n) " << endl;
	char input;
	cin >> input;
	if (input == 'y')
	{
		double totalPrice = 0;
		for (int i = 0; i < ArrayBook.size(); i++)
		{
			totalPrice += dbMod.PurchaseBook(ArrayBook[i], quantityList[i]);			//Get the total price
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
