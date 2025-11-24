#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(void) {
  printf("CLIENT:\n");

  int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Socket creation fail!");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_un addr;
  addr.sun_family = AF_UNIX;
  snprintf(addr.sun_path, 108, "socket_fun");
  if (connect(socket_fd, (struct sockaddr *)&addr,
              sizeof(struct sockaddr_un)) == -1) {
    perror("Connect fail!");
    exit(EXIT_FAILURE);
  }

  char *msg = "Sockets aren't fun.\n";
  int bytes_written = write(socket_fd, msg, strlen(msg));

  close(socket_fd);

  return 0;
}
