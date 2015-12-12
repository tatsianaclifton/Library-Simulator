/**************************************************
 * Author: Tatsiana Clifton                       *
 * Date: 6/2/2015                                 *
 * Description: Movie.hpp is the Movie class      *
 * specification file                             *
 **************************************************/
#ifndef MOVIE_HPP
#define MOVIE_HPP
#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Movie:public LibraryItem
{
    private:
        string director;
    public:
        static const int CHECK_OUT_LENGTH = 7;
        Movie (string, string, string);
        virtual int getCheckOutLength();
        string getDirector();
};
#endif 
