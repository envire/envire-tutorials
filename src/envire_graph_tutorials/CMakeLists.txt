find_package( Boost COMPONENTS system)

rock_executable(frame_tutorials
                SOURCES frames.cpp
                DEPS_PKGCONFIG envire_core
                DEPS_PLAIN Boost_SYSTEM)

                    