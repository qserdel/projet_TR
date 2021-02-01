# Install script for directory: /home/polytech/Bureau/projet_TR/TP3/rosws/src/HelloWorld/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/polytech/Bureau/projet_TR/TP3/rosws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so"
         RPATH "/home/polytech/ws/underlay_isolated/install_isolated/lib:/home/polytech/ws/underlay_isolated/install_isolated/lib/orocos/gnulinux:/home/polytech/ws/underlay_isolated/install_isolated/lib/orocos/gnulinux/plugins:/home/polytech/ws/underlay_isolated/install_isolated/lib/orocos/gnulinux/types:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib/orocos/gnulinux/HelloWorld:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib/orocos/gnulinux/HelloWorld/types:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib/orocos/gnulinux/HelloWorld/plugins:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld" TYPE SHARED_LIBRARY FILES "/home/polytech/Bureau/projet_TR/TP3/rosws/devel/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so"
         OLD_RPATH "/home/polytech/ws/underlay_isolated/install_isolated/lib::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/home/polytech/ws/underlay_isolated/install_isolated/lib:/home/polytech/ws/underlay_isolated/install_isolated/lib/orocos/gnulinux:/home/polytech/ws/underlay_isolated/install_isolated/lib/orocos/gnulinux/plugins:/home/polytech/ws/underlay_isolated/install_isolated/lib/orocos/gnulinux/types:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib/orocos/gnulinux/HelloWorld:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib/orocos/gnulinux/HelloWorld/types:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib/orocos/gnulinux/HelloWorld/plugins:/home/polytech/Bureau/projet_TR/TP3/rosws/install/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/HelloWorld/libHelloWorld-gnulinux.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/orocos/HelloWorld" TYPE FILE FILES "/home/polytech/Bureau/projet_TR/TP3/rosws/src/HelloWorld/src/HelloWorld-component.hpp")
endif()

