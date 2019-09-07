#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#include <string>

class Song{
    
    private:
        std::string artist;
        std::string name;
        std::string ranking;

    public:
        std::string getArtist();
        std::string getName();
        std::string getRanking();
        std::string toString();

        void setArtist(const std::string&);
        void setName(const std::string&);
        void setRanking(const std::string&);

};

#endif // SONG_H_INCLUDED
