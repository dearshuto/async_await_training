#include <boost/asio.hpp>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
  // 処理系がサポートしているスレッド数を取得方法。
  const auto count = std::thread::hardware_concurrency();

  // 少なくともひと組のタスクは同じスレッドで動くようなサンプルにしたいので、
  // 実際に起動するスレッド数は少なめに設定しておく
  constexpr auto actualThreadCount = 2;
  boost::asio::thread_pool threadPool{actualThreadCount};

  // 実行時に情報を知れるように出力
  std::cout << "Hardware Concurrency: " << count << std::endl;
  std::cout << "Actual              : " << actualThreadCount << std::endl;
  std::cout << std::endl;

  std::mutex mutex;
  const auto func = [&]() {
    const auto id = std::this_thread::get_id();
    for (auto index = 0; index < 4; ++index) {
      { // 出力がバグらないようにロックをとっておく
        std::lock_guard<std::mutex> lock{mutex};
        std::cout << id << ": " << index << std::endl;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  };

  // スレッドプールが 2 つでタスクが 3 つなので、
  // 1 組だけ同じスレッドで実行されるはず
  boost::asio::post(threadPool, func);
  boost::asio::post(threadPool, func);
  boost::asio::post(threadPool, func);

  threadPool.join();
  return 0;
}