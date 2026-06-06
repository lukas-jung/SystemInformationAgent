qt_add_executable(SystemInformationAgent
    main.cpp
    systeminforeader.h
    memoryinforeader.h memoryinforeader.cpp
    storageinforeader.h storageinforeader.cpp
    poller.h poller.cpp
    systeminformationservice.h systeminformationservice.cpp
)

qt_add_repc_sources(SystemInformationAgent ../remote_objects/systeminformationservice.rep)

target_link_libraries(SystemInformationAgent
    PRIVATE
        Qt::Core
        Qt::RemoteObjects
        SystemInformationAgentShared
)

install(TARGETS SystemInformationAgent
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
