#include <envire_core/graph/EnvireGraph.hpp>

using namespace envire::core;



void addFrame()
{
//#snippet_begin:graph_frames_add_frame
  EnvireGraph g;
  const FrameId frame = "frame_a";
  g.addFrame(frame);
//#snippet_end:graph_frames_add_frame
}


int main(int argc, char **argv)
{
  addFrame();
}