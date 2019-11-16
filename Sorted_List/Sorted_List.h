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

    int value{};
    Node* next_node{};
  };

public:
  Sorted_List();
  Sorted_List(std::initializer_list<int> lst);
  Sorted_List(Sorted_List const & old_list);
  Sorted_List& operator=(Sorted_List const&);
  ~Sorted_List() {}


  void insert(int);
  bool erase(int);
  void clear();
  int at(int) const;
  bool empty() const;
  int size() const;

  //Invänta svar på mail från Eric. Print kanske borde ersättas med operatorn <<
  void print() const;


private:
  Node* first_node{};


};
#endif
