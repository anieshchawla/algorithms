#include <stdio.h> 

void print_ptr(char*ch){
	printf("addr is %x\n",&(ch) );
	printf("value is %x\n",&(ch[1]) );
	printf("value is %s\n",ch);
}

int main() 
{
	char ch[] = {"abcdefghij"};
	printf("Hello World!!\n");
	print_ptr(ch); 
 return 0; 
} 