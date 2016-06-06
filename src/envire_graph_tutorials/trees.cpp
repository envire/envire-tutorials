#include <envire_core/graph/EnvireGraph.hpp>

using namespace envire::core;



int main(int argc, char **argv)
{
  //#snippet_begin:graph_trees_get_1
  EnvireGraph g;
  const FrameId root("root");
  /*
   ....
   */
  TreeView view = g.getTree(root);
  //#snippet_end:graph_trees_get_1
    //#snippet_begin:graph_trees_get_2
  g.getTree(root, &view);
  //#snippet_end:graph_trees_get_2
    //#snippet_begin:graph_trees_get_3
  g.getTree(root, true, &view);
  //#snippet_end:graph_trees_get_3
}