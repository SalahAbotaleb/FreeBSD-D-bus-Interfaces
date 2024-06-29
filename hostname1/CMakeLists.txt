cmake_minimum_required(VERSION 3.0)
project(BSDHostname1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS DBus)

# Generate .h and .cpp files from D-Bus XML interface
qt_add_dbus_interface(GENERATED_SOURCES org.freedesktop.hostname1.xml hostname1)

# Add executable target
add_executable(hostname1 main.cpp ${GENERATED_SOURCES})

# Link Qt5 libraries
target_link_libraries(hostname1 Qt5::Core Qt5::DBus)
