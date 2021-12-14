#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  while (1) {
    from_client = server_handshake(&to_client);
    while (1) {
      char user_put[100];
      int r = read(from_client, user_put, 100);
      if (!r) {
        break;
      }
      user_put[strlen(user_put)-1] = '\0';
      strcat(user_put, "changed");

      write(to_client, user_put, 100);
    }
  }
}
