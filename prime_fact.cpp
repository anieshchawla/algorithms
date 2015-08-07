#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ulli unsigned long long int 


using namespace std;


bool check(ulli a, ulli b, ulli max_no){
	if(b%2==0){
			if(a%2!=0){
				cout<<"No"<<endl;
				return false;	
			}
			while(b%2==0)b=b/2;
		}
	for(ulli i=3;i<=max_no;i+=2){
		if(b%i==0){
			if(a%i!=0){
				cout<<"No"<<endl;
				return false;
			}
			while(b%i==0){
				b=b/i;
			}
		}

	}
	if(b>2){
		if(a%b != 0){
			cout<<"No"<<endl;
			return false;
		}
	}

	return true;
}


int main(){
	int test;
	cin>>test;
	while(test>0){
		test--;
		bool breaked=false;
		ulli a,b,max_no;
		cin>>a>>b;
		max_no = sqrt(b);
		breaked = check(a,b,max_no);
		if(breaked) cout<<"Yes"<<endl;

	}
	return 0;
}
