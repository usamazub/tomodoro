#include "tomodoro.h"

#include <chrono>
#include <cstdio>
#include <thread>

void tomodoro(int total_minutes) {
  int total_seconds = total_minutes * 60;

  while (total_seconds) {
    int minutes = total_seconds / 60;
    int seconds = total_seconds % 60;

    printf("\r%02d:%02d", minutes, seconds);
    fflush(stdout);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    --total_seconds;
  }

  printf("\n");
  std::system("say 'Time\'s up'");

  return;
}
