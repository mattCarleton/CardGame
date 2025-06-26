cmake_minimum_required(VERSION 3.16)

project(CardGame LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test)

# Main application executable
add_executable(CardGame
  main.cpp
  Card.h Card.cpp
  Deck.h Deck.cpp
)
target_link_libraries(CardGame Qt${QT_VERSION_MAJOR}::Core)

# Test executable
add_executable(all_tests
    tests/all_tests.cpp
    tests/card_test.h tests/card_test.cpp
    tests/deck_test.h tests/deck_test.cpp
    Card.cpp
    Deck.cpp
)
target_link_libraries(all_tests Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Core)

enable_testing()
add_test(NAME AllTests COMMAND all_tests)

include(GNUInstallDirs)
install(TARGETS CardGame
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
