/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Book.cpp is the Book class        *
 * function implementation file                   *
 **************************************************/
#include "Book.hpp"

using namespace std;

/**************************************************
 *                 Book::Book                     *
 * This function is a constructor with three      *
 * parameters that initializes the fields         *
 * of the Book object                             *
 **************************************************/
Book::Book(string idc, string t, string a):LibraryItem(idc, t)
{
    author = a;
}


/**************************************************
 *            Book::getCheckOutLength             *
 * This function returns the Book object's allowed*
 * check out length                               *
 **************************************************/
int Book::getCheckOutLength()
{
    return CHECK_OUT_LENGTH;
}


/**************************************************
 *                Book::getAuthor                 *
 * This function returns the Book's object author *
 **************************************************/
string Book::getAuthor()
{
    return author;
}
