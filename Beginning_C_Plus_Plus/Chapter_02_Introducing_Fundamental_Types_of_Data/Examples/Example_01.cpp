/*
 * Example 1 Chapter 2
 * Writing values of variables to the screen
 */
#include <iostream>

int main()
{
    int apple_count {15};
    int orange_count {5};
    int total_fruit {apple_count + orange_count};

    std::cout << "The value of apple_count is " << apple_count << '\n'
        << "The value of orange_count is " << orange_count << '\n'
        << "The value of total_fruit is " << total_fruit << '\n';
}