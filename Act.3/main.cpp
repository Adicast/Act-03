#include <iostream>
#include <string>

#include "listsong.h"
#include "song.h"

using namespace std;

listSong<Song>* top50 = new listSong<Song>();

void mensajeListaLlena(){
    cout<<"-----------"<<endl;
    cout<<"Lista llena"<<endl;
    cout<<"-----------"<<endl;
}

void agregar(){
    
    Song mySong;
    string data;
    char option;
    
    do {
        cin.ignore();
        
        top50->print();
        
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
        
        //Se agraga la cancino a la lista.
        top50->insertData(top50->getLastPos(),mySong);
        
        //Si no está llena pregunta si quieres agragar mas.
        if(!top50->isFull()){
            cout<<"Quiere agregar otra cancion? (s/n)"<<endl;
            cin>>option;
        } else {
            mensajeListaLlena();
            option = 'c';// cualquier valor que no se a s
        }
        
    } while(option == 's');
 
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
               
                if(!top50->isFull()){
                    agregar();
                } else {
                    mensajeListaLlena();
                }
                
            } break;
            case 'o':{} break;
            case 'e':{} break;
            case 'S':{ return 0; } break;
        }

    }while(true);

}
