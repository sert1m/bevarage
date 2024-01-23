
include_directories(beverage condiment .)

file(GLOB SOURCE_MAIN "main.cpp")
add_executable(coffe ${SOURCE_MAIN})
target_link_libraries(coffe PUBLIC gtest pthread)
