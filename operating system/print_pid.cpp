#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main ( )
{
  pid_t child_pid;
  child_pid =fork();
  if(child_pid != 0){
    printf ("The process ID is %d\n", (int) getpid ()) ;
    printf ("The child process ID is %d\n", (int) child_pid) ;
  }
  else{
    printf ("I am child with ID is %d\n", (int) getpid ()) ;

  }
    return 0 ;
}
