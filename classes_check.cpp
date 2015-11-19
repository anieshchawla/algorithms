#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>

using namespace std;

class Fruit{
public: virtual void peel(){cout<<"this is the base class"<<endl;}
private: int weight, calories_per_oz;
};

class Apple: public Fruit{
public: void peel(){cout<<"this is apple peeling process"<<endl;}
};

int main(){
  Fruit banana;
  banana.peel();
  Fruit *apl_ptr;
  apl_ptr = new Apple;
  apl_ptr->peel();
  return 0;
}
