#define _POSIX_C_SOURCE 200809L

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror("Wrong # of arguments.");
    exit(EXIT_FAILURE);
  }

  char *msg = argv[1];
  int fd = shm_open(msg, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  ftruncate(fd, sizeof(int));

  void *mem_map =
      mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  int *data = (int *)mem_map;

  printf("%d\n", *data);

  return 0;
}
