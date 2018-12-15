#include "Song.h"
#include <iostream>
#include <string>

using namespace std;


void Song::operator=(const Song& right)
{
    this -> mins = right.mins;
    this -> name = right.name;
    this -> secs = right.secs;
}

Song::Song(const Song& songToCopy)
{
    this -> mins = songToCopy.mins;
    this -> name = songToCopy.name;
    this -> secs = songToCopy.secs;
}

Song::~Song()
{
}

int Song :: getMins() {
    return mins;
}
string Song :: getName(){
    return name;
}

int Song :: getSecs(){
    return secs;
}

Song::Song(const string sName, const int sMins, const int sSecs)
{
    this -> mins = sMins;
    this -> name = sName;
    this -> secs = sSecs;
}




