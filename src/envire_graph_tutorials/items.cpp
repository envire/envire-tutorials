#include <envire_core/graph/EnvireGraph.hpp>
#include <envire_core/plugin/ClassLoader.hpp>
#include <envire_octomap/OcTree.hpp>

using namespace envire::core;

int main(int argc, char **argv)
{
  //#snippet_begin:graph_items_setup
  const FrameId frame = "I am so smart, S M A T";
  EnvireGraph g;
  g.addFrame(frame);
  //#snippet_end:graph_items_setup
  
  //#snippet_begin:graph_items_load_octree
  envire::octomap::OcTree::Ptr octree;
  if(!ClassLoader::createEnvireItem("envire::octomap::OcTree", octree))
  {
    std::cerr << "Unabled to load envire::octomap::OcTree" << std::endl;
    return -1;
  }
  //#snippet_end:graph_items_load_octree
  
  g.addItemToFrame(frame, octree);
  
  octree->setFrame(frame);
  g.addItem(octree);
  
  
}