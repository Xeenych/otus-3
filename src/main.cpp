#include "my_allocator.hpp"
#include "my_container.hpp"

#include <iostream>
#include <map>
#include <vector>

constexpr int fact(int v) {
    return v ? v * fact(v - 1) : 1;
}

// Вывод содержимого мапы в консоль
template <typename T, typename V, typename... Args>
std::ostream& operator<<(std::ostream& s, const std::map<T, V, Args...>& a) {
    for (const auto& pair : a) {
        s << pair.first << ' ' << pair.second << std::endl;
    }
    return s;
}

// Вывод вектора в консоль
/*
template <typename T, typename... Args>
std::ostream& operator<<(std::ostream& s, const my_container<T>& a) {
    for (const auto& e : a) {
        s << e << std::endl;
    }
    return s;
}
*/

int main() {
    // 1. Созание экземпляра std::map<int, int>
    auto m1 = std::map<int, int>{};

    // 2. Заполнение 10 элементами
    for (int i = 0; i < 10; ++i) {
        m1[i] = fact(i);
    }

    // 3. Создание экземпляра с новым аллокатором на 10 элементов
    using alloc = my_allocator<std::pair<const int, int>, 10>;
    auto m2 = std::map<int, int, std::less<int>, alloc>{};

    // 4. Заполнение 10 элементами
    for (int i = 0; i < 10; ++i) {
        m2[i] = fact(i);
    }

    // 5. Вывод на экран всех значений
    std::cout << m2;

    // 6. Создание экземпляра своего контейнера
    // my_container<int, my_allocator<int, 100>> m3;
    my_container<int> m3;

    // 7. Заполнение своего контейнера числами от 0 до 9
    for (int i = 0; i < 10; ++i) {
        // m3.emplace_back(i);
        m3.push_back(55);
    }

    std::cout << "size: " << m3.size() << std::endl;

    for (const auto& i : m3) {
        std::cout << i << std::endl;
    }

    return 0;
}