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
#include <envire_core/plugin/ClassLoader.hpp>
#include <envire_core/items/Item.hpp>
#include <octomap/AbstractOcTree.h>

using namespace envire::core;

int main(int argc, char **argv)
{
  const FrameId frame = "I am so smart, S M A T";
  EnvireGraph g;
  g.addFrame(frame);

  envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>::Ptr octree;
  ClassLoader* loader = ClassLoader::getInstance();
  if(!loader->createEnvireItem("envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>", octree))
  {
    std::cerr << "Unabled to load envire::octomap::OcTree" << std::endl;
    return -1;
  }
  

  g.addItemToFrame(frame, octree);
  octree->setFrame(frame);
  g.addItem(octree);
  const bool contains = g.containsItems<envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>>(frame);
  assert(contains);

  const std::type_index index(octree->getTypeIndex());
  const bool contains2 = g.containsItems(frame, index);

  assert(contains2);
  
  using Iterator = EnvireGraph::ItemIterator<envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>>;
  Iterator it, end;
  std::tie(it, end) = g.getItems<envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>>(frame);
  for(; it != end; ++it)
  {
    std::cout << "Item uuid: " << it->getIDString() << std::endl;
  }

  Iterator itemIt = g.getItem<envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>>(frame, 42);

  const std::type_index index2(octree->getTypeIndex());
  const Frame::ItemList& items = g.getItems(frame, index2);

  Iterator i, endI;
  std::tie(i, endI) = g.getItems<envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>>(frame);
  for(; i != endI;)
  {
      std::tie(i, endI) = g.removeItemFromFrame(frame, i);
  }

  g.clearFrame(frame);

}