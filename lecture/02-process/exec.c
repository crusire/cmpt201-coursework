#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  printf("Hello World!\n");
  pid_t pid = fork(); // split into two functions

  char *args[] = {"/bin/ls", "-a", NULL};

  if (pid == 0) { // as the child...
    printf("Hello I am the child!\n");
    execl("/bin/ls", "/bin/ls", "-a", "-l", "-h", NULL);
  } else {
    printf("Hello I am the parent!\n");
    execv("/bin/ls", args);
  }
  printf("%d\n", getpid());
}
