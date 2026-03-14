#include <string>

#include "tomodoro.h"

int main(int argc, char* argv[]) {
  int total_minutes = DEFAULT_MINUTES;

  if (argc >= 2) {
    try {
      total_minutes = std::stoi(argv[1]);
    } catch (...) {
      printf("Input must be integer. Using default (%d minute(s)).\n",
             DEFAULT_MINUTES);
    }
  }

  tomodoro(total_minutes);
}
