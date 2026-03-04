#include <iostream>
#include "BiList.h"
#include "subfunctions.h"

int main()
{

  size_t size = 0;
  BiList<int> *list = nullptr;
  int *arr = nullptr;
  std::cin >> size;

  try
  {
    arr = new int[size];
    for (size_t i = 0; i < size; ++i)
    {
      std::cin >> arr[size - i - 1];
      if (!std::cin)
      {
        std::cerr << "Unexpected input" << "\n";
        delete[] arr;
        return 3;
      }
    }
  }
  catch(const std::bad_alloc &e)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 2;
  }

  try
  {
    list = convert(arr, size);
  }
  catch(...)
  {
    std::cerr << "Error converting to list" << "\n";
    delete[] arr;
    return 1;
  }

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
  delete[] arr;

  return 0;
}
