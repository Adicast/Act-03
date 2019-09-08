#ifndef LISTSONG_H_INCLUDED
#define LISTSONG_H_INCLUDED

#include <iostream>
#include "listexception.h"
#include "song.h"

template<class T, int ARRAYSIZE = 50>
class listSong{
    
    private:
        T data[ARRAYSIZE];
        int last;
        bool isValidPos(const int&);

    public:

        void initialize();

        bool isEmpty();
        bool isFull();

        void insertData(const int&, const T&);
        void deleteData(const int&);

        int getFirstPos();
        int getLastPos();
        int getPrevPos(const int&);
        int getNextPos(const int&);

        int findData(const T&);

        int retrieve(const T&);

        void sortData();

        void print();

        void deleteAll();


};

///Implementacion

using namespace std;

template<class T, int ARRAYSIZE>
bool listSong<T, ARRAYSIZE>::isValidPos(const int&p)
{
    return p>=0 and p<=last;
}

template<class T, int ARRAYSIZE>
void listSong<T, ARRAYSIZE>::initialize()
{
    last=-1;
}

template<class T, int ARRAYSIZE>
bool listSong<T, ARRAYSIZE>::isEmpty()
{
    return last==-1;
}

template<class T, int ARRAYSIZE>
bool listSong<T, ARRAYSIZE>::isFull()
{
    return last==ARRAYSIZE-1;
}

template<class T, int ARRAYSIZE>
void listSong<T, ARRAYSIZE>::insertData(const int&p, const T&e)
{
    if(isFull())
    {
        throw ListException("Desbordamiento de datos, insertData");
    } else if (p!=-1 and !isValidPos(p)){
        throw ListException("Posicion invalida, insertData");
    }
    
     int i(last);
    
     while(i>p){
         
         data[i+1]=data[i];
         i--;
     }
     data[p+1]=e;
     last++;
}

template<class T, int ARRAYSIZE>
void listSong<T, ARRAYSIZE>::deleteData(const int&p)
{
    /*if(!isValidPos(p))
    {
        throw ListException("Posicion Invalida, deleteData");
    }*/
    
    for(int i = 0; i < last; i++) {
        cout<<"ranking: "<<data[i].getRanking()<<endl;
    }
    
    /*for(int i(0);i<=49;i++){
        if(data[i].getRanking() == p){
            int i(p);
            while(i<last)
            {
                data[i]=data[i+1];
                i++;
            }
            last--;
        }
        
    }*/
}

template<class T, int ARRAYSIZE>
int listSong<T, ARRAYSIZE>::getFirstPos()
{
    if (isEmpty())
    {
        return -1;
    }
    return 0;
}

template<class T, int ARRAYSIZE>
int listSong<T, ARRAYSIZE>::getLastPos()
{
    return last;
}

template<class T, int ARRAYSIZE>
int listSong<T, ARRAYSIZE>::getPrevPos(const int&p)
{
    if(p==getFirstPos() or !isValidPos(p))
    {
        return -1;
    }
    return p-1;
}

template<class T, int ARRAYSIZE>
int listSong<T, ARRAYSIZE>::getNextPos(const int&p)
{
    if (p==getLastPos() or !isValidPos(p))
    {
        return -1;
    }
    return p+1;
}

template<class T, int ARRAYSIZE>
int listSong<T, ARRAYSIZE>::findData(const T&p)
{
    
}

template<class T, int ARRAYSIZE>
int listSong<T, ARRAYSIZE>::retrieve(const T&p)
{
    if (!isValidPos(p))
    {
        throw ListException("Posicion Invalida, retrieveData");
    }
    return data[p];
}

template<class T, int ARRAYSIZE>
void listSong<T, ARRAYSIZE>::sortData()
{
    if(isEmpty()){
        cout<<"Lista vacia - ingresa canciones para luego ordenarlas"<<endl<<endl;
        return;
    }
    
    T aux;
    
    for(int i = 0; i < last + 1 ; i++) {
        for(int j = 0; j < last ; j++){
            if(stoi(data[j].getRanking()) > stoi(data[j + 1].getRanking())) {
                aux = data[j + 1];
                data [j +1] = data[j];
                data[j] = aux;
            }
        }
    }
}

template<class T, int ARRAYSIZE>
void listSong<T, ARRAYSIZE>::print()
{
    
    if(isEmpty()){
        cout<<"\tLista vacia"<<endl<<endl;
        return;
    }
    
    int i(0);
    while(i<=last)
    {
        cout<<"\t"<<data[i].toString()<<endl;
        i++;
    }
   
}

template<class T, int ARRAYSIZE>
void listSong<T, ARRAYSIZE>::deleteAll()
{
    last=-1;
}



#endif // LISTSONG_H_INCLUDED
