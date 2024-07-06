cmake_minimum_required(VERSION 3.0)
project(BSDHostname1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS DBus)

qt_add_dbus_adaptor(GENERATED_SOURCES org.freedesktop.hostname1.xml hostname1.h Hostname1)

# Add executable target
add_executable(hostname1 main.cpp hostname1.cpp logger.cpp ${GENERATED_SOURCES})

# Link Qt5 libraries
target_link_libraries(hostname1 Qt5::Core Qt5::DBus)

configure_file(org.freedesktop.hostname1.service.in org.freedesktop.hostname1.service)
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

install(TARGETS hostname1 RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/org.freedesktop.hostname1.service DESTINATION /usr/local/share/dbus-1/system-services)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/org.freedesktop.hostname1.conf DESTINATION /usr/local/share/dbus-1/system.d)