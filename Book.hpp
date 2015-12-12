/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Book.hpp is the Book class        *
 * specification file                             *
 **************************************************/
#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Book:public LibraryItem
{
    private:
        string author;
    public:
        static const int CHECK_OUT_LENGTH = 21;
        Book (string, string, string);
        virtual int getCheckOutLength();
        string getAuthor();
};
#endif 
