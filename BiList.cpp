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
  if (!h)
  {
    return create(d);
  }
  BiList<T> *newh = new BiList<T>{d, h, h->prev};
  h->prev->next = newh;
  h->prev = newh;
  return newh;
}

template < class T >
BiList<T> *insert(BiList<T> *n, const T &d)
{
  return add(h->next, d);
}

template < class T >
BiList<T> *cut(BiList<T> *h) noexcept
{
  if (h->next == h)
  {
    return nullptr;
  }
  BiList<T> *subh = h->next;
  h->prev->next = subh;
  subh->prev = h->prev;
  delete h;
  return subh;
}

template < class T >
BiList<T> *erase(BiList<T> *n) noexcept
{
  if (n->next == n)
  {
    return nullptr;
  }
  return cut(n->next);
}

template < class T >
BiList<T> *clear(BiList<T> *b, BiList<T> *e) noexcept
{
  if (b == nullptr) return e;

  BiList<T> *before = b->prev;

  while (b != e)
  {
    BiList<T> *temp = b->next;
    delete b;
    b = temp;
  }

  if (before != nullptr && b != nullptr) {
    before->next = b;
    b->prev = before;
  }

  return b;
}

template< class T, class F >
F traverse(F f, BiList<T> *b, BiList<T> *e)
{

}

template< class T >
BiList<T> *convert(const T* arr, size_t size)
{

}
