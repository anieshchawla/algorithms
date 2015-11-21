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

//char alphabets[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

int min_mismatch(string P, string E){
  int min = P.length()-1;
  std::vector<int> difference;
  for(int i=0;i<P.length();i++){
    int dif = (((int)E[i]) - ((int)P[i]));
    if(dif<0) dif+=26;
    difference.push_back(dif);
  }
  std::sort(difference.begin(),difference.end());
  int prev_num = difference[0];
  int similar = 0,local_max = 0;
for(int i=1;i<P.length();i++){
    if(prev_num == difference[i]) local_max ++;
    else {
      local_max = 0;
    }
    if(similar<local_max){
      similar = local_max;
    }
    prev_num = difference[i];

  }

  return min-similar;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string P;
        string E;
        cin >> P >> E;
        cout<<min_mismatch(P,E)<<endl;
    }
    return 0;
}
