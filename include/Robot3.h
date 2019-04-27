#ifndef ROBOT3_H
#define ROBOT3_H


#include "Item.h"
#include "Harta.h"
#include "Robot3.h"
#include "Robot.h"
class Robot3 : public Robot
{
private:
    int n,m;
    int **v,**zz;
    bool ok;
public:
     void virtual dfs(int,int,int nr=1);
    Robot3(int a=0,int b=0);
    virtual ~Robot3();
     void virtual afisare();
     bool virtual isSafe(int,int,bool **);
      bool virtual isSafeItem(int,int,bool **);
     void virtual Prelucrare(int **,int **,int,int);
      void virtual afisaretape();
};


#endif // ROBOT3_H
