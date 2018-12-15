#ifndef __SONG_H
#define __SONG_H
#include <string>

using namespace std;
class Song {
public:
Song(const string sName = "", const int sMins = 0,
const int sSecs = 0);
~Song();
Song(const Song &songToCopy);
int getMins();
int getSecs();
string getName();
void operator=(const Song &right);
private:
string name;
int mins;
int secs;
};
#endif
