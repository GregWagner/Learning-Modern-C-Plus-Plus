#include <cstddef>
#include <type_traits>
#include <cstdio>

template<typename T>
concept bool Averageable() {
  return std::is_default_constructible<T>::value
    && requires (T a, T b) {
      { a += b } -> T;
      { a / size_t{1} } -> T;
    };
}

template<Averageable T>
T mean(const T* values, size_t length) {
  T result{};     // type T must be default constructible
  for (size_t i{}; i < length; ++i) {
    result += values[i];    // type T must support operator+=
  }
  return result / length;   // dividing T by a size_t yield a T
}

int main()
{
  const size_t length {4};
  const double nums_d[] {1.0, 2.0, 3.0, 4.0};
  const auto result1 = mean(nums_d, length);
  printf("double: %f\n", result1);

  const float nums_f[] {1.0f, 2.0f, 3.0f, 4.0f};
  const auto result2 = mean(nums_f, 4);
  printf("float: %f\n", result2);

  const int nums_c[] {1, 2, 3, 4};
  const auto result3 = mean(nums_c, 4);
  printf("size_t: %d\n", result3);
}
