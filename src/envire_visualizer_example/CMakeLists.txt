rock_executable(envire_visualizer_example
                SOURCES VisualizerExample.cpp
                DEPS_PKGCONFIG envire_core
                DEPS_PKGCONFIG plugin_manager
                DEPS_PKGCONFIG pcl_common-1.7
                DEPS_PKGCONFIG pcl_io-1.7
                DEPS_PKGCONFIG envire_pcl
                DEPS_PKGCONFIG base-lib
                DEPS_PKGCONFIG envire_visualizer)
                
rock_executable(envire_visualizer_example_threaded
                SOURCES VisualizerExampleThreaded.cpp
                DEPS_PKGCONFIG envire_core
                DEPS_PKGCONFIG plugin_manager
                DEPS_PKGCONFIG pcl_common-1.7
                DEPS_PKGCONFIG pcl_io-1.7
                DEPS_PKGCONFIG envire_pcl
                DEPS_PKGCONFIG base-lib
                DEPS_PKGCONFIG vizkit3d
                DEPS_PKGCONFIG envire_visualizer)                
                