qt_add_executable(SystemInformationAgentClient
    main.cpp
    systeminfojsonparser.h
    storageinfojsonparser.h storageinfojsonparser.cpp
    messagejsonparser.h messagejsonparser.cpp
)


qt_add_repc_replicas(SystemInformationAgentClient ../remote_objects/systeminformationservice.rep)

target_link_libraries(SystemInformationAgentClient
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
