cmake_minimum_required(VERSION 3.19)
project(SystemInformationAgent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core RemoteObjects)

qt_standard_project_setup()
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(shared)
add_subdirectory(server)
add_subdirectory(client)

install(TARGETS SystemInformationAgent
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
