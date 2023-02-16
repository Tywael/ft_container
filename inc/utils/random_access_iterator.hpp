//
// Created by tywael on 2/16/23.
// source: https://en.cppreference.com/w/cpp/iterator/random_access_iterator

#ifndef FT_CONTAINER_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINER_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename T>
		class random_access_iterator: ft::iterator<ft::random_access_iterator_tag, T> {
		public:
			typedef typename 	ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename 	ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename 	ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef T *pointer;
			typedef T &reference;

		private:
			pointer	_ptr;
		public:
			//constructor: void - value - copy
			random_access_iterator(): _ptr(NULL) {}
			random_access_iterator(pointer ptr): _ptr(ptr) {}
			random_access_iterator(const random_access_iterator &cpy): _ptr(cpy._ptr) {}

			//operator: copy
			random_access_iterator &operator=(const random_access_iterator &rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			}

			//destructor
			virtual ~random_access_iterator() {}

			//getter
			pointer base() const {	return (this->_ptr); }

			//operator: dereference
			reference operator*() const { return (*_ptr); }
			pointer operator->() const { return (&(this->operator*())); }
			reference operator[](difference_type n) { return (*(operator+(n))); }

			//operator: decrement
			random_access_iterator &operator--() {
				_ptr--;
				return (*this);
			}
			random_access_iterator operator--(int) {
				random_access_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			//operator: increment
			random_access_iterator &operator++() {
				_ptr++;
				return (*this);
			}
			random_access_iterator operator++(int) {
				random_access_iterator tmp = *this;
				--(*this)
				return (tmp);
			}

			//operator:
			random_access_iterator operator+(difference_type n) const { return (this->_ptr + n); }
			random_access_iterator operator-(difference_type n) const { return (this->_ptr - n); }

			//operator: + affectation
			random_access_iterator &operator+=(difference_type n) const {
				this->_ptr += n;
				return (*this);
			}
			random_access_iterator &operator-=(difference_type n) const {
				this->_ptr -= n;
				return (*this);
			}

			//operator: to const
			operator random_access_iterator<const T> () const { return (random_access_iterator<const T>(this->_ptr)); }

		}
}

#endif //FT_CONTAINER_RANDOM_ACCESS_ITERATOR_HPP
