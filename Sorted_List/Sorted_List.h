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
#include "Node.h"
#include <iostream>

//=================================

// Komplettering: h-filen ska ge en snabb överblick över vad som finns i er klass.
//  Därför bör de publika delarna ligga överst.
//  Om ni behöver någon privat del för att deklarera någon publik så kan man
//  fördeklarera (forward declaration).

class Sorted_List {

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
  Sorted_List::Node* ptr_to_first_node{};
};
#endif
