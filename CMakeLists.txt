cmake_minimum_required(VERSION 3.16.3)

project(Filter VERSION 1.0)


include_directories(
    ${PROJECT_SOURCE_DIR}/include/utilities
    ${PROJECT_SOURCE_DIR}/include/file_handler
    ${PROJECT_SOURCE_DIR}/include/filter
)

set(HEADER ${HEADER}
    ${PROJECT_SOURCE_DIR}/include/utilities/utilities.h
    ${PROJECT_SOURCE_DIR}/include/file_handler/fileHandler.h
    ${PROJECT_SOURCE_DIR}/include/filter/filterConvolution.h
)

set(SOURCE ${SOURCE} 
    ${PROJECT_SOURCE_DIR}/source/utilities/utilities.c
    ${PROJECT_SOURCE_DIR}/source/file_handler/fileHandler.c
    ${PROJECT_SOURCE_DIR}/source/filter/filterConvolution.c
    ${PROJECT_SOURCE_DIR}/main.c

)

add_executable(${PROJECT_NAME}
	${HEADER}
    ${SOURCE}
)

