#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;


int main(){
	int test;
	cin>>test;
	while(test){
		test--;
		int n;
		cin>>n;
		int x,y;
		int mul = n/4;
		switch(n%4){
			case 0:
			x = -n/2;
			y=x;
			break;
			case 1:
			x = n-2*mul;
			y = -2*mul;
			break;
			case 2:
			x= (n-1)-2*mul;
			y= n-2*mul;
			break;
			case 3:
			x= -2*(mul+1);
			y= (n-1)-2*mul;

		}
		cout<<x<<" "<<y<<endl;

	}
	return 0;
}