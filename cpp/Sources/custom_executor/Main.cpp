#include <boost/asio.hpp>
#include <functional>
#include <future>
#include <iostream>
#include <queue>

// シングルスレッドでタスクを消化する Executor
class CustomExecutor {
public:
  void submit(std::function<void()> function) noexcept {
    m_TaskQueue.push(function);
  }

  void join() noexcept {
    while (!m_TaskQueue.empty()) {
      m_TaskQueue.front()();
      m_TaskQueue.pop();
    }
  }

private:
  std::queue<std::function<void()>> m_TaskQueue;
};

int main() {
  CustomExecutor executor;
  executor.submit([]() { std::cout << "Hello World" << std::endl; });

  executor.join();

  return EXIT_SUCCESS;
}
