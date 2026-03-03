#include <iostream>
#include "BiList.h"

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

int main() {

  int arr[] = {5, 2, 8, 1, 9};
  BiList<int>* list = convert(arr, 5);

  std::cout << "Список: ";
  traverse(print<int>, list, list);
  std::cout << "\n";

  Counter<int> cnt;
  cnt = traverse(cnt, list, list);
  std::cout << "Кол-во элементов: " << cnt.count << "\n";

  std::cout << "\nadd(0) + add(7): ";
  list = add(list, 0);
  list = add(list, 7);
  traverse(print<int>, list, list);
  std::cout << "\n";

  std::cout << "insert после второго узла: ";
  insert(list->next, 3);
  traverse(print<int>, list, list);
  std::cout << "\n";

  std::cout << "cut: ";
  list = cut(list);
  traverse(print<int>, list, list);
  std::cout << "\n";

  std::cout << "erase после третьего узла: ";
  erase(list->next->next);
  traverse(print<int>, list, list);
  std::cout << "\n";

  list = clear(list, list);
}
