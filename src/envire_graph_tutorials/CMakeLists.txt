find_package( Boost COMPONENTS system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

rock_executable(frame_tutorials_frames
                SOURCES frames.cpp
                DEPS_PKGCONFIG envire_core)

rock_executable(frame_tutorials_items
                SOURCES items.cpp
                DEPS_PKGCONFIG envire_core)                    