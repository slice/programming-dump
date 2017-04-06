#include <iostream>
#include <vector>

struct dummy_object {
  int a;
  int b;
  int c;
};

int main() {
  std::vector<dummy_object*> exhausted_list;

  for (int i = 0; i < 100'000'000; i++) {
    if (i % 1'000'000 == 0) {
      std::cout << "stats: allocated progress: " << exhausted_list.size() << '\n';
    }

    auto* ptr = new dummy_object;
    exhausted_list.push_back(ptr);
  }

  std::cout << "stats: " << exhausted_list.size() << " elems\n";
  std::cout << "allocated memory!. . .\n";
  char a; std::cin >> a;

  for (dummy_object* ptr : exhausted_list) {
    delete ptr;
  }
  exhausted_list.clear();

  std::cout << "deallocated memory. . .\n";
  std::cin >> a;

  return 0;
}
