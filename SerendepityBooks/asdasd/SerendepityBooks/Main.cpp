#include "CashierModuleFunctions.h"
#include "DatabaseModule.h"


using namespace std;

int main()
{

	bool FirstRound = true;
	int choice = -1;
	DatabaseModule DB;

	do
	{

		if (FirstRound == true)
		{
			cout << "\tWelcome to Serendipity books" << endl;
			cout << "What module do you wish to access: " << endl;
			cout << "1. Cashier" << endl;
			cout << "2. Database" << endl;
			cout << "3. Report" << endl;
			cout << "4. No module [Exit]" << endl;
			cout << "Your Choice: ";
			cin >> choice;
			system("CLS");
		}

		if (FirstRound == false)
		{
			cout << "\tInvalid Choice!" << endl;
			cout << "Try accesing another number: " << endl;
			cout << "1. Cashier" << endl;
			cout << "2. Database" << endl;
			cout << "3. Report" << endl;
			cout << "4. No module [Exit]" << endl;
			cout << "Your Choice: ";
			cin >> choice;
			system("CLS");

		}
		FirstRound = false;


	} while (choice > 4 || choice < 1);

	FirstRound = true;


	do
	{
		if (FirstRound == true)
		{
			bool returned = false;
			switch (choice)
			{

			case 1 :
				CashierModule();
				break;

			case 2:
				returned = DB.Loop();
				cout << (returned ? "yes" : "no") << endl;
				break;
			case 3 :
				cout << "ERROR! REPORT MODULE NOT LINKED YET!" << endl;
				break;
			case 4 :
				return 1;
			}
		}

		if (FirstRound == false)
		{
			do
			{
			cout << "\tWelcome back to the menu!" << endl;
			cout << "What module do you wish to access: " << endl;
			cout << "1. Cashier" << endl;
			cout << "2. Database" << endl;
			cout << "3. Report" << endl;
			cout << "4. No module [Exit]" << endl;
			cout << "Your Choice: ";
			cin >> choice;
			system("CLS");


			} while (choice > 4 || choice < 1);

			bool returned = false;
			switch (choice)
			{

			case 1:
				CashierModule();
				break;

			case 2:
				returned = DB.Loop();
				cout << (returned ? "yes" : "no") << endl;
				break;
			case 3:
				cout << "ERROR! REPORT MODULE NOT LINKED YET!" << endl;
				break;
			case 4:
				return 1;
			}


		}




	} while (choice != 4);






	return 0;
}
