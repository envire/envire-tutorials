#include <envire_core/graph/EnvireGraph.hpp>

using namespace envire::core;



int main(int argc, char **argv)
{
  //#snippet_begin:graph_transforms_add
  EnvireGraph g;
  const FrameId a = "frame_a";
  const FrameId b = "frame_b";
  Transform ab;
  /** initialize Transform */
  g.addTransform(a, b, ab);
  //#snippet_end:graph_transforms_add
  
  //#snippet_begin:graph_transforms_remove
  g.removeTransform(a, b);
  //#snippet_end:graph_transforms_remove
  
  //#snippet_begin:graph_transforms_update
  Transform tf;
  tf.transform.translation << 84, 21, 42;
  g.updateTransform(a, b, tf);
  //#snippet_end:graph_transforms_update
  
  //#snippet_begin:graph_transforms_get
  const Transform tf2 = g.getTransform(a, b);
  //#snippet_end:graph_transforms_get

  //#snippet_begin:graph_transforms_tree_get
  TreeView view = g.getTree(g.getVertex(a));
  const Transform tf3 = g.getTransform(a, b, view);
  //#snippet_end:graph_transforms_tree_get 
  
  //#snippet_begin:graph_transforms_path_get
  const vector<FrameId> path = g.getPath(a, b);
  const Transform tf4 = g.getTransform(path);
  //#snippet_end:graph_transforms_path_get
}