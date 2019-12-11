//=================================
// include guard
#ifndef NODE_H
#define NODE_H

//=================================
// included dependencies
#include "Sorted_List.h"

class Sorted_List::Node {

  public:
    Node() = default;
    Node(int value_, Node* next_node_)
    : value{value_}, ptr_to_next_node{next_node_}  {}
    Node(Node const & old_node);
    Node& operator=(Node const&);
    ~Node() {}

    Node* clone() const
    {
      if (ptr_to_next_node != nullptr)
      {
        return new Node{value, ptr_to_next_node->clone()};
      }
      else
      {
        return new Node(value, nullptr);
      }
    }

    int value{};
    Node* ptr_to_next_node{};
};
#endif
