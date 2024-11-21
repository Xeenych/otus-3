#include "my_allocator.hpp"
#include "my_container.hpp"

#include <map>

int main() {
    /*
        auto v = std::vector<int, my_allocator<int, 20>>{};
        v.reserve(5);
        for (int i = 0; i < 6; ++i) {
            v.emplace_back(i);
            std::cout << std::endl;
        }
    */
    using alloc = my_allocator<std::pair<const int, int>, 100>;
    auto m = std::map<int, int, std::less<int>, alloc>{};

    for (int i = 0; i < 3; ++i) {
        m[i] = static_cast<float>(i);
    }

    return 0;
}