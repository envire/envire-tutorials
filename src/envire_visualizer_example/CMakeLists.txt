find_package( Boost COMPONENTS system)
find_package(PCL 1.7 REQUIRED COMPONENTS common)

set(PCL_LIBS pcl_common-${PCL_VERSION_MAJOR}.${PCL_VERSION_MINOR} pcl_io-${PCL_VERSION_MAJOR}.${PCL_VERSION_MINOR})

rock_executable(envire_visualizer_example
                SOURCES VisualizerExample.cpp
                DEPS_PKGCONFIG 
                    envire_core
                    plugin_manager
                    ${PCL_LIBS}
                    envire_pcl
                    base-lib
                    base-logging
                    envire_visualizer
)
                
rock_executable(envire_visualizer_example_threaded
                SOURCES VisualizerExampleThreaded.cpp
                DEPS_PKGCONFIG 
                    envire_core
                    plugin_manager
                    ${PCL_LIBS}
                    envire_pcl
                    base-lib
                    base-logging
                    vizkit3d
                    envire_visualizer
)
                    