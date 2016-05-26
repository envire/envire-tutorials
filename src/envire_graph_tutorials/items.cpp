#include <envire_core/graph/EnvireGraph.hpp>
//#snippet_begin:graph_items_classloader_includes
#include <envire_core/plugin/ClassLoader.hpp>
#include <envire_octomap/OcTree.hpp>
//#snippet_end:graph_items_classloader_includes
using namespace envire::core;

int main(int argc, char **argv)
{
  
  const FrameId frame = "I am so smart, S M A T";
  EnvireGraph g;
  g.addFrame(frame);
  //#snippet_end:graph_items_setup
  
  //#snippet_begin:graph_items_load_octree
  envire::octomap::OcTree::Ptr octree;
  ClassLoader* loader = ClassLoader::getInstance();
  if(!loader->createEnvireItem("envire::octomap::OcTree", octree))
  {
    std::cerr << "Unabled to load envire::octomap::OcTree" << std::endl;
    return -1;
  }
  //#snippet_end:graph_items_load_octree
  //#snippet_begin:graph_items_add_to_frame
  g.addItemToFrame(frame, octree);
  //#snippet_end:graph_items_add_to_frame
  //#snippet_begin:graph_items_setFrame
  octree->setFrame(frame);
  g.addItem(octree);
  //#snippet_end:graph_items_setFrame
  
  //#snippet_begin:graph_items_contains_item
  const bool contains = g.containsItems<envire::octomap::OcTree>(frame);
  //#snippet_end:graph_items_contains_item
  assert(contains);
  //#snippet_begin:graph_items_contains_type_index
  const std::type_index index(octree->getTypeIndex());
  const bool contains2 = g.containsItems(frame, index);
  //#snippet_end:graph_items_contains_type_index
  assert(contains2);
  
  
}