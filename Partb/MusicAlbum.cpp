#include "MusicAlbum.h"
#include <string>
#include <iostream>

using namespace std;

MusicAlbum :: MusicAlbum(const MusicAlbum &maToCopy){
    this->artist = maToCopy.artist;
    this->title = maToCopy.title;
    this->noSongs = maToCopy.noSongs;
    this->year = maToCopy.year;
    if(!noSongs)
        this->songs = NULL;
    else
        for(int i = 0; i < noSongs; i++){
            songs[i] = maToCopy.songs[i];
        }
    songs = maToCopy.songs;
}
MusicAlbum ::MusicAlbum(const string maArtist, const string maTitle, const int maYear) {
    this->title = maTitle;
    this->artist = maArtist;
    this->year = maYear;
    noSongs=0;
    songs = NULL;

}


MusicAlbum :: ~MusicAlbum(){
    if(songs != NULL)
        delete[] songs;
}
void MusicAlbum ::clearSongs() {
    if(songs != NULL)
        delete[] songs;
}

bool MusicAlbum :: songExists(string sName){
    if(!this->noSongs)
        return false;
    for(int i = 0; i< noSongs; i++){
        if(songs[i].getName() == sName)
            return true;
    }
    return false;
}

bool MusicAlbum :: addSong(const string sName, const int sMins, const int sSecs) {
    Song *tmp = new Song[this->noSongs+1];
    int i;
    for(i=0;i<noSongs;i++){
        if(tmp[i].getName() == sName){
            delete[] tmp;
            return false;
        }

        tmp[i] = songs[i];
    }
    Song tmp2(sName,sMins,sSecs);
    tmp[noSongs] = tmp2;
    noSongs ++;
    delete[]songs;
    songs = tmp;
    return true;
}

int MusicAlbum ::getNumberOfSongs() { return noSongs;}

void MusicAlbum :: operator=(const MusicAlbum &maToCopy){
    this->artist = maToCopy.artist;
    this->title = maToCopy.title;
    this->noSongs = maToCopy.noSongs;
    this->year = maToCopy.year;
    if(!noSongs)
        this->songs = NULL;
    else
        songs = new Song[noSongs];
        for(int i = 0; i < noSongs; i++){
            songs[i] = maToCopy.songs[i];
        }
}

string MusicAlbum :: getMusicAlbumArtist(){
    return this->artist;
}

string MusicAlbum :: getMusicAlbumTitle(){
    return this -> title;
}

int MusicAlbum :: getMusicAlbumYear(){
    return this -> year;
}

void MusicAlbum :: calculateMusicAlbumLength(int &minutes, int &seconds){
    minutes = 0;
    seconds = 0;
    if (!noSongs) {
        return;
    }
    for(int i = 0; i < noSongs; i++){
        minutes += this->songs[i].getMins() + this->songs[i].getSecs()/60;
        seconds +=  this->songs[i].getSecs()%60;
    }
    minutes+=seconds/60;
    seconds =seconds%60;
}






