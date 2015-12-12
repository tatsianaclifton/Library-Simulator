/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Album.hpp is the Album class      *
 * specification file                             *
 **************************************************/
#ifndef ALBUM_HPP
#define ALBUM_HPP
#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Album:public LibraryItem
{
    private:
        string artist;
    public:
        static const int CHECK_OUT_LENGTH = 14;
        Album (string, string, string);
        virtual int getCheckOutLength();
        string getArtist();
};
#endif 
