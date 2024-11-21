#pragma once
#include <memory>
#include <string>

template <class T, class Allocator = std::allocator<T>>
class my_container {
   public:
    using value_type = T;
    using allocator_type = Allocator;
    using const_iterator = const T*;
    using iterator = T*;

    my_container() {}

    void push_back(const T& val) {
        auto* p = _a.allocate(1);
        if (!_begin) {
            _begin = p;
        }
        _end = p + 1;
        _a.construct(p, val);
        // std::copy(&val, &val + 1, p);
    }

    template <class... Args>
    T& emplace_back(Args&&... args) {
        auto* p = _a.allocate(1);
        if (!_begin) {
            _begin = p;
        }
        _end = std::next(p);
        _a.construct(p, args...);
        return *p;
    }

    size_t size() const {
        if (!_end || !_begin) {
            return 0;
        }
        return _end - _begin;
    }

    const_iterator begin() const { return _begin; }
    iterator begin() { return _begin; }
    const_iterator end() const { return _end; }
    iterator end() { return _end; }

   private:
    allocator_type _a{};
    iterator _begin = nullptr;
    iterator _end = nullptr;
};