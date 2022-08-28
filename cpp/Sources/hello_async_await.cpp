#include <chrono>
#include <future>
#include <iostream>
#include <thread>

// clang-format off
// std::async の挙動を実感するためのプログラムです
// std::launch::deferred は future が get() したタイミングで実行されます。
// std::launch::async は feature が生成されたと同時にスレッドが起動して並列に実行されます。
// clang-format on
int main() {
  std::future<void> f = std::async(std::launch::deferred, []() {
    const auto id = std::this_thread::get_id();
    std::cout << "Hello World Deferred: " << id << std::endl;
  });

  std::future<void> fAsync = std::async(std::launch::async, []() {
    const auto id = std::this_thread::get_id();
    std::cout << "Hello World Async: " << id << std::endl;
  });

  std::cout << "Start from " << std::this_thread::get_id() << std::endl;
  std::cout << "Sleep 1[sec]..." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::cout << "Get Result" << std::endl;
  f.get();
  fAsync.get();
  std::cout << "End!" << std::endl;

  return 0;
}