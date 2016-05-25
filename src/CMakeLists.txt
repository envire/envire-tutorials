set(deps_pkg_config base-types)

rock_executable(tutorials_bin
                SOURCES main.cpp)

add_subdirectory(envire_visualizer_example)
add_subdirectory(envire_graph_tutorials)