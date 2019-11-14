//=================================
// include guard
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <string>

//=================================

class Sorted_List {


private:
  class Node {
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

public:
  Sorted_List() = default;
  //Att göra: lägg till konstruktor som tar ett godtyckligt antal parametrar och gör om till sträng och skickar till ListHandler konstruktor
  // tips: använd initializer_list som konstruktor-argument. Se sida 244 boken

  Sorted_List(Sorted_List const & old_list);
  Sorted_List& operator=(Sorted_List const&);
  virtual ~Sorted_List() {}

  virtual void print() const;
  virtual bool remove(int);
  virtual bool remove_all();
  virtual int get_element(int) const;
  virtual int get_length() const;
  virtual bool is_empty() const;

  std::string input{"1 7 3 2 5"};
  Node* first_node{};


};
#endif
