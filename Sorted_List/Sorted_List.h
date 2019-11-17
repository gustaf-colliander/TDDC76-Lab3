//=================================
// include guard
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <string>
#include <initializer_list>
#include <iostream>

//=================================

class Sorted_List {


private:
  class Node {
  public:
    Node() = default;
    Node(int value_, Node* next_node_)
    : value{value_}, next_node{next_node_}  {}
    Node(Node const & old_node);
    Node& operator=(Node const&);
    ~Node() {}

    Node* clone() const
    {
      if (next_node != nullptr)
      {
        return new Node{value, next_node->clone()};
      }
      else
      {
        return new Node(value, nullptr);
      }
    }

    int value{};
    Node* next_node{};
  };

public:
  Sorted_List();
  Sorted_List(std::initializer_list<int>);
  Sorted_List(Sorted_List const & old_list);
  Sorted_List& operator=(Sorted_List const& rhs);
  Sorted_List(Sorted_List && rhs);
  Sorted_List& operator=(Sorted_List && rhs);

  // Destruktor: tar bort alla Noder (minnesläckor) m.h.a. clear().
  // Destruktorn anropas då Sorted_List går ur sin scope {} eller om delete Sorted_List* körs.
  ~Sorted_List() {clear();}


  void insert(std::initializer_list<int>);
  void erase(int);
  void clear();
  int at(int) const;
  bool empty() const;
  int size() const;

  friend std::ostream& operator<<(std::ostream& out, const Sorted_List& lst);


private:
  Node* first_node{};


};
#endif
