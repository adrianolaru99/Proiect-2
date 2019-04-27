#ifndef ROBOT1_H
#define ROBOT1_H

#include "Item.h"
#include "Harta.h"
#include "Robot1.h"
#include "Robot.h"
class Robot1 : public Robot
{
private:
    int n,m;
    int **v,**zz;
    bool ok;
public:
     void virtual dfs(int,int,int nr=1);
    Robot1(int a=0,int b=0);
    virtual ~Robot1();
     void virtual afisare();
     bool virtual isSafe(int,int,bool **);
      bool virtual isSafeItem(int,int,bool **);
     void virtual Prelucrare(int **,int **,int,int);
      void virtual afisaretape();
};


#endif // ROBOT1_H
