#include <stdlib.h>
#include <error.h>
#include <argp.h>

int main(int argc,char* argv[]){
	printf("no of arguments are %d\n",argc );
	while(argc)
	{
		/* code */
		printf("%s\n",argv[argc-1] );
		if(strcmp(argv[argc-1],"--transapi")==0) printf("successssss\n");
		argc--;
	}
}