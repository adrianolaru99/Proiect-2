#include "Harta.h"
#include <cstdlib>
#include <ctime>
using namespace std;
   //Constructor fara paramentri
   Harta :: Harta()
    {
       n=0;
       m=0;
    }
    //Constructor cu parametri
   Harta :: Harta(int m,int n)
    {
        this->n=n;
        this->m=m;
        v=new int *[n];
        for(int i=0;i<n;i++)
          v[i]=new int [m];
        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
               v[i][j]=0;
        int z;
        srand (time(0));
        z= rand() %15 +1;
        int x,y;
        for(int i=0;i<z;i++)
        {
            x= rand()%n;
            y=rand()%m;
            v[x][y]=-1;

        }
        x=rand()%(n-1)+1;
        y=rand()%(m-1)+1;
        v[x][y]=-2;
        v[0][0]=0;
    }
    //functie pt dezalocare a memoriei
    void Harta:: dezalocare()
    {
        for(int i=0;i<n;i++)
           delete v[i];
        delete v;
        n=0;
        m=0;
    }
    //supraincarcare operator =
    Harta Harta :: operator =(const Harta &a)
    {
        m=a.m;
        n=a.n;
        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
               v[i][j]=a.v[i][j];
        return *this;
    }
    //constructor de copiere
    Harta :: Harta(Harta &z)
    {
         v=new int *[z.n];
         for(int i=0;i<z.m;i++)
             v[i]=new int[z.m];
         n=z.n;
         m=z.m;
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                v[i][j]=z.v[i][j];
    }
    // supraincarcare citire
    istream & operator >>(istream &in, Harta &b)
    {
       for(int i=0;i<b.n;i++)
           for(int j=0;j<b.m;j++)
              in>>b.v[i][j];
        return in;
    }
    //supraincarcare afisare
    ostream &operator <<(ostream &out, Harta &b)
    {
        for(int i=0;i<b.n;i++)
        {
            for(int j=0;j<b.m;j++)
               out<<b.v[i][j]<<" ";
            out<<endl;
        }
        return out;
    }
    //functie de afisare a hartii
    void  Harta :: display()
    {
       cout<<n<<" "<<m<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
              cout<<v[i][j]<<" ";
            cout<<endl;
       }
     }
     // returnarea spre alta clasa
     int ** Harta :: returnare(int &a,int &b)
     {
         a=n;
         b=m;
         return v;
     }
