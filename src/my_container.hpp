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
        if (_size == _capacity) {
            auto old_capacity = _capacity;
            _capacity = 10;

            T* newData = _a.allocate(_capacity);
            if (_data) {
                std::copy(_data, _data + old_capacity, newData);
                std::swap(newData, _data);
                _a.deallocate(newData, old_capacity);
            } else {
                _data = newData;
            }
        }
        _a.construct(_data + _size, val);
        ++_size;
    }

    size_t size() const { return _size; }

    const_iterator begin() const { return _data; }
    iterator begin() { return _data; }
    const_iterator end() const { return _data + _size; }
    iterator end() { return _data + _size; }

   private:
    allocator_type _a{};
    std::size_t _size = 0;
    std::size_t _capacity = 0;
    T* _data = nullptr;
};