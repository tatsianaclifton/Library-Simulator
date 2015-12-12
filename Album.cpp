/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Album.cpp is the Album class      *
 * function implementation file                   *
 **************************************************/
#include "Album.hpp"

using namespace std;

/**************************************************
 *                 Album::Album                   *
 * This function is a constructor with three      *
 * parameters that initializes the fields         *
 * of the Album object                            *
 **************************************************/
Album::Album(string idc, string t, string a):LibraryItem(idc, t)
{
    artist = a;
}


/**************************************************
 *            Album::getCheckOutLength            *
 * This function returns the Album object's       *
 * allowed check out length                       *
 **************************************************/
int Album::getCheckOutLength()
{
    return CHECK_OUT_LENGTH;
}


/**************************************************
 *               Album::getArtist                 *
 * This function returns the Album object's artist*
 **************************************************/
string Album::getArtist()
{
    return artist;
}
