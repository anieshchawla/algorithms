#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test;
    cin>>test;
    while(test){
    test--;
    lli no_of_days;
    cin>>no_of_days;
    lli stock_price[no_of_days];
    for(int i=0;i<no_of_days;i++){
    	lli input;
    	cin>>input;
    	stock_price[i]=input;
    }
    lli stock_value=0,local_max=stock_price[no_of_days-1];
    for(lli j=no_of_days-1;j>=0;j--){
    	if(stock_price[j]>local_max) local_max = stock_price[j];
    	else{
    		stock_value+=(local_max - stock_price[j]);
    	}

    }
    cout<<stock_value<<endl;
    }
    return 0;
}