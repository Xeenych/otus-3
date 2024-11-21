#pragma once
#include <array>
#include <iostream>

template <typename T, size_t MAX>
struct my_allocator {
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    template <typename U>
    struct rebind {
        using other = my_allocator<U, MAX>;
    };

    my_allocator() {}
    ~my_allocator() = default;

    // Не хочу копировать мапу
    template <typename U, size_t M>
    my_allocator(const my_allocator<U, MAX>&) = delete;

    T* allocate(std::size_t n) {
        std::cout << "alloc" << "[n = " << n << "]" << std::endl;

        // Места больше нет
        if (_begin + n > _stor.end()) {
            throw std::bad_alloc();
        }

        T* ret = _begin;
        _begin += n;
        return ret;
    }

    void deallocate(T*, std::size_t) {
        // We do not deallocate memory
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        //std::cout << "construct" << std::endl;
        new (p) U(std::forward<Args>(args)...);
    };

    template <typename U>
    void destroy(U* p) {
        //std::cout << "destroy" << std::endl;
        p->~U();
    }

   private:
    typename std::array<T, MAX> _stor{};
    typename std::array<T, MAX>::iterator _begin = _stor.begin();
};
