#include <iostream>

void print_out(auto& lst) {
  for (auto i : lst) {
    std::cout << i << '\n';
  }
}

int main() {
  int v[] = {0,1,2,3,4,5,6,7,8,9};
  for (auto& val : v) {
    ++val;
  }
  print_out(v);
  return 0;
}
