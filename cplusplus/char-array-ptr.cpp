#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
void print_ptr(char *ch){
	cout<<"&ch "<<&ch<<endl;
	cout<<"&ch[0] "<<&(ch[0])<<endl;
	cout<<"&ch[1] "<<&(ch[1])<<endl;
	cout<<"ch++ "<<ch++<<endl;
	cout<<"sizeofptr "<<sizeof(ch)<<endl;
}

void print_array(char ch[]){
	cout<<"&ch array "<<&ch<<endl;
	cout<<"&ch[0] array "<<&(ch[0])<<endl;
	cout<<"&ch[1] array "<<&(ch[1])<<endl;
	cout<<"sizeofptr array "<<sizeof(ch)<<endl;
}


int main(){
	char ch[]={"abcdefghijklmnop"};
	cout<<"&ch main "<<&ch<<endl;
	cout<<"&ch[0] main "<<&(ch[0])<<endl;
	cout<<"&ch[1] main "<<&(ch[1])<<endl;
	cout<<"sizeofptr main "<<sizeof(ch)<<endl;

	cout<<"sizeof int ptr "<<sizeof(int*)<<endl;
	print_ptr(ch);
	print_array(ch);

}