#include <iostream>
#include "Harta.h"
#include "Item.h"
#include "Robot.h"
#include "Robot1.h"
#include "Robot2.h"
#include "Robot3.h"
using namespace std;
int main()
{
    Robot *a;
    a=new Robot1(15,15);
    a->dfs(0,0);
}
