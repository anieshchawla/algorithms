#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dollars[7] = {1,2,5,10,20,50,100};

int number_of_ways(int value, int coin_number){
  if(value < 0 || coin_number < 0) return 0;
  if (value == 0 ) return 1;
  return number_of_ways(value,coin_number-1) + number_of_ways(value-dollars[coin_number],coin_number);
}

int main(){
  int N;
  cin>>N;
  cout<<number_of_ways(N,6)<<endl;
}
