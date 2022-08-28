// 非同期にデータを変換するプログラム

#include <future>
#include <iostream>

struct Src {
  int value;
};
struct Dst {
  int value;
};

std::future<Dst> func(const Src &src) {
  auto future = std::async(std::launch::deferred, [&]() {
    const auto value = src.value;
    auto dst = Dst{};
    dst.value = value + 10;
    return dst;
  });
  return future;
}

int main() {
  Src src = {};
  src.value = 10;
  auto future = func(src);
  const auto dst = future.get();
  std::cout << dst.value << std::endl;

  return EXIT_SUCCESS;
}