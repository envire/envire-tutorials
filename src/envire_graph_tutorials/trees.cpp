#include <envire_core/graph/EnvireGraph.hpp>

using namespace envire::core;



int main(int argc, char **argv)
{
  //#snippet_begin:graph_transforms_add
  EnvireGraph g;
  const FrameId root("root");
  /*
   ....
   */
  TreeView view;
  g.getTree(root, true, &view);
  //#snippet_end:graph_transforms_add
}