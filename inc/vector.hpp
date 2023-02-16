//
// Created by tywael on 1/7/23.
//

#ifndef FT_CONTAINER_VECTOR_HPP
#define FT_CONTAINER_VECTOR_HPP

#include <iterator>

namespace ft {
    template< class T,class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef             T                                               value_type;
            typedef             Alloc                                           allocator_type;
            typedef             std::size_t                                     size_type;
            typedef             std::ptrdiff_t                                  difference_type;
            typedef typename    allocator_type::reference                       reference;
            typedef typename    allocator_type::const_reference                 const_reference;
            typedef typename    allocator_type::pointer                         pointer;
            typedef typename    allocator_type::const_pointer                   const_pointer;
            typedef             ft::random_access_iterator<value_type>          iterator;
            typedef             ft::random_access_iterator<const value_type>    const_iterator;
            typedef             std::reverse_iterator<iterator>                 reverse_iterator;
            typedef             std::reverse_iterator<const_iterator>           const_reverse_iterator;

            explicit vector(const allocator_type& alloc = allocator_type())
            :   _alloc(alloc),
                _start(u_nullptr),
                _end(u_nullptr),
                _end_capacity(u_nullptr)
            {}

            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            :   _alloc(alloc),
                _start(u_nullptr),
                _end(u_nullptr),
                _end_capacity(u_nullptr)
            {
                _start = _alloc.allocate(n);
                _end_capacity = _start + n;
                _end = _start;
                while (n--){
                    _alloc.construct(end, val)
                    _end++;
                }
            }

        private:

    };
}

#endif //FT_CONTAINER_VECTOR_HPP
