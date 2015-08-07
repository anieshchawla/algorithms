#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *x, int *y){
	int *temp = x;
	*x = *y;
	*y = *temp;
	cout<<"x "<<x<<" y "<<y<<endl;
}

int main() {
	int a = 10,b=20;
	cout<<"a= "<<a<<" b= "<<b<<endl;
	swap(&a,&b);
	int *temp = &a;
	cout<<"a= "<<*temp<<" b= "<<b<<endl;
	

	/*int a = 10,b=20;
	cout<<"a "<<a<<" b "<<b<<endl;
	//swap(&a,&b);
	cout<<"a swap "<<a<<" b swap "<<b<<endl;
	*/
	return 0;
}