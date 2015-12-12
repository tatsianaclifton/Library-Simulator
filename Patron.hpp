/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Patron.hpp is the Patron class    *
 * specification file                             *
 **************************************************/
#ifndef PATRON_HPP
#define PATRON_HPP
#include <string>
#include <vector>
#include "LibraryItem.hpp"

using namespace std;

class Patron
{
    private:
        string idNum;
        string name;
        vector<LibraryItem*> checkedOutItems;
        double fineAmount;
    public:
        Patron(string idn, string n);
        string getIdNum();
        string getName();
        vector<LibraryItem*> getCheckedOutItems();
        void addLibraryItem(LibraryItem* b);
        void removeLibraryItem(LibraryItem* b);
        double getFineAmount();
        void amendFine(double amount);
};
#endif 
