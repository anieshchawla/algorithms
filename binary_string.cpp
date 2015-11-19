#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N,k,t;
    string ss;
    cin>>N>>k>>t;
    cin>>ss;
    int array[N];
    for(int i=0;i<N;i++){
    	array[i]=ss[i]-'0';
    }
    int j = 0;
    while(t>0 and j<N-k ){
    	if(array[j]<array[j+k]){
    		array[j+k]=0;
    		array[j]=1;
    		t--;
    		if(t<=0) break;
    		int i=j-k;
    		while(i>=0){
    			if(array[i]<array[i+k]){
    				array[i]=1;
    				array[i+k]=0;
    				t--;
    				if(t<=0) break;
    			}
    			else{
    				break;
    			}
    			i-=k;
    		}
    	}
    	j++;

    }
    for(int i=0;i<N;i++){
    	cout<<array[i];
    }  
    cout<<endl;
    return 0;
}
