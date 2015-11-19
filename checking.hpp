#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <limits.h>
using namespace std;
void check(){
	cout<<"checking"<<endl;
}

struct node
{
	int i;
	char *ch;
};

void display(){
	static int j=10;
	j++;
	cout<<"J="<<j<<endl;
}


class checking_class{
public:
	checking_class();
	~checking_class();
	int mult(int a,int b){return a*b;}
	int mult_node(struct node check_node);

};
