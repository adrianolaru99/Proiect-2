#ifndef ROBOT_H
#define ROBOT_H
#include "Item.h"
#include "Harta.h"
#include "Robot.h"
class Robot : public Item
{
private:
    int n,m;
    int **v,**zz;
    bool ok;
public:
     void virtual dfs(int,int,int nr=1);
    Robot(int a=0,int b=0);
    virtual ~Robot();
     void virtual afisare();
     bool virtual isSafe(int,int,bool **);
      bool virtual isSafeItem(int,int,bool **);
     void virtual Prelucrare(int **,int **,int,int);
      void virtual afisaretape();
};

#endif // ROBOT_H
