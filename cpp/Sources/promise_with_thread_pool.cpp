#include <boost/asio.hpp>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

void calc(std::promise<int> result) { result.set_value(7); }

int main() {
  constexpr auto threadCount = 2;
  boost::asio::thread_pool threadPool{threadCount};

  std::promise<double> promise;
  auto future = promise.get_future();

  const auto func = [&]() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    promise.set_value(10.0);
  };
  boost::asio::post(threadPool, func);

  std::future_status status = static_cast<std::future_status>(-1);
  while (status != std::future_status::ready) {
    std::cout << "Not Ready" << std::endl;
    status = future.wait_for(std::chrono::seconds(0));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  const auto result = future.get();
  std::cout << "Done!! : " << result << std::endl;

  threadPool.join();
  return EXIT_SUCCESS;
}