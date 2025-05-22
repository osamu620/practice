#include <iostream>

// STL: Standard Template Library
// Container formats: vector, array, map, deque, ...

#include <vector>
// vector: 可変長配列、末尾への要素の追加・削除が早い O(1)

// int pow2(int x) { return x * x; }

int main() {
  std::vector<int> data;

  for (int a = 0; a < 20; ++a) {
    // ラムダ式
    auto pow2 = [](int a) { return a * a; };
    if (a % 2 == 0) {
      data.push_back(pow2(a));
    }
  }

  auto i = 0;
  for (auto v : data) {
    std::cout << "data[" << i << "] = " << v << std::endl;
    i++;
  }
  return 0;
}