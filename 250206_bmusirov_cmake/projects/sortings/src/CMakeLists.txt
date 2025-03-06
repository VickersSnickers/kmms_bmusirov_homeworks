target_sources(selection_sort_lib
	PRIVATE
		selection_sort.cpp
	PUBLIC
		selection_sort.hpp
)

target_include_directories(selection_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)