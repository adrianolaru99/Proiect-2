#ifndef ITEM_H
#define ITEM_H
#include "Harta.h"
#include "Item.h"
#include<iostream>
using namespace std;
class Item : public Harta
{
    private:
       int nr,n,m;
       int **v;
    public:
    Item(int a,int b);
    void randomizare();
    Item();
    Item(Item &);
    int ** returnare (int &,int &);
     void dezalocare();

};

#endif // ITEM_H
