#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int two_power(int n){
	if (n==0) return 1;
	else if (n==1) return 2;
	else {
		if (n%2==0){
			int m = two_power(n/2);
			return m*m;
		}
		else{
			return 2*two_power(n-1);
		}
	}
}
int find_power_two(int n){
	int ans=0;
	while(n>1){
		ans+=1;
		n/=2;
	}
	return ans;
}

int main(){
	int test;
	cin>>test;
	while(test){
		test--;
		int A,B;
		cin>>A>>B;
		int m,n;
		if (A==B){
			cout <<0<<endl;
		}
		else{

			m = find_power_two(A);
			n = find_power_two(B);
			int diff = A - two_power(m);
			int addition=0;
			if(diff!=0){
					addition = find_power_two(diff)+1;
			}
			
			cout<<abs(n-m+2*addition)<<endl;
			

		}
	}
}