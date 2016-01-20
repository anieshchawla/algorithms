#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main()

{ FILE *pipe_w, *pipe_r;

  char line[80];

  pipe_w = popen("/bin/more -l", "w");
  pipe_r = popen("/usr/bin/rwho", "r");

  while (! feof(pipe_r))
    { if ( fgets(line, 80, pipe_r) != NULL ) /* pipe not closed */
        {  /* fprintf(stdout,"%s", line); */
          fprintf(pipe_w,"%s", line); 

        }
    }
 }
