//
// Copyright (c) 2015, Deutsches Forschungszentrum für Künstliche Intelligenz GmbH.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

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