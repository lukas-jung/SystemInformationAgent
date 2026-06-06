add_library(SystemInformationAgentShared STATIC
    core/include/jsonserializable.h
    include/memoryinfo.h memoryinfo.cpp
    include/storageinfo.h storageinfo.cpp
    include/systeminfo.h
    include/message.h message.cpp
)

target_link_libraries(SystemInformationAgentShared
    PRIVATE
        Qt::Core
)


target_include_directories(SystemInformationAgentShared
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/core/include
)
