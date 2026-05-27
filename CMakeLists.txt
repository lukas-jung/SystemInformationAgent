cmake_minimum_required(VERSION 3.19)
project(SystemInformationAgent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(SystemInformationAgent
    main.cpp
    core/jsonserializable.h
    systeminforeader.h
    memoryinfo.h memoryinfo.cpp
    memoryinforeader.h memoryinforeader.cpp
    storageinfo.h storageinfo.cpp
    storageinforeader.h storageinforeader.cpp
    systeminfo.h
)

target_link_libraries(SystemInformationAgent
    PRIVATE
        Qt::Core
)

install(TARGETS SystemInformationAgent
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
