#include "song.h"

using namespace std;

string Song::getArtist()
{
    return artist;
}

string Song::getName()
{
    return name;
}

string Song::getRanking()
{
    return ranking;
}

string Song::toString()
{
    string cancion;

    cancion= ranking;
    cancion+= " - ";
    cancion+= name;
    cancion+= " by: ";
    cancion+= artist;

    return cancion;
}

void Song::setArtist(const std::string&a)
{
    artist=a;
}

void Song::setName(const std::string&n)
{
    name=n;
}

void Song::setRanking(const std::string&r)
{
    ranking=r;
}
