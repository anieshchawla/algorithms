#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/stropts.h>
#include <sys/types.h>

int iterrations=0;  
 
void sigpoll()
{	
	 //signal(SIGPOLL, sigpoll);
		 // signal(SIGQUIT, quitproc);
		 // printf("ctrl-c disabled use ctrl-\\ to quit\n");
		 // for(;;); /* infinite loop */
	char c = getchar();
	printf("Got the char %c at iterrations \n",c,iterrations);
	if(c=='q' || c == 'Q'){
		system("stty sane");
		exit(0);
	}

}
 
int main()
{ 		 sigset(SIGPOLL, sigpoll); /* using sigset instead of signal so that we don't have to register for signal again  */
		 /* NOTE some versions of UNIX will reset signal to default
		 after each call. So for portability reset signal each time */
 		system("stty raw -echo");
 		ioctl(0,I_SETSIG,S_RDNORM); //this tell OS to send the interrupts as SIGPOLL
		// printf("you have pressed ctrl-c \n");
 		for(;;iterrations++);
}
 

