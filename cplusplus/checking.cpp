#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <iostream>
#include <unistd.h>

using namespace std;
/*void input_nos();
void print_nos();
*/
/*struct check_struct
{
	int a;
	int b;
	int c;
};*/
int main(){
	//input_nos();
	//print_nos();
	/*int a=50;
	int b=50;*/
/*	check_struct abc;
	abc.a=10;
	abc.b=20;
	int *p = &(abc.b);
	p++;*/
//	*p=100;
	int i=1;
	while(i){
		pid_t node = fork();
		if(node==0) break;
		printf("pid is %d\n", node);
	}
	//*p=100;
	//*p=20;
//	printf("a=%d b=%d c=%d\n",abc.a,abc.b,abc.c);
	//printf("value of p%d\n",*p);
	return 0;
}
/*void input_nos(){
	int i=9;
	int array[10];
	while(i>=0){
		array[i]=i;
		i--;
	}
}
void print_nos(){
	int i=9;
	int arry[10];
	while(i>=0){
		cout<<arry[i]<<endl;
		i--;
	}
}*/