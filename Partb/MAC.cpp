#include "MAC.h"
#include <iostream>

using namespace std;


void MAC::calculateAvgMusicAlbumLength(int& minutes, int& seconds)
{

        minutes = 0;
        seconds = 0;
        if(noOfMusicAlbums==0)return;
    else

        for(int i=0, tmpmins=0, tmpsecs=0; i<noOfMusicAlbums; i++){
            this->musicAlbums[i].calculateMusicAlbumLength(tmpmins,tmpsecs);
            minutes += tmpmins;
            seconds += tmpsecs;
        }
        int temp = seconds + 60*minutes;
        temp=temp/noOfMusicAlbums;
    minutes = temp/60;
    seconds = temp%60;
}


bool MAC::removeSongs(const string maArtist, const string maTitle)
{
    if(!(this->noOfMusicAlbums))
        return false;
    bool flag = false;

    for(int i=0; i<noOfMusicAlbums; i++) {
        if (musicAlbums[i].getMusicAlbumTitle() == maTitle && musicAlbums[i].getMusicAlbumArtist() == maArtist) {
            flag = true;
            if (musicAlbums[i].getNumberOfSongs() == 0) {
                return false;
            }
            musicAlbums[i].clearSongs();
            return true;
        }
    }
    return false;

}


bool MAC::addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs)
{

    for(int i=0;i<noOfMusicAlbums;i++){
        if(musicAlbums[i].getMusicAlbumArtist() == maArtist && musicAlbums[i].getMusicAlbumTitle()==maTitle){

                return musicAlbums[i].addSong(sName, sMins, sSecs);



        }
    }
    return false;
}


int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums) {
    allMusicAlbums = new MusicAlbum[noOfMusicAlbums];
    for (int i = 0; i < noOfMusicAlbums; i++) {
        allMusicAlbums[i] = musicAlbums[i];
    }
    return noOfMusicAlbums;
}


bool MAC::removeMusicAlbum(const string maArtist, const string maTitle)
{
    if(!(this->noOfMusicAlbums))
        return false;
    MusicAlbum *tmp = new MusicAlbum[noOfMusicAlbums-1] ;
    bool flag = false;

    for(int i=0, k=0; i<noOfMusicAlbums; i++){
        if(musicAlbums[i].getMusicAlbumTitle() == maTitle &&  musicAlbums[i].getMusicAlbumArtist() == maArtist){
            flag = true;
            continue;
        }

        if(k==noOfMusicAlbums-1){
            break;
        }
        tmp[k] = musicAlbums[i];
        k++;

    }
    if(!flag){
        delete[] tmp;
        return false;
    }
    delete[] musicAlbums;
    musicAlbums = tmp;
    noOfMusicAlbums--;
    return flag;
}


bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
    int j = this->noOfMusicAlbums;
    noOfMusicAlbums++;
    MusicAlbum *tmp = new MusicAlbum[this->noOfMusicAlbums];
    int i;
    for(i=0;i<j;i++){
        if(tmp[i].getMusicAlbumArtist() == maArtist && tmp[i].getMusicAlbumTitle()==maTitle){
            delete[] tmp;
            return false;
        }

        tmp[i] = this->musicAlbums[i];
    }
    MusicAlbum tmp2(maArtist,maTitle,maYear);
    tmp[j] = tmp2;
    delete[] this->musicAlbums;
    this ->musicAlbums = tmp;
    return true;
}


void MAC::operator=(const MAC &right)
{
    this->noOfMusicAlbums = right.noOfMusicAlbums;
    if(right.noOfMusicAlbums==0){
        this->musicAlbums= NULL;
    }
    else{
        this->musicAlbums = new MusicAlbum[right.noOfMusicAlbums];
    }
    int i;
    for(i=0;i<right.noOfMusicAlbums;i++){
        this->musicAlbums[i]=right.musicAlbums[i];
    }
}


MAC :: MAC(const MAC &macToCopy)
{

    this->noOfMusicAlbums = macToCopy.noOfMusicAlbums;
    if(macToCopy.noOfMusicAlbums==0){
        this->musicAlbums = NULL;
    }
    else{
        this->musicAlbums = new MusicAlbum[macToCopy.noOfMusicAlbums];
    }
    int i;
    for(i=0;i<macToCopy.noOfMusicAlbums;i++){
        this->musicAlbums[i]=macToCopy.musicAlbums[i];
    }

}

MAC::~MAC()
{
    if(musicAlbums != NULL)
        delete[] musicAlbums;
}

MAC::MAC()
{
    this->noOfMusicAlbums = 0;
    this->musicAlbums = NULL;
}


