#include "BiList.h"

template < class T >
BiList<T> *create(const T &d)
{
  BiList<T> *h = new BiList<T>{d, nullptr, nullptr};
  h->next = h;
  h->prev = h;
  return h;
}

template < class T >
BiList<T> *add(BiList<T> *h, const T &d)
{
  BiList<T> *newh = new BiList<T>{d, h, h->prev};
  h->prev->next = newh;
  h->prev = newh;
  return newh;
}

template < class T >
BiList<T> *insert(BiList<T> *n, const T &d)
{
  BiList<T> *newNode = new BiList<T>{d, n->next, n};
  n->next->prev = newNode;
  n->next = newNode;
  return newNode;
}

template < class T >
BiList<T> *cut(BiList<T> *h) noexcept
{

}

template < class T >
BiList<T> *erase(BiList<T> *n) noexcept
{

}

template < class T >
BiList<T> *clear(BiList<T> *b, BiList<T> *e) noexcept
{

}

template< class T, class F >
F traverse(F f, BiList<T> *b, BiList<T> *e)
{

}

template< class T >
BiList<T> *convert(const T* arr, size_t size)
{

}
