//
//  DataBaseMASTER.h
//  
//
//  Created by Michael Zuccarino on 2/26/15.
//
//

#ifndef ____DataBaseMASTER__
#define ____DataBaseMASTER__

#include <stdio.h>

using namespace std;

struct Book {
    
    public:
        String ISBN;
        String Title:
        String Author;
        Date dateAdded;
        unsigned int quantity;
        double wholesale;
        double retail;
    
};

class DataBaseMASTER
{
    private:
        vector listOfBooks;
    
    public:
        void addBookToList(Book);
}

void addBookToList(Book book2Add)
{
    this->listOfBooks.push_back(Book);
}

void deleteBookUsingISBN(String ISBN)
{
    bool foundBook = false;
    int idx = 0;
    vector newListOfBooks;
    while (idx < this->listOfBooks.length)
    {
        Book compareBook = this->listOfBooks[idx++];
        if (compareBook.ISBN == ISBN)
        {
            foundBook = true;
        }
        else
        {
            newListOfBooks.push_back(compareBook);
        }
    }
    this->listOfBooks = newListOfBooks;
}




#endif /* defined(____DataBaseMASTER__) */
