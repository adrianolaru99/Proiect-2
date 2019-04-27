#ifndef ROBOT2_H
#define ROBOT2_H


#include "Item.h"
#include "Harta.h"
#include "Robot2.h"
#include "Robot.h"
class Robot2 : public Robot
{
private:
    int n,m;
    int **v,**zz;
    bool ok;
public:
     void virtual dfs(int,int,int nr=1);
    Robot2(int a=0,int b=0);
    virtual ~Robot2();
     void virtual afisare();
     bool virtual isSafe(int,int,bool **);
      bool virtual isSafeItem(int,int,bool **);
     void virtual Prelucrare(int **,int **,int,int);
      void virtual afisaretape();
};


#endif // ROBOT2_H
