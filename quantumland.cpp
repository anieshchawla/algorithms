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
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
        }
        int count=0,result=0;
        for(int i=0;i<n;i++){
        	if(a[i]!=1){
        		while(i<n && a[i]!=1){
        			count++;
        			i++;
        		}
        		result+= (count/2);
        		count=0;
        	}
        	else{
        		count=0;
        	}

        }
        cout<<result<<endl;
    }
    return 0;
}
