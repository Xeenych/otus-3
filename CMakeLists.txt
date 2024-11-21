cmake_minimum_required(VERSION 3.5)

project(otus-3)
#add_compile_options(-Werror)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Warray-bounds)
#add_compile_options(-Weffc++)

add_executable(allocator src/main.cpp)
set_target_properties(allocator PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

#add_executable(01_std_03_allocator simple_allocator.cpp)
#set_target_properties(01_std_03_allocator PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

#add_executable(00_new_overload new_overload.cpp)
#set_target_properties(00_new_overload PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

#add_executable(03_allocator_traits allocator_traits.cpp)
#set_target_properties(03_allocator_traits PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

#add_executable(04_polymorphism polymorphism.cpp)
#set_target_properties(04_polymorphism PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

#add_executable(05_polymorphic_allocator polymorphic_allocator.cpp)
#set_target_properties(05_polymorphic_allocator PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

