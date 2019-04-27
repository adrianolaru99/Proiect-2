#include "Item.h"
#include "Harta.h"
#include <cstdlib>
#include <ctime>
using namespace std;
// generarea aleatoare a item-urilor ( Acestea ofera posibilitatea de a accesa obstacolelor vecine)
// constructor cu parametri
Item::Item(int a,int b)
{
    srand (time(0));
    nr=rand()%15+1;
    n=a;
    m=b;
    v=new int *[n];
    for(int i=0; i<n; i++)
        v[i]=new int [m];
}
// constructor fara parametri
Item :: Item()
{
    n=0;
    m=0;
}
//constructor de copiere
Item :: Item(Item &z)
{
    v=new int *[z.n];
    for(int i=0; i<z.m; i++)
        v[i]=new int[z.m];
    n=z.n;
    m=z.m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            v[i][j]=z.v[i][j];
}
//Punerea aleatoare a item-urilor
void  Item :: randomizare()
{
    Harta z(n,m);
    int a,b;
    v=z.returnare(a,b);
    for(int i=0; i<nr; i++)
    {
        int x=rand()%n;
        int y=rand()%m;
        if(v[x][y]!=-2)
        v[x][y]=-3;
    }
    v[0][0]=0;
}
// returnare spre alta functie
int ** Item ::  returnare(int &a,int &b)
{
    a=n;
    b=m;
    return v;
}
// dezalocare de morie
void Item:: dezalocare()
{
    for(int i=0; i<n; i++)
        delete v[i];
    delete v;
    n=0;
    m=0;
}
