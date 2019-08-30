#include <iostream>
#include "tea/attribute.hpp"

void print_int(int val) {
  std::cout << "Set to " << val << std::endl;
}

int main()
{
  tea::Attribute<int> a;
  a.observe(&print_int);

  a = 2;
  a = 3;
  a = 4;

  return 0;
}
