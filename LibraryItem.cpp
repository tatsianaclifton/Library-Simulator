/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: LibraryItem.cpp is the            *
 * LibraryItem class function                     *
 * implementation file                            *
 **************************************************/
#include <string>
#include "LibraryItem.hpp"

using namespace std;

/**************************************************
 *        LibraryItem::LibraryItem                *
 * This function is a constructor with two        *
 * parameters that initializes the fields         *
 * of the LibraryItem                             *
 **************************************************/
LibraryItem::LibraryItem(string idc, string t)
{
    idCode = idc;
    title = t;
    checkedOutBy = NULL;
    requestedBy = NULL;
    location = ON_SHELF;
}

/**************************************************
 *           LibraryItem::getIdCode               *
 * This function returns the LibraryItem object's *
 * id code                                        *
 **************************************************/
string LibraryItem::getIdCode()
{
   return idCode;
}


/**************************************************
 *           LibraryItem::getTitle                *
 * This function returns the LibraryItem object's *
 * title                                          *
 **************************************************/
string LibraryItem::getTitle()
{
   return title;
}


/**************************************************
 *           LibraryItem::setLocation             *
 * This function copies the argument passed into  *
 * the parameter to the private member variable   *
 * location                                       *
 **************************************************/
void LibraryItem::setLocation(Locale locationIn)
{
    location = locationIn;
}

/**************************************************
 *           LibraryItem::getLocation             *
 * This function returns the LibraryItem object's *
 * location                                       *
 **************************************************/
Locale LibraryItem::getLocation()
{
   return location;
}


/**************************************************
 *         LibraryItem::getCheckedOutBy           *
 * This function returns the LibraryItem object's *
 * pointer to the Patron who has it checked out   *
 **************************************************/
Patron* LibraryItem::getCheckedOutBy()
{
    return checkedOutBy;
}


/**************************************************
 *        LibraryItem::setCheckedOutBy            *
 * This function copies the argument passed into  *
 * the parameter to the private member variable   *
 * checkedOutBy that is pointer to the Patron who *
 * has checked out an item                        *
 **************************************************/
void LibraryItem::setCheckedOutBy(Patron* checkedOutByIn)
{
    checkedOutBy = checkedOutByIn;
}


/**************************************************
 *         LibraryItem::getRequestedBy            *
 * This function returns the LibraryItem object's *
 * pointer to the Patron who has it requested     *
 **************************************************/
Patron* LibraryItem::getRequestedBy()
{
    return requestedBy;
}


/**************************************************
 *        LibraryItem::setRequestedBy             *
 * This function copies the argument passed into  *
 * the parameter to the private member variable   *
 * requestedBy that is pointer to the Patron who  *
 * has requested an item                          *
 **************************************************/
void LibraryItem::setRequestedBy(Patron* requestedByIn)
{
    requestedBy = requestedByIn;
}


/**************************************************
 *         LibraryItem::getDateCheckedOut         *
 * This function returns the LibraryItem object's *
 * date when it was checked out                   *
 **************************************************/
int LibraryItem::getDateCheckedOut()
{
    return dateCheckedOut;
}


/**************************************************
 *        LibraryItem::setDateCheckedOut          *
 * This function copies the argument passed into  *
 * the parameter to the private member variable   *
 * that indicates the date when an item was       *
 * checked out                                    *
 **************************************************/
void LibraryItem::setDateCheckedOut(int dateCheckedOutIn)
{
    dateCheckedOut = dateCheckedOutIn;
}
