#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    long long int K,points=0;
    long long int N;
    cin >> K >> N;
    vector<long long int> R(K);
    for(long long int R_i = 0;R_i < K;R_i++){
       cin >> R[R_i];
       R[R_i]*=R[R_i];
    }
    vector< vector<long long int> > x(N,vector<long long int>(2));
    for(long long int x_i = 0;x_i < N;x_i++){
       for(long long int x_j = 0;x_j < 2;x_j++){
          cin >> x[x_i][x_j];
       }
    }
    for(long long int i = 0;i < N;i++){
      long long int distance = ((x[i][0])*(x[i][0]) + (x[i][1])*(x[i][1]));
       for(long long int j = K-1;j >= 0;j--){
         if(distance <= R[j]){
           points+=(j+1);
           break;
         }
       }
    }
    cout<<points<<endl;
    return 0;
}
