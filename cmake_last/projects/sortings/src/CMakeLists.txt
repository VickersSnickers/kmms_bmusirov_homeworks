target_sources(sortings
	PRIVATE
		selection_sort.cpp
	PUBLIC
		selection_sort.hpp
)

target_include_directories(sortings PRIVATE
	"${PROJECT_SOURCE_DIR}/src"
)