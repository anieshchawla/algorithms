#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define FOR(n) for(int i=0;i<n;i++)
#define FOR_M(m,n) for(int j=m-1;j<n;j++)
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,Q;
    cin>>N>>Q;
    int array[N];
    FOR(N){
        int new_num;
    	cin>>new_num;
        if(i>0) array[i] = array[i-1]+new_num;
        else array[i] = new_num;
    }
    FOR(Q){
    	int L,R;
    	cin>>L>>R;
    	int sum;
        if (L==1) sum=array[R-1];
        else sum = array[R-1] - array[L-2];
    	if (sum%2==0) cout<<"Even"<<endl;
    	else cout<<"Odd"<<endl;
    }
    return 0;
}
