#ifndef REPORTMODULE_H
#define REPORTMODULE_H
#include "DatabaseModule.h"
#include <vector>
using namespace std;

class ReportModule
{
    public:
        ReportModule(DatabaseModule* );
        virtual ~ReportModule();
        void Loop();
        void InventoryList();
        void InventoryWholesaleValue();
        void InventoryRetailValue();
        void ListByQuantity();
        void ListByCost();
        void ListbyAge();
    private:
        DatabaseModule* DataMod;
        vector<Book> ListOfBooks;
};

#endif // REPORTMODULE_H
