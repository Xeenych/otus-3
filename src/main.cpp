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

    auto m = std::map<int, float, std::less<int>, my_allocator<std::pair<const int, float>, 100>>{};

    for (int i = 0; i < 3; ++i) {
        m[i] = static_cast<float>(i);
    }

    return 0;
}