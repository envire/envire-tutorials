#include <envire_core/graph/EnvireGraph.hpp>

using namespace envire::core;


void removeFrame()
{
//#snippet_begin:graph_frames_remove_frame
  EnvireGraph g;
  const FrameId frame = "frame_a";
  g.addFrame(frame);
  g.disconnectFrame(frame);
  g.removeFrame(frame);
//#snippet_end:graph_frames_remove_frame
}


void addFrameTransform()
{
//#snippet_begin:graph_frames_add_transform_frame
  EnvireGraph g;
  const FrameId frameA = "frame_a";
  const FrameId frameB = "frame_b";
  Transform tf;
  g.addTransform(frameA, frameB, tf);
//#snippet_end:graph_frames_add_transform_frame
}

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
  addFrameTransform();
  removeFrame();
}