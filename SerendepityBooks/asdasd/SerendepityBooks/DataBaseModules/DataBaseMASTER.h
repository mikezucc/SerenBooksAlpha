//
//  DataBaseMASTER.h
//
//
//  Created by Michael Zuccarino on 2/26/15.
//
//

#ifndef ____DataBaseMASTER__
#define ____DataBaseMASTER__
#include <vector>
#include <string>
#include <stdio.h>
#include "Book.h"
using namespace std;

class DataBaseMASTER
{
    private:
        vector<Book> listOfBooks;
        void addBookToList(Book book2Add);
        void deleteBookUsingISBN(string ISBN);
};

#endif /* defined(____DataBaseMASTER__) */
