//#snippet_begin:graph_new_item_header
#include <envire_core/items/Item.hpp>
#include <envire_core/plugin/Plugin.hpp>

namespace envire { namespace myNamespace
{
  struct MyInternalType{};

  struct MyItem : public envire::core::Item<MyInternalType>
  {
    ENVIRE_PLUGIN_HEADER(MyItem)
    virtual const std::type_info* getTypeInfo() const override
    {
      return &typeid(envire::myNamespace::MyItem);
    }
  };
}}

namespace boost { namespace serialization
{
  template<class Archive>
  void serialize(Archive & ar, ::envire::myNamespace::MyInternalType & data, const unsigned int version)
  {
    //serialize
  }
}}
//#snippet_end:graph_new_item_header