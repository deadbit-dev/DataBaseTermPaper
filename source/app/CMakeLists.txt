cmake_minimum_required (VERSION 3.8)

set(TARGET Application)

project (${TARGET})

file(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../connection/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../data_base/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../prepared_statement/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../result/*.cpp
	${DIR_THIRDPARTY}/sqlite/source/shell.c
	${DIR_THIRDPARTY}/sqlite/source/sqlite3.c
)

file(GLOB HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/../connection/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/../data_base/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/../prepared_statement/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/../result/*.h
)

add_executable(${TARGET} ${SOURCES} ${HEADERS})

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${DIR_EXPORT})
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${DIR_EXPORT})
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${DIR_EXPORT})
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${DIR_EXPORT})

target_include_directories(${TARGET} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/../connection/
	${CMAKE_CURRENT_SOURCE_DIR}/../data_base/
	${CMAKE_CURRENT_SOURCE_DIR}/../prepared_statement/
	${CMAKE_CURRENT_SOURCE_DIR}/../result/
)

set_target_properties(${TARGET} PROPERTIES DEBUG_POSTFIX _debug)

target_link_libraries(${TARGET} PUBLIC mysqlcppconn)

add_custom_command(
	TARGET ${TARGET} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${DIR_THIRDPARTY}/connector/dll/
		${DIR_EXPORT}/
)

target_link_options(${TARGET} PUBLIC "/MANIFEST:NO")