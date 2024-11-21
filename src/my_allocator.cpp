#include <iostream>
#include <map>
#include <vector>

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

    my_allocator() = default;
    ~my_allocator() = default;

    // Не хочу копировать мапу
    template <typename U, size_t M>
    my_allocator(const my_allocator<U, MAX>&) = delete;

    T* allocate(std::size_t n) {
        std::cout << "alloc" << "[n = " << n << "]" << std::endl;

        if (n + count_ > MAX) {
            throw std::bad_alloc();
        }
        auto p = std::malloc(n * sizeof(T));
        if (!p) {
            throw std::bad_alloc();
        }
        return static_cast<T*>(p);
    }

    void deallocate(T* p, std::size_t n) {
        std::cout << "dealloc" << "[n = " << n << "]" << std::endl;
        std::free(p);
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        std::cout << "construct" << std::endl;
        new (p) U(std::forward<Args>(args)...);
    };

    template <typename U>
    void destroy(U* p) {
        std::cout << "destroy" << std::endl;
        p->~U();
    }

   private:
    std::map<int, T> _stor{};
    size_t count_ = 0;
};

int main() {
    auto v = std::vector<int, my_allocator<int, 10>>{};
    v.reserve(5);
    for (int i = 0; i < 6; ++i) {
        std::cout << "vector size = " << v.size() << std::endl;
        v.emplace_back(i);
        std::cout << std::endl;
    }

    /*
auto m = std::map<int, float, std::less<int>, my_allocator<std::pair<const int, float>>>{};

for (int i = 0; i < 1; ++i) {
    m[i] = static_cast<float>(i);
}

    */

    return 0;
}
