#include <cstdio>
#include <string>
#include <thread>
#include <chrono>

constexpr int DEFAULT_MINUTES = 10;

int main(int argc, char* argv[]) {
  int total_minutes = DEFAULT_MINUTES;

  if (argc >= 2) {
    try {
      total_minutes = std::stoi(argv[1]);
    } catch (...) {
      printf("Input must be integer. Using default (10 minutes)\n");
    }
  }

  int total_seconds = total_minutes * 60;

  total_seconds = 3;
  while (total_seconds >= 0) {
    int minutes = total_seconds / 60;
    int seconds = total_seconds % 60;

    printf("\r%02d:%02d", minutes, seconds);
    fflush(stdout);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    --total_seconds;
  }

  printf("\n");

  std::system("say 'Time is up'");

  return 0;
}
