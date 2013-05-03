find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE}) #include_directories, etc
#moc? QT4_WRAP_CPP(outfiles infiles options)

set(MOC_HEADERS mainwindow.h )

QT4_WRAP_CPP(MOC_SRCS ${MOC_HEADERS})
add_executable(phastasteering guimain.cpp ${MOC_SRCS} mainwindow.cpp ${MOC_SRCS})
target_link_libraries(phastasteering ${QT_LIBRARIES} )
