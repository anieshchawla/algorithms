#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#define fori(n) for(int i=0;i<n;i++)

using namespace std;

int main()
{

    int N,K;
    cin>>N>>K;
    int boys[N], girls[N];
    fori(N){
    	cin>>boys[i];
    	
    }
    fori(N){
    	cin>>girls[i];
    }
    int size = sizeof boys/sizeof *boys;
    qsort(boys,size,sizeof(*boys),[] (const void *args1,const void *args2){
    	int lhs = *static_cast<int const*> (args1);
    	int rhs = *static_cast<int const*> (args2);
    	if(lhs<rhs) return -1;
    	if (lhs>rhs) return 1;
    	return 0;
    });
    qsort(girls,size,sizeof(*girls),[] (const void *args1,const void *args2){
    	int lhs = *static_cast<int const*> (args1);
    	int rhs = *static_cast<int const*> (args2);
    	if(lhs<rhs) return -1;
    	if (lhs>rhs) return 1;
    	return 0;
    });
    int ans=0;
    int i = 0,j=0;
    while(i<N && j <N){
    	if(abs(boys[i]-girls[j]) <= K){
    		ans++;
    		i++;
    		j++;
    	}
    	else if(boys[i]<girls[j]){
    		i++;
    	}
    	else j++;
    }
    cout<<ans<<endl;
    return 0;
}