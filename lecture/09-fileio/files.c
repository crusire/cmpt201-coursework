#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
  int fd = open("tmp", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);

  char *msg = "Hello World!";
  write(fd, msg, strlen(msg));

  while (1) {
    sleep(30);
  }
}
