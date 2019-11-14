//=================================
// include guard
#ifndef NODE_H
#define NODE_H

//=================================
// forward declared dependencies


//=================================
// included dependencies
#include "Sorted_List.h"

//=================================

class Node : public Sorted_List  {
public:
  Node() = default;
  Node(double value_, Node* next_node_)
  : value{value_}, next_node{next_node_}  {}
  Node(Node const & old_node);
  Node& operator=(Node const&);
  virtual ~Node() {}

  virtual bool is_empty() const;

  double value{};
  Node* next_node{};

};
#endif
