file(GLOB SOURCES *.cc)
#add_library(CuckooHash ${SOURCES})


enable_testing()

set(test_name tedittest)

# add the executable
add_executable(${test_name} ${SOURCES})

target_include_directories(${test_name} PRIVATE ${PROJECT_SOURCE_DIR}/inc/)

target_link_libraries(
    ${test_name}
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${test_name})
