cmake_minimum_required (VERSION 3.8)
project ("DataBaseTermPaper")

set(DIR_THIRDPARTY ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty)
set(DIR_EXPORT ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})

if (WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 /Zc:__cplusplus")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_WARNINGS")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fstrict-aliasing -Wno-unknown-pragmas -Wno-unused-function")
endif()

include_directories("3rdParty/")
include_directories("3rdParty/connector/include")
include_directories("3rdParty/sqlite/include")

link_directories("3rdparty/connector/lib")

add_subdirectory (source/app)