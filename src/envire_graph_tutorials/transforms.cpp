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
#include <vector>
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
  envire::core::Path::Ptr path = g.getPath(a, b, false);
  const Transform tf4 = g.getTransform(path);
  //#snippet_end:graph_transforms_path_get
}