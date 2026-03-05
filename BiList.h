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
BiList<T> *create(const T &d)
{
  BiList<T> *h = new BiList<T>{d, nullptr, nullptr}; //конструктор копирования
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
  BiList<T> *newh = new BiList<T>{d, h, h->prev}; //конструктор копирования
  h->prev->next = newh;
  h->prev = newh;
  return newh;
}

template < class T >
BiList<T> *insert(BiList<T> *n, const T &d)
{
  return add(n->next, d);
}

template < class T >
BiList<T> *cut(BiList<T> *h) noexcept
{
  if (h->next == h)
  {
    delete h; //деструктор по умолчанию
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
  if (b == e)
  {
    if (b->next == b)
    {
      delete b; //деструктор по умолчанию
      return nullptr;
    }

    BiList<T> *last = b->prev;
    last->next = nullptr;

    BiList<T> *cur = b;
    while (cur != nullptr)
    {
      BiList<T> *temp = cur->next;
      delete cur; //деструктор по умолчанию
      cur = temp;
    }

    return nullptr;
  }

  BiList<T> *bef = b->prev;
  while (b != e)
  {
    BiList<T> *temp = b->next;
    delete b; //деструктор по умолчанию
    b = temp;
  }

  if (bef != nullptr && b != nullptr)
  {
    bef->next = b;
    b->prev = bef;
  }

  return b;
}

template< class T, class F >
F traverse(F f, BiList<T> *b, BiList<T> *e)
{
  if (!b) return f;

  if (b == e)
  {
    BiList<T>* start = b;
    for(; ; b = b->next)
    {
      f(b->data); //может вызываться конструктор копирования, если функтор принимает аргумент по значению
      if (b->next == start) break;
    }
    return f;
  }

  for(; b != e; b = b->next)
  {
    f(b->data);
  }

  return f;
}

template< class T >
BiList<T> *convert(const T *arr, size_t size)
{
  if (arr == nullptr || size == 0)
  {
    return nullptr;
  }

  BiList<T> *head = nullptr;

  try
  {
    head = create(arr[0]); //конструктор копирования

    for (size_t i = 1; i < size; ++i)
    {
        head = add(head, arr[i]); //конструктор копирования
    }
    return head;
  }
  catch (...)
  {
    clear(head, head); //деструктор по умолчанию
    throw;
  }
}

#endif
