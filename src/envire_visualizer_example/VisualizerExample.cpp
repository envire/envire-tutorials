//#snippet_begin:graph_viz_example_includes
#include <envire_visualizer/EnvireVisualizerWindow.hpp>
#include <envire_core/graph/EnvireGraph.hpp>
//#snippet_end:graph_viz_example_includes
#include <envire_core/items/Transform.hpp>
#include <base/samples/RigidBodyState.hpp>
#include <envire_smurf/GraphLoader.hpp>

//following includes are only needed for writeGraphToFile()
#include <plugin_manager/PluginLoader.hpp>
#include <envire_core/items/Item.hpp>
#include <pcl/io/pcd_io.h>
#include <QFile>
#include <QApplication>
#include <chrono>
#include <thread>
#include <maps/grid/MLSMap.hpp>
#include <smurf/Robot.hpp>

using namespace envire::viz;

maps::grid::MLSMapPrecalculated mlsMap;

std::shared_ptr<envire::core::EnvireGraph> createGraph()
{   
    std::shared_ptr<envire::core::EnvireGraph> graph(new envire::core::EnvireGraph);
    plugin_manager::PluginLoader* loader = plugin_manager::PluginLoader::getInstance();
    envire::core::ItemBase::Ptr mapItem;
    loader->createInstance("envire::core::Item<maps::grid::MLSMapPrecalculated>", mapItem);
    assert(mapItem != nullptr);
    envire::core::Item<maps::grid::MLSMapPrecalculated>::Ptr map =  boost::dynamic_pointer_cast<envire::core::Item<maps::grid::MLSMapPrecalculated>>(mapItem);
        
    envire::core::EnvireGraph g;
    g.loadFromFile("/home/dfki.uni-bremen.de/aboeckmann/stuff/mls/graph_mls_kalman.bin");
    map->setData(g.getItem<envire::core::Item<maps::grid::MLSMapKalman>>("mls_map", 0)->getData());
    
    graph->addFrame("root_node");
    envire::core::Transform tf;
    tf.setIdentity();
    std::cout << "trans: " << tf.transform.translation.transpose() << std::endl;
    graph->addTransform("root_node", "map", tf);
    graph->addItemToFrame("map", map);
        
    envire::core::Transform robotTf;
    robotTf.transform.translation << 0, 0, 1;
    robotTf.transform.orientation.setIdentity();
    graph->addTransform("root_node", "robot", robotTf);
//     
    std::shared_ptr<envire::smurf::GraphLoader> graphLoader(new envire::smurf::GraphLoader(graph, robotTf));
    smurf::Robot* robot = new(smurf::Robot);
    robot->loadFromSmurf("/home/dfki.uni-bremen.de/aboeckmann/git/rock-entern/models/robots/crex/smurf/crex.smurf");
    int nextGrpId = 0;
    graphLoader->loadStructure(graph->getVertex("robot"), *robot);
    graphLoader->loadVisuals(*robot);
    
//     graphLoader->loadRobot(nextGrpId, graph->getVertex("robot"), robotTf, *robot);
    
  

//   envire::core::ItemBase::Ptr cloudItem2;
//   envire::core::ItemBase::Ptr cloudItem3;
//   loader->createInstance("envire::core::Item<pcl::PCLPointCloud2>", cloudItem);
//   loader->createInstance("envire::core::Item<pcl::PCLPointCloud2>", cloudItem2);
//   loader->createInstance("envire::core::Item<pcl::PCLPointCloud2>", cloudItem3);
//   envire::core::Item<pcl::PCLPointCloud2>::Ptr cloud = boost::dynamic_pointer_cast<envire::core::Item<pcl::PCLPointCloud2>>(cloudItem);
//   envire::core::Item<pcl::PCLPointCloud2>::Ptr cloud2 = boost::dynamic_pointer_cast<envire::core::Item<pcl::PCLPointCloud2>>(cloudItem2);
//   envire::core::Item<pcl::PCLPointCloud2>::Ptr cloud3 = boost::dynamic_pointer_cast<envire::core::Item<pcl::PCLPointCloud2>>(cloudItem3);
//   
//   const char* rootPath = std::getenv("AUTOPROJ_CURRENT_ROOT");
//   if(rootPath == nullptr)
//   {
//     std::cerr << "Environment variable AUTOPROJ_CURRENT_ROOT not set. Cannot locate"
//               << " pcl example files. Building graph without pointclouds" << std::endl;
//   }
// 
//   const std::string bunnyPcd = std::string(rootPath) + "/slam/pcl/test/bunny.pcd";
//   const std::string turtlePcd = std::string(rootPath) + "/slam/pcl/test/cturtle.pcd";
//   pcl::PCDReader reader;
//   if(QFile::exists(QString::fromStdString(bunnyPcd)))
//   {
//     reader.read(bunnyPcd, cloud->getData());
//     reader.read(bunnyPcd, cloud2->getData());
//   }
//   else
//   {
//     std::cerr << bunnyPcd << " does not exist" << std::endl;
//   }
//   
//   if(QFile::exists(QString::fromStdString(turtlePcd)))
//   {
//     reader.read(turtlePcd, cloud3->getData());
//   }
//   else
//   {
//     std::cerr << turtlePcd << " does not exist" << std::endl;
//   }
// 
//   envire::core::Item<std::string>::Ptr strItem(new envire::core::Item<std::string>("Huh. Did everything just taste purple for a second? "));
//   
//   envire::core::EnvireGraph* graph = new envire::core::EnvireGraph;
//   graph->addFrame("A"); 
//   graph->addFrame("B");
//   graph->addFrame("C");
//   graph->addFrame("D");
//   graph->addItemToFrame("B", cloud);
//   graph->addItemToFrame("D", cloud2);
//   graph->addItemToFrame("A", cloud3); //special case item in root node
//   
//   graph->addItemToFrame("C", strItem);
//   
//   envire::core::Transform ab(base::Position(1, 1, 1), Eigen::Quaterniond::Identity());
//   graph->addTransform("A", "B", ab);
//   envire::core::Transform bc(base::Position(1, 0, 0.3), Eigen::Quaterniond(Eigen::AngleAxisd(0.3, Eigen::Vector3d(1,0,3))));
//   graph->addTransform("B", "C", ab);  
//   envire::core::Transform cd(base::Position(0, 2, -1), Eigen::Quaterniond(Eigen::AngleAxisd(-0.8, Eigen::Vector3d(0,0,1))));
//   graph->addTransform("C", "D", cd);  
//   
//   graph->addFrame("randTree");
//   envire::core::Transform aToForrest(base::Position(0, -3, -2), Eigen::Quaterniond(Eigen::AngleAxisd(0, Eigen::Vector3d(0,0,1))));
//   graph->addTransform("A", "randTree", aToForrest);
  
  return graph;
}

int main(int argc, char **argv)
{
  //#snippet_begin:graph_viz_example_code
  QApplication app(argc, argv);
  EnvireVisualizerWindow window;
  std::shared_ptr<envire::core::EnvireGraph> graph(createGraph());
  window.displayGraph(graph, "root_node");
  window.show();
  
//   std::thread t([&graph](){
//         while(true)
//         {
//         std::this_thread::sleep_for(std::chrono::milliseconds(300));
//         envire::core::Transform ab = graph->getTransform("A", "B");
//         ab.transform.translation.x() += 0.1;
//         std::cout << ab.transform.translation.x() << std::endl;
//         graph->updateTransform("A", "B", ab);
//         }
//     });
  
  app.exec();
//#snippet_end:graph_viz_example_code
  return 0;
}