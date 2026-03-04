#ifndef SUBFUNCTIONS_H
#define SUBFUNCTIONS_H
#include <iostream>
template <class T>
void print(const T& val)
{
  std::cout << val << " ";
}

template <class T>
struct Counter
{
  size_t count = 0;
  void operator()(const T&)
  {
    ++count;
  }
};

#endif
