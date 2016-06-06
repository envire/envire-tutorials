find_package( Boost COMPONENTS system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

rock_executable(tutorial_frames
                SOURCES frames.cpp
                DEPS_PKGCONFIG envire_core)

rock_executable(tutorial_items
                SOURCES items.cpp
                DEPS_PKGCONFIG envire_core)                    
                
rock_library(tutorial_new_item
             SOURCES newItem.cpp
             HEADERS newItem.h
             DEPS_PKGCONFIG envire_core)