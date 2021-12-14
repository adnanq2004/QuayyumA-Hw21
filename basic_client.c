#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while (1) {
    char user_put[100];
    printf("Enter input: ");
    fgets(user_put, 100, stdin);
    write(to_server, user_put, 100);

    int r = read(from_server, user_put, 100);
    if (!r) {
      break;
    }
    printf("Response: %s\n", user_put);
  }
}
