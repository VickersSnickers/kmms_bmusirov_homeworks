cmake_minimum_required(VERSION 3.2...3.27.5)

project(250206_bmusirov_cmake)

enable_testing()
add_subdirectory(lib/googletest)

# add_subdirectory(menu)
# add_subdirectory(sortings)
# add_subdirectory(long_number)
add_subdirectory(vector_list)

set(CMAKE_SUPRESS_REGENERATION true)