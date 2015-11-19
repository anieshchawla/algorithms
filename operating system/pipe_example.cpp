#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main(){
	int fdarray[2],anotherarray[2],pid;
	char buffer[21];
	pipe(fdarray);
	pipe(anotherarray);
	pid = fork();
	if(pid>0) {
		//close(2);
		//close(fdarray[0]);
		close(fdarray[0]);
		write(fdarray[1],"hellodears",10);
		read(anotherarray[0],buffer,sizeof(buffer));
		//read(fdarray[0],buffer,20);
		cout<<buffer<<endl;
	}
	else {
		//close(1); //In this we are closing the standard output and thus it
		//will not be able to print on the console
		//dup(fdarray[1]);
		//close(fdarray[1]);
		write(fdarray[1],"shitokdear",10);
		read(fdarray[0],buffer,20);
		write(anotherarray[1],"anieshisnotgreatwhichishwhyheis",31);
		cout<<buffer<<endl;
	}
}