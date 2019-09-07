#include <iostream>
#include <string>

#include "listsong.h"
#include "song.h"

using namespace std;

listSong<Song>* top50 = new listSong<Song>();

void agregar(){
    
    Song mySong;
    string data;
    
     cin.ignore();
    
    //Ceate option
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
    
    top50->insertData(top50->getLastPos(),mySong);
}

int main()
{
    top50->initialize();
    
    char option;
    do{
        
        //Menu
        cout<<"Radiodifusora"<<endl;
        top50->print();
        
        cout<<"Elije una opcion: "<<endl;
        cout<<"a)  Agragar cancion"<<endl;
        cout<<"o)  Ordenar"<<endl;
        cout<<"e)  Eliminar"<<endl;
        cout<<"S)  Salir"<<endl<<endl;
        
        cin>>option;
        
        switch(option){
            case 'a':{
               
                agregar();
                cout<<"Quiere agregar otra cancion? (s/n)"<<endl;
                cin>>option;
                
                
            } break;
            case 'o':{} break;
            case 'e':{} break;
            case 'S':{ return 0; } break;
        }

    }while(true);

}
