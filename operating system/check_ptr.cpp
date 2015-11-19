#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>

using namespace std;

int main(){
	int array[10]={1,12,23,34,45,56,37,284,92,210};
	const int *check= array;
	int *const check_ptr = array;
	(*check_ptr)+=5	;
	*(check+=4);
	cout<<*check<<endl;
	cout<<*(check_ptr)<<endl;
}