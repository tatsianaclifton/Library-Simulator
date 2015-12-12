/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Patron.cpp is the Patron class    *
 * function implementation file                   *
 **************************************************/
#include <string>
#include <vector>
#include "Patron.hpp"

using namespace std;

/**************************************************
 *                Patron::Patron                  *
 * This function is a constructor with two        *
 * parameters that initializes the fields         *
 * of the Patron                                  *
 **************************************************/
Patron::Patron(string idn, string n)
{
    idNum = idn;
    name = n;
}


/**************************************************
 *               Patron::getIdNum                 *
 * This function returns the Patron object's      *
 * id number                                      *
 **************************************************/
string Patron::getIdNum()
{
    return idNum;
}


/**************************************************
 *               Patron::getName                  *
 * This function returns the Patron object's      *
 * name                                           *
 **************************************************/
string Patron::getName()
{
    return name;
}


/**************************************************
 *         Patron::getCheckedOutItems             *
 * This function returns the Patron object's      *
 * checked out items                              *
 **************************************************/
vector<LibraryItem*> Patron::getCheckedOutItems()
{
    return checkedOutItems;
}


/**************************************************
 *          Patron::addLibraryItem                *
 * This function adds a new checked out library   *
 * to already existing                            *
 **************************************************/
void Patron::addLibraryItem(LibraryItem* b)
{
    checkedOutItems.push_back(b);
}


/**************************************************
 *          Patron::removeLibraryItem             *
 * This function removes a checked out before     *
 * library from the list of checked out items     *
 **************************************************/
void Patron::removeLibraryItem(LibraryItem* b)
{
    //Loop through the list of checked out items
    for (int i = 0; i < checkedOutItems.size(); i++)
    {
        if (checkedOutItems.at(i) == b)
        {
            checkedOutItems.erase(checkedOutItems.begin() + i);
        }
    }
}


/**************************************************
 *            Patron::getFineAmount               *
 * This function returns the Patron object's      *
 * fine amount                                    *
 **************************************************/
double Patron::getFineAmount()
{
    return fineAmount;
}


/**************************************************
 *            Patron::getFineAmount               *
 * This function takes a double as parameter and  *
 * increases or decreases the fine amount         *
 **************************************************/
void Patron::amendFine(double amount)
{
    fineAmount = fineAmount + amount;
}
