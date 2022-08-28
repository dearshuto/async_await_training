#include <future>
#include <iostream>
#include <thread>

void calc(std::promise<int> result) { result.set_value(7); }

int main() {
  std::promise<int> promise;
  auto future = promise.get_future();

  std::thread t(calc, std::move(promise));

  const auto result = future.get();
  std::cout << result << std::endl;

  t.join();
  return 0;
}