cmake_minimum_required(VERSION 3.19)
project(SystemInformationAgent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core RemoteObjects)

qt_standard_project_setup()
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt_add_executable(SystemInformationAgent
    main.cpp
    core/jsonserializable.h
    systeminforeader.h
    memoryinfo.h memoryinfo.cpp
    memoryinforeader.h memoryinforeader.cpp
    storageinfo.h storageinfo.cpp
    storageinforeader.h storageinforeader.cpp
    systeminfo.h
    systeminfojsonparser.h
    storageinfojsonparser.h storageinfojsonparser.cpp
    message.h message.cpp
    poller.h poller.cpp
    messagejsonparser.h messagejsonparser.cpp
    systeminformationservice.h systeminformationservice.cpp
)

qt_add_repc_sources(SystemInformationAgent systeminformationservice.rep)
qt_add_repc_replicas(SystemInformationAgent systeminformationservice.rep)

target_link_libraries(SystemInformationAgent
    PRIVATE
        Qt::Core
        Qt::RemoteObjects
)

install(TARGETS SystemInformationAgent
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
