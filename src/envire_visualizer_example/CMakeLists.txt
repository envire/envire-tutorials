find_package( Boost COMPONENTS system)

rock_executable(envire_visualizer_example
                SOURCES VisualizerExample.cpp
                DEPS_PKGCONFIG 
                    envire_core
                    plugin_manager
                    pcl_common-1.7
                    pcl_io-1.7
                    envire_pcl
                    base-lib
                    envire_visualizer
)
                
rock_executable(envire_visualizer_example_threaded
                SOURCES VisualizerExampleThreaded.cpp
                DEPS_PKGCONFIG 
                    envire_core
                    plugin_manager
                    pcl_common-1.7
                    pcl_io-1.7
                    envire_pcl
                    base-lib
                    vizkit3d
                    envire_visualizer
)
                    