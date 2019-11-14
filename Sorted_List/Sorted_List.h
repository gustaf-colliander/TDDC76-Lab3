//=================================
// include guard
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

//=================================
// forward declared dependencies
class Node;

//=================================
// included dependencies
#include "ListHandler.h"

//=================================

class Sorted_List : public ListHandler  {
public:
  Sorted_List() = default;
  //Att göra: lägg till konstruktor som tar ett godtyckligt antal parametrar
  Sorted_List(Sorted_List const & old_list);
  Sorted_List& operator=(Sorted_List const&);
  virtual ~Sorted_List() {}

  virtual void print() const;
  virtual bool remove(int);
  virtual bool remove_all();
  virtual int get_element(int) const;
  virtual int get_length() const;
  virtual bool is_empty() const;

  Node* first_node{};

};
#endif
