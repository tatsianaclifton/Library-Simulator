/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Movie.cpp is the Movie class      *
 * function implementation file                   *
 **************************************************/
#include "Movie.hpp"

using namespace std;

/**************************************************
 *                 Movie::Movie                   *
 * This function is a constructor with three      *
 * parameters that initializes the fields         *
 * of the Movie object                            *
 **************************************************/
Movie::Movie(string idc, string t, string a):LibraryItem(idc, t)
{
    director = a;
}


/**************************************************
 *            Movie::getCheckOutLength            *
 * This function returns the Movie object's       *
 * allowed check out length                       *
 **************************************************/
int Movie::getCheckOutLength()
{
    return CHECK_OUT_LENGTH;
}


/**************************************************
 *               Movie::getDirector               *
 * This function returns the Movie object's       *
 * director                                       *
 **************************************************/
string Movie::getDirector()
{
    return director;
}
