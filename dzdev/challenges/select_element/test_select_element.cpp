#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "select_element.hpp"

// compare functions
int on_bits(int n);
bool bits_greater(int a, int b);
bool shortest(const std::string& a, const std::string& b);
bool longest(const std::string& a, const std::string& b);

int main(void) {
  // numbers
  {
    std::vector<int> vec{{10, 16, 1, 0, -1, 15}};
    std::cout << "min: " << *local::select_element(vec.begin(), vec.end(), std::less<int>{}) << "\n";
    std::cout << "max: " << *local::select_element(vec.begin(), vec.end(), std::greater<int>{}) << "\n";
    std::cout << "max 'on bits': " << *local::select_element(vec.begin(), vec.end(), bits_greater) << "\n";
  }

  // strings
  {
    std::vector<std::string> vec{{"short", "medium", "loooong"}};
    std::cout << "shortest: " << *local::select_element(vec.begin(), vec.end(), shortest) << "\n";
    std::cout << "longest: " << *local::select_element(vec.begin(), vec.end(), longest) << "\n";
  }
}

// count number of set bits
int on_bits(int n) {
  int counter = 0;
  unsigned x = static_cast<unsigned>(n);
  while (x > 0) {
    counter += (x & 1);
    x >>= 1;
  }
  return counter;
}

bool bits_greater(int a, int b) {
  return on_bits(a) > on_bits(b);
}

bool shortest(const std::string& a, const std::string& b) {
  return a.size() < b.size();
}

bool longest(const std::string& a, const std::string& b) {
  return a.size() > b.size();
}