#ifndef BILIST_H
#define BILIST_H
#include <cstddef>
template < class T >
struct BiList
{
  T data;
  BiList<T> *next;
  BiList<T> *prev;
};

template < class T >
BiList<T> *create(const T &d);

template < class T >
BiList<T> *add(List<T> *h, const T &d);

template < class T >
BiList<T> *insert(List<T> *n, const T &d);

template < class T >
BiList<T> *cut(List<T> *h) noexcept;

template < class T >
BiList<T> *erase(List<T> *n) noexcept;

template < class T >
BiList<T> *clear(BiList<T> *b, BiList<T> *e) noexcept;

template< class T, class F >
F traverse(F f, BiList<T> *b, BiList<T> *e);

template< class T >
BiList<T> *convert(const T* arr, size_t size);
#endif
