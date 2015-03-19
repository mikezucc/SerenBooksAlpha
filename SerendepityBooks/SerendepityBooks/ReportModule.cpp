#define _CRT_SECURE_NO_WARNINGS

#include "ReportModule.h"

ReportModule::ReportModule(DatabaseModule* DB)
:DataMod(DB)
{
    ListOfBooks = DataMod->GetBookList();
}

ReportModule::~ReportModule()
{
    //dtor
}

void ReportModule::Loop()
{
    bool Done = false;
    while(!Done)
    {
        cout << "1. Inventory Listing\n2. Inventory Wholesale Value\n3. Inventory Retail Value\n4. Listing by Quantity\n5. Listing by Cost\n6. Listing by Age\n7. Return to Main Menu\n";
        cout << "Enter your choice:";
        char choice;
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case '1':
                InventoryList();
                break;
            case '2':
                InventoryWholesaleValue();
                break;
            case '3':
                InventoryRetailValue();
                break;
            case '4':
                ListByQuantity();
                break;
            case '5':
                ListByCost();
                break;
            case '6':
                ListbyAge();
                break;
            case '7':
                Done = true;
                break;
            default:
                cout << "please chose a valid input";
        }
    }
}
void ReportModule::InventoryList()
{
    for(unsigned int i = 0; i < ListOfBooks.size(); ++i)
    {
        DataMod->DisplayBook(ListOfBooks[i]);
        cout << endl;
    }
}
void ReportModule::InventoryWholesaleValue()
{
    double Total;
    for(unsigned int i = 0; i < ListOfBooks.size(); ++i)
    {
        Total += ListOfBooks[i].WholesaleCost;
    }
    cout << "The Total Wholesale Value is: " << Total << endl;
}
void ReportModule::InventoryRetailValue()
{
    double Total;
    for(unsigned int i = 0; i < ListOfBooks.size(); ++i)
    {
        Total += ListOfBooks[i].RetailPrice;
    }
    cout << "The Total Retail Value is: " << Total << endl;
}
void ReportModule::ListByQuantity()
{
    vector<Book> Temp = ListOfBooks;
    for(unsigned int Wall = 0; Wall-1 < Temp.size(); ++Wall)
    {
        unsigned int MaxIndex = Wall;
        for(unsigned int Index = Wall + 1; Index < Temp.size(); ++Index)
        {
            if(Temp[MaxIndex].QuantityOnHand > Temp[Index].QuantityOnHand)
                MaxIndex = Index;
        }
        Book T = Temp[MaxIndex];
        Temp[MaxIndex] = Temp[Wall];
        Temp[Wall] = T;
    }

    for(unsigned int i = 0; i < Temp.size(); ++i)
    {
        cout << "Title: " << Temp[i].Title << "Quantity: " << Temp[i].QuantityOnHand << endl;
    }
}
void ReportModule::ListByCost()
{
    vector<Book> Temp = ListOfBooks;
    for(unsigned int Wall = 0; Wall-1 < Temp.size(); ++Wall)
    {
        unsigned int MaxIndex = Wall;
        for(unsigned int Index = Wall + 1; Index < Temp.size(); ++Index)
        {
            if(Temp[MaxIndex].RetailPrice > Temp[Index].RetailPrice)
                MaxIndex = Index;
        }
        Book T = Temp[MaxIndex];
        Temp[MaxIndex] = Temp[Wall];
        Temp[Wall] = T;
    }

    for(unsigned int i = 0; i < Temp.size(); ++i)
    {
        cout << "Title: " << Temp[i].Title << "Price: " << Temp[i].RetailPrice << endl;
    }
}
void ReportModule::ListbyAge()
{
    vector<Book> Temp = ListOfBooks;
    for(unsigned int Wall = 0; Wall-1 < Temp.size(); ++Wall)
    {
        unsigned int MaxIndex = Wall;
        for(unsigned int Index = Wall + 1; Index < Temp.size(); ++Index)
        {
            if(Temp[MaxIndex].DateAdded > Temp[Index].DateAdded)
                MaxIndex = Index;
        }
        Book T = Temp[MaxIndex];
        Temp[MaxIndex] = Temp[Wall];
        Temp[Wall] = T;
    }

    for(unsigned int i = 0; i < Temp.size(); ++i)
    {
        cout << "Title: " << Temp[i].Title << "DateAdded: "; Temp[i].DateAdded.PrintDate();
    }
}
