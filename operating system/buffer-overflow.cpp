#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	unsigned short B=1979;
	char A[8]="";
	strcpy(A,"excessive");
	cout<<"A="<<A<<endl;
	cout<<"B="<<B<<endl;
	cout<<"Address of A= "<<&A<<endl;
	cout<<"Address of B= "<<&B<<endl;
	return 0;
}