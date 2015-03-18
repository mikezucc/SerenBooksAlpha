#ifndef CATEGORY_SETUP_INCLUDE
#define CATEGORY_SETUP_INCLUDE
#include <iostream>
#include <iomanip>
#include <string>
#include "DatabaseModule.h"

using namespace std;


void CategorySetup();											//Set up Columns
void ListBook(Book);											//ListBooks
string InputBookInformationISBN();								//Get ISBN of book to purchase
string InputBookInformationTitle();								//Get Title of book to purchase
int TitleorISBN();												//Ask the user wheather he/she wants to add a book using ISBN or Title
void CashierModule();





#endif 
