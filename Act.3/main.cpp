#include <iostream>
#include <string>

#include "listsong.h"
#include "song.h"

using namespace std;

int main()
{
    listSong<Song>* top50 = new listSong<Song>();
    Song mySong;

    string data;
    char option;
    do{
        cout<<"Nombre de la cancion:"<<endl;
        getline(cin,data);
        mySong.setName(data);

        cout<<"Nombre del Artista:"<<endl;
        getline(cin,data);
        mySong.setArtist(data);

        cout<<"Numero de Ranking:"<<endl;
        getline(cin,data);
        mySong.setRanking(data);
        
        //TODO: delte this.
        cout<<"my song: "<<mySong.toString()<<endl;

        cout<<"Quiere agregar otra cancion? (s/n)"<<endl;
        cin>>option;
        cin.ignore();

        top50->insertData(top50->getLastPos(),mySong);

    }while(option== 's');

    cout<<endl;

    cout<<"Contenido de la lista:"<<endl;

    top50->print();

    cout<<endl;


}
