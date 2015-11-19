#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	FILE *in;
	char buff[512];

	if(!(in = popen("ls -sailh | grep pipe", "r"))){
		return 1;
	}

	while(fgets(buff, sizeof(buff), in)!=NULL){
		cout << buff;
	}
	pclose(in);

	return 0;
}