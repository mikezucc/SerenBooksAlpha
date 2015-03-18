#include <iostream>
#include <string> 
#include <vector>
#include "CashierModuleFunctions.h"
#include "DatabaseModule.h"


using namespace std;

//int main()  
void CashierModule()
{
	int choice;
	string title, ISBN;
	vector<Book> ArrayBook(1);
	DatabaseModule DB;
	bool add = false;
	int NumBookArr = 1;
	
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
		ArrayBook[0] = DB.SearchForBook();
		system("CLS");

		do {
			choice = 0;
			cout << "Do you wish to add another book?" << endl
				<< "1. Yes" << endl
				<< "2. No" << endl;
			cin >> choice;
			system("CLS");
		} while (choice > 2 || choice < 1);

		if (choice == 2)
		{
			return;
		}
		else
		{
			ArrayBook.push_back(DB.SearchForBook());
			NumBookArr++;
		}

	} while (add == true);
	
	CategorySetup();

	for (int i = 0; i < NumBookArr; i++)
	{
		ListBook(ArrayBook[i]);

	}

	
	system("pause");

	
	//return 0;
}
