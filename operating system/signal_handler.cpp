#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;
void handler(int s){
  if(s==SIGSEGV){
    cout<<"we are screwed by "<<SIGSEGV<<endl;
    exit(0);
  }
}
int main(){
  int *p=NULL;
  signal(SIGSEGV,handler);
  *p=110;
  cout<<"we are not putting the value now "<<endl;
  return 0;
}
