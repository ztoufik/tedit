file(GLOB SOURCES *.cc)
#add_library(CuckooHash ${SOURCES})


# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/inc/)
target_link_libraries(${PROJECT_NAME} PUBLIC curses)
