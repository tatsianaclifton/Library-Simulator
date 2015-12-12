/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Library.cpp is the Library class  *
 * function implementation file                   *
 **************************************************/
#include <string>
#include <vector>
#include "Library.hpp"
#include "Patron.hpp"

using namespace std;

/**************************************************
 *              Library::Library                  *
 * This function is a constructor that initializes*
 * current date to zero                           *
 **************************************************/
Library::Library()
{
    currentDate = 0;
}


/**************************************************
 *          Library::addLibraryItem               *
 * This function takes as a parameter the         *
 * LibraryItem object and adds it to the list of  *
 * items in the library                           *
 **************************************************/
void Library::addLibraryItem(LibraryItem* itemOnHold)
{
    holdings.push_back(itemOnHold);
}


/**************************************************
 *             Library::addPatron                 *
 * This function takes as a parameter the Patron  *
 * object and adds it to the library members      *
 **************************************************/
void Library::addPatron(Patron* patronIn)
{
    members.push_back(patronIn);
}


/**************************************************
 *         Library::checkOutLibraryItem           *
 * This function takes as parameters the patron ID*
 * and the item ID and provides information if    *
 * this item is not available. Otherwise, it      *
 * updates the information about this item in     *
 * order to indicate that the item is checked out *
 **************************************************/
string Library::checkOutLibraryItem(string patronID, string ItemID)
{
    //Lopp through all items in the library
    for (int i = 0; i < holdings.size(); i++)
    {
        //Item is found
        if (holdings.at(i)->getIdCode() == ItemID)
        {
            //Loop through all paprons in the library
            for (int j = 0; j < members.size(); j++)
            {
                //Patron is found
                if (members.at(j)->getIdNum() == patronID)
                {
                    //Check if item is checked out
                    if (holdings.at(i)->getLocation() == CHECKED_OUT)
                        return "item already checked out";
                    //Check if item is on hold shelf for other patron
                    else if(holdings.at(i)->getLocation() == ON_HOLD_SHELF && holdings.at(i)->getRequestedBy() != members.at(j))
                        return "item on hold by other patron";
                    //Item is available
                    else
                    {
                        //Indicate who checked this item 
                        holdings.at(i)->setCheckedOutBy(members.at(j));
                        //Set the checked out date for this item
                        holdings.at(i)->setDateCheckedOut(currentDate);
                        //Change the location of this item for checked out  
                        holdings.at(i)->setLocation(CHECKED_OUT);

                        //Check if this patron has requested the item
                        if (holdings.at(i)->getRequestedBy() == members.at(j))
                            //Remove the patron from the request for this item 
                            holdings.at(i)->setRequestedBy(NULL);

                        //Add the item for the list of checked out item for this patron 
                        members.at(j)->addLibraryItem(holdings.at(i));
                        return "check out successful";
                    }
                }
            }
            return "patron not found";
        }
    }
    return "item not found";
}

/**************************************************
 *         Library::returnLibraryItem             *
 * This function takes as parameters the item ID. *
 * If this item was in the library was checked out*
 * and returned, it updates this item             *
 * information                                    *
 **************************************************/
string Library::returnLibraryItem(string ItemID)
{
    //Loop through the list of items in the library
    for (int i = 0; i < holdings.size(); i++)
    {
        //Item is found
        if (holdings.at(i)->getIdCode() == ItemID)
        {
            //Check if the item is already in the library
            if (holdings.at(i)->getLocation() != CHECKED_OUT)
                return "item already in library";

            //Find who checked out the item and remove from this patron's list
            //of checked out items 
            holdings.at(i)->getCheckedOutBy()->removeLibraryItem(holdings.at(i));

           //Check that nobody has requested this item
           if (holdings.at(i)->getRequestedBy() == NULL)
               //Set the location of the item to the shelf
               holdings.at(i)->setLocation(ON_SHELF);
           //Item was requested
           else
                //Set the location of the item to the hold shelf
                holdings.at(i)->setLocation(ON_HOLD_SHELF);

            //Set that item is not checked out by anybody
            holdings.at(i)->setCheckedOutBy(NULL);

            return "return successful";
        }

    }
    return "item not found";
}


/**************************************************
 *         Library::requestLibraryItem            *
 * This function takes as parameters the patron ID*
 * and the item ID and provides information if    *
 * this item is not available. Otherwise, it      *
 * updates the information about this item in     *
 * order to put this item on request              *
 **************************************************/
string Library::requestLibraryItem(string patronID, string ItemID)
{
    //Loop through the items in the library
    for (int i = 0; i < holdings.size(); i++)
    {
        //Item is found
        if (holdings.at(i)->getIdCode() == ItemID)
        {
            //Loop through the patrons of the library 
            for (int j = 0; j < members.size(); j++)
            {
                //Patron is found 
                if (members.at(j)->getIdNum() == patronID)
                {
                    //Check if someboby already has requested the item
                    if (holdings.at(i)->getLocation() == ON_HOLD_SHELF || holdings.at(i)->getLocation() == CHECKED_OUT && holdings.at(i)->getRequestedBy() != NULL)
                        return "item on hold by other patron";
                    //Noboby has requested the item
                    else
                        //Add the patron as the person who requested the item
                        holdings.at(i)->setRequestedBy(members.at(j));
                        //Check if the location of the item is shelf
                        if (holdings.at(i)->getLocation() == ON_SHELF)
                            //Put the item on the hold shelf
                            holdings.at(i)->setLocation(ON_HOLD_SHELF);
                    return "request successful";
                }
            }
            return "patron not found"; 
        }
    }
    return "item not found";
}


/**************************************************
 *               Library::payFine                 *
 * This function takes as parameters the patron ID*
 * and the payment amount. If the patron with this*
 * ID was found it reduces the amount of the fine *
 * for this payment amount                        *
 **************************************************/
string Library::payFine(string patronID, double payment)
{
    //Loop through the patrons of the library
    for (int j = 0; j < members.size(); j++)
    {
        //Patron is found
        if (members.at(j)->getIdNum() == patronID)
        {
            //Decrease the fine for that patron
            members.at(j)->amendFine(-payment);
            return "payment successful";
        }
    }
    return "patron not found";
}


/**************************************************
 *         Library::incrementCurrentDate          *
 * This function increments current date and      *
 * increases each Patron's fines by 10 cents for  *
 * each overdue LibraryItem they have checked out *
 **************************************************/
void Library::incrementCurrentDate()
{
    currentDate++;

    //Loop through the patrons of the library
    for (int j = 0; j < members.size(); j++)
    {
        //Loop through the checked out items of the patron
        for (int i = 0; i < members.at(j)->getCheckedOutItems().size(); i++)
        {
            //Compare the allowed length for checked out with the actaual length
            if (members.at(j)->getCheckedOutItems().at(i)->getCheckOutLength() < currentDate-members.at(j)->getCheckedOutItems().at(i)->getDateCheckedOut())
                //If length of actual checked out is more add 10 cents of fine for this item 
                members.at(j)->amendFine(0.10);
        }
    }
}


/**************************************************
 *               Library::getPatron               *
 * This function takes as a parameter the patron  *
 * ID and returns the Patron object's with this ID*
 **************************************************/
Patron* Library::getPatron(string patronID)
{
    for (int j = 0; j < members.size(); j++)
    {
        if (members.at(j)->getIdNum() == patronID)
            return members.at(j);
    }
    return NULL;
}


/**************************************************
 *             Library::getLibraryItem            *
 * This function takes as a parameter the library *
 * item ID and returns the LibraryItem object's   *
 * with this ID                                   *
 **************************************************/
LibraryItem* Library::getLibraryItem(string ItemID)
{
    for (int i = 0; i < holdings.size(); i++)
    {
        if (holdings.at(i)->getIdCode() == ItemID)
            return holdings.at(i);
    }
    return NULL;
}


