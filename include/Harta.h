#ifndef HARTA_H
#define HARTA_H
#include<iostream>
using namespace std;
class Harta
{
    private:
    int n,m;
    int **v;
    public:
    Harta();
    Harta(int ,int );
    Harta operator =(const Harta &);
    Harta(Harta &);
    friend istream & operator >>(istream &, Harta &);
    friend ostream &operator <<(ostream &, Harta &);
    void display();
    int ** returnare(int &,int &);
    void dezalocare();
};

#endif // HARTA_H
