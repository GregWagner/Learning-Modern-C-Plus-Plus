/*
 * Finding the maximum value contained in an array.
 * Listing 2-10 Page 43
 */
#include <iostream>

int main()
{
  unsigned long maximum {};
  unsigned long const values[] {10, 50, 20, 40, 0};

  for (size_t i {}; i < 5; ++i) {
    if (values[i] > maximum) {
      maximum = values[i];
    }
  }
  std::cout << "The maximum value is " << maximum << '\n';
}
