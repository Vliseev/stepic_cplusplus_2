//
// Created by vlad on 17.12.17.
//

#ifndef TASK_1_VECTORLIST_H
#define TASK_1_VECTORLIST_H

#include <vector>
#include <list>
#include <cstddef>

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
            data_.push_back(VectT(p,q));
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
//    class const_iterator {
//        typedef const_iterator self_type;
//        typedef T value_type;
//        typedef T &reference;
//        typedef T *pointer;
//        typedef int difference_type;
//        typedef std::forward_iterator_tag iterator_category;
//
//    private:
//        pointer ptr_;
//    };
//    const_iterator begin() const { return  ; }
//    const_iterator end()   const { return ... ; }

private:
    ListT data_;
};


#endif //TASK_1_VECTORLIST_H
