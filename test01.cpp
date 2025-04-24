#include <iostream>
#include <vector>

std::vector<int> make_data(int start) {
  int a, b;
  std::vector<int> data;

  a = start;
  for (b = 1; b < 20; ++b) {
    if ((a + b) % 2 == 0) {
      data.push_back(a + b);
      std::cout << "a + b = " << (a + b) << std::endl;
    }
  }
  return data;
}

int main() {
  auto a = make_data(-2);
  return 0;
}