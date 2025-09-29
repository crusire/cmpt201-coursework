#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

struct sigaction handler;

void siginthandler() {
  write(STDOUT:
}

int main() {
  
  handler.sa_handler = signal_handler;
  handler.sa_flags = 0;
  sigemptyset(&handler.sa_mask);

  pid_t pid = fork();
  
  if (pid) {
    
  }
  void (*signal_handler)(int);
  sigaction(SIGINT, handler, NULL);
}
