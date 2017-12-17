//
// Created by vlad on 17.12.17.
//

#ifndef TASK_1_VECTORLIST_H
#define TASK_1_VECTORLIST_H

#include <vector>
#include <list>
#include <cstddef>
#include <utility>

template<typename T>
class VectorList {

private:
    using VectT  = std::vector<T>;
    using ListT = std::list<VectT>;

public:
    using value_type = T;

    VectorList() = default;

    VectorList(VectorList const &) = default;

    VectorList(VectorList &&) = default;

    VectorList &operator=(VectorList &&)     = default;

    VectorList &operator=(VectorList const &) = default;

    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
    template<typename It>
    void append(It p, It q) // определена снаружи
    {
        if (p != q)
            data_.push_back(VectT(p, q));
    }

//    bool empty() const { return size() == 0; }

    // определите метод size
    size_t size() const {
        size_t __size = 0;
        for (auto __it = data_.begin(); __it != data_.end(); __it++) {
            __size += (*__it).size();
        }
        return __size;
    }

//
//    // определите const_iterator
    class const_iterator {
    public:
        typedef const_iterator self_type;
        typedef T value_type;
        typedef const T &reference;
        typedef T *pointer;
        typedef int difference_type;
        typedef std::pair<typename ListT::const_iterator, typename VectT::const_iterator> iterator_pair;
        typedef std::forward_iterator_tag iterator_category;

        reference operator*() const {
            typename VectT::const_iterator  __it = position.second;
            return *__it;
        }

        self_type operator++() {
            typename ListT::const_iterator & __list_it = position.first;
            typename VectT::const_iterator & __vec_it = position.second;

            __vec_it++;
            if (__vec_it == __list_it->end()){
                __list_it++;
                __vec_it = __list_it->begin();
            }
            return *this;

        }
        bool operator!=(const self_type& rhs)
        { return position != rhs.position; }

        const_iterator() {
            typename ListT::const_iterator __list_it;
            typename VectT::const_iterator __vec_it;
            position = iterator_pair(__list_it,__vec_it);
        };

        const_iterator(const const_iterator & __other) {
            position = __other.position;
        };

        const_iterator(typename ListT::const_iterator __list_it, typename VectT::const_iterator __vec_it) {
            position = iterator_pair(__list_it, __vec_it);
        };

    private:
        iterator_pair position;
    };

    const_iterator begin() const {
        typename ListT::const_iterator __first_it = data_.begin();
        typename VectT::const_iterator __second_it = __first_it->begin();
        return const_iterator(__first_it,__second_it);
    }

    const_iterator end() const {
        typename ListT::const_iterator __last_it_list = data_.end();
        typename VectT::const_iterator __last_vector_it = __last_it_list->begin();
        return const_iterator(__last_it_list,__last_vector_it);
    }

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


    const_reverse_iterator rbegin() const {
        typename ListT::const_iterator __first_it = data_.begin();
        typename VectT::const_iterator __second_it = __first_it->begin();

        return const_reverse_iterator(const_iterator(__first_it,__second_it));
    }

    const_reverse_iterator rend() const {
        typename ListT::const_iterator __last_it_list = data_.end();
        typename VectT::const_iterator __last_vector_it = __last_it_list->begin();
        return const_reverse_iterator(const_iterator(__last_it_list,__last_vector_it));
    }

private:
    ListT data_;
};


#endif //TASK_1_VECTORLIST_H
