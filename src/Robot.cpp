
#include "Robot.h"
#include "Item.h"
#include "Harta.h"
#include <stack>
#include <vector>
#include <fstream>
using namespace std;
ofstream out("date.out");
//constructor pentru creare labirint
Robot :: Robot(int a,int b)
{
    n=a;
    m=b;
    v=new int *[n];
    zz=new int *[n];
    for(int i=0; i<n; i++)
        v[i]=new int [m];
    for(int i=0; i<n; i++)
        zz[i]=new int [m];
    Item z(a,b);
    z.randomizare();
    v=z.returnare(n,m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            zz[i][j]=v[i][j];
    out<<"Labirintul este urmatorul!"<<endl;
    out<<endl;
    afisare();
    out<<endl;
}
// destructor
Robot ::~Robot()
{
   for(int i=0;i<n;i++)
      delete v[i];
   for(int i=0;i<n;i++)
      delete zz[i];
    delete v;
    delete zz;
}
//functie de afisare
void Robot::afisare()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            out<<v[i][j]<<" ";
        out<<endl;
    }
}
// functie care verifica daca se poate accesa punctul curent ,fiind pe o pozitie cu item (-3)
bool Robot :: isSafeItem(int x,int y,bool **visited)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return 0;
    if(visited[x][y]==1)
        return 0;
    if(v[x][y]==0 || v[x][y]==-2 || v[x][y]==-3 || v[x][y]==-1)
        return 1;
    return 0;
}
// functie care verifica daca se poate accesa punctul curent
bool Robot :: isSafe(int x,int y,bool **visited)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return 0;
    if(v[x][y]==0 || v[x][y]==-2 || v[x][y]==-3)
        return 1;
    if(visited[x][y]==1)
        return 0;
    return 0;
}
// functie dfs pentru observarea hartii si gasirea unui drum
// se memoreaza si  intr-un vector de tati pentru a se reface drumul
void Robot :: dfs(int x,int y,int nr)
{
    stack <pair <int,int> > stack;
    stack.push(make_pair(x,y));
    bool **visited;
    visited=new bool *[n];
    for(int i=0; i<n; i++)
        visited[i]=new bool [m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            visited[i][j]=0;
    int st[]= {-1,1,0,0};
    int dr[]= {0,0,1,-1};
    int **xa,**ya;
    xa=new int *[n];
    for(int i=0; i<n; i++)
        xa[i]=new int[m];
    ya=new int *[n];
    for(int i=0; i<n; i++)
        ya[i]=new int [m];
    xa[0][0]=ya[0][0]=0;
    while(stack.empty()==0)
    {
        int x1=stack.top().first;
        int y1=stack.top().second;
        stack.pop();
        if(v[x1][y1]==-2)
        {
            v[x1][y1]=nr;
            Prelucrare(xa,ya,x1,y1);
            return;
        }
        visited[x1][y1]=1;
        v[x1][y1]=nr;
        nr++;

        for(int i=0; i<4; i++)
        {
            if(v[x1][y1]==-3)
            {
                if(isSafeItem(x1+st[i],y1+dr[i],visited))
                {
                    stack.push(make_pair(x1+st[i],y1+dr[i]));
                    xa[x1+st[i]][y1+dr[i]]=x1;
                    ya[x1+st[i]][y1+dr[i]]=y1;
                }
            }
            else if(isSafe(x1+st[i],y1+dr[i],visited))
            {
                stack.push(make_pair(x1+st[i],y1+dr[i]));
                xa[x1+st[i]][y1+dr[i]]=x1;
                ya[x1+st[i]][y1+dr[i]]=y1;
            }
        }
    }
}
// construirea drumului , fie cel final, fie pe etape
void Robot :: Prelucrare(int **x1,int **y1,int x,int y)
{
    int nr=1,xs=x,ys=y;
    int **zzz;
    zzz=new int *[n];
    for(int i=0; i<n; i++)
        zzz[i]=new int [m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            zzz[i][j]=zz[i][j];
    while(x || y)
    {

        x=x1[x][y];
        y=y1[x][y];
        nr++;
    }
    x=xs;
    y=ys;
    while(x!=0 || y!=0)
    {
        zz[x][y]=nr;
        x=x1[x][y];
        y=y1[x][y];
        nr--;
    }
    zz[x][y]=nr;
    afisaretape();
    if(ok==0)
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                out<<zz[i][j]<<" ";
            out<<endl;
        }
    if(ok==1)
    {
        out<<endl;
        out<<endl;
        zzz[0][0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                out<<zzz[i][j]<<" ";
            out<<endl;
        }
        out<<endl;
        int x=0,y=0,nr=1;
        bool ok1=0;
        do
        {
            nr++;
            ok1=0;
            int x2=x-1,y2=y,x3=x+1,y3=y,x4=x,y4=y+1,x5=x,y5=y-1,x6=x+1,y6=y+1,x7=x+1,y7=y-1;
            if(x7>=0 && x7<n && y7>=0 && y7<m)
            {
                if(zz[x7][y7]==nr)
                {
                    x=x7;
                    y=y7;
                    ok1=1;
                }
            }
            if(x2>=0 && x2<n && y2>=0 && y2<m)
            {
                if(zz[x2][y2]==nr)
                {
                    x=x2;
                    y=y2;
                    ok1=1;
                }
            }
            if(x3>=0 && x3<n && y3>=0 && y3<m)
            {
                if(zz[x3][y3]==nr)
                {
                    x=x3;
                    y=y3;
                    ok1=1;
                }
            }
            if(x4>=0 && x4<n && y4>=0 && y4<m)
            {
                if(zz[x4][y4]==nr)
                {
                    x=x4;
                    y=y4;
                    ok1=1;
                }
            }
            if(x5>=0 && x5<n && y5>=0 && y5<m)
            {
                if(zz[x5][y5]==nr)
                {
                    x=x5;
                    y=y5;
                    ok1=1;
                }
            }
            if(x6>=0 && x6<n && y6>=0 && y6<m)
            {
                if(zz[x6][y6]==nr)
                {
                    x=x6;
                    y=y6;
                    ok1=1;
                }
            }
            if(ok1==1)
            {
                zzz[x][y]=nr;
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                        out<<zzz[i][j]<<" ";
                    out<<endl;
                }
                out<<endl;
            }

        }
        while(ok1==1);
    }
}
// intrebarea utilizatorului tipul de afisare dorita
void Robot :: afisaretape()
{
    bool z;
    cout<<"Doriti afisarea pe etape sau afisarea rezultatului final?"<<endl
        <<"R: (1 pentru afisarea pe etape , 0 pentru afisarea finala)";
    cin>>z;
    if(z==1)
        ok=1;
    else
        ok=0;
}
