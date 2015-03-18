#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <string>
#include "Date.h"

struct Book
{
    string ISBN;
    string Title;
    string Author;
    string Publisher;
    Date DateAdded;
    unsigned int QuantityOnHand;
    double WholesaleCost;
    double  RetailPrice;
};

#endif // BOOK_H_INCLUDED
