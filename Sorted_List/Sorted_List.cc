//=================================
// included dependencies
#include "Sorted_List.h"
#include "Node.h"
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream> //debugging
#include <exception>
using namespace std;


//=================================
// Sorted_List konstruktorer

//Körs om tom lista skapas
Sorted_List::Sorted_List()
: ptr_to_first_node{nullptr} {}

Sorted_List::Sorted_List(initializer_list<int> lst)
{
  for (int element : lst)
  {
  insert(element);
  }
}


// Kopieringskonstruktor
Sorted_List::Sorted_List(Sorted_List const & old_list)
{
  if (!old_list.empty())
  {
    ptr_to_first_node = old_list.ptr_to_first_node->clone();
  }
  else
  {
    ptr_to_first_node = nullptr;
  }
}

// Kopieringstilldelning
Sorted_List& Sorted_List::operator=(Sorted_List const& rhs)
{
  if (this != &rhs)
  {
  clear();
  ptr_to_first_node = rhs.ptr_to_first_node->clone();
  }
  return *this;
}

// Flyttkonstruktor
Sorted_List::Sorted_List(Sorted_List && rhs)
: ptr_to_first_node{rhs.ptr_to_first_node}
{
  rhs.ptr_to_first_node = nullptr;
}

// Flyttilldelning
Sorted_List& Sorted_List::operator=(Sorted_List && rhs)
{
  if (this != &rhs)
  {
  Node* pointer{ptr_to_first_node};
   ptr_to_first_node = rhs.ptr_to_first_node;
   rhs.ptr_to_first_node = pointer;
  }
  return *this;
}



//=================================
// Sorted_List funktioner

void Sorted_List::insert(int element)
{
    if (empty())
    {
      //Listan är tom.
      Node* ins_node{new Node{element, nullptr}};
      ptr_to_first_node = ins_node;
    }
    else if (element <= ptr_to_first_node->value)
    {
      //Insatta noden är minst av alla element i listan.
      Node* ins_node{new Node{element, ptr_to_first_node}};
      ptr_to_first_node = ins_node;
    }
    else
    {
      Node* current_node{ptr_to_first_node};
      Node* ptr_to_next_node{};
      while (element > current_node->value)
      {
        ptr_to_next_node = current_node->ptr_to_next_node;
        if (ptr_to_next_node == nullptr)
        {
          //Insatta noden är störst av alla element i listan.
          Node* ins_node{new Node{element, nullptr}};
          current_node->ptr_to_next_node = ins_node;
          break;
        }
        else if (element <= ptr_to_next_node->value)
        {
          //Insatt nod ligger mellan de två noderna current_node och ptr_to_next_node i listan.
          Node* ins_node{new Node{element, ptr_to_next_node}};
          current_node->ptr_to_next_node = ins_node;
          break;
        }
        else
        {
          current_node = ptr_to_next_node;
        }
      }
    }
}

void Sorted_List::erase(int index)
{
  int N{size()};
  if (empty())
  {
    // FALL 1: borttagning i tom lista.
    throw domain_error("List is empty so we can't remove any elements.");
  }
  else if (index < 0 || index >= N)
  {
    throw out_of_range("Specified index does not belong to the list.");
  }
  else
  {
    Node* current_node{ptr_to_first_node};
    Node* previous_node{};
    for (int i = 1; i <= index; i++)
    {
      previous_node = current_node;
      current_node = current_node->ptr_to_next_node;
    }
    // FALL 2: borttaget element minst av alla element i listan.
    if (index == 0)
    {
      ptr_to_first_node = current_node->ptr_to_next_node;
      delete current_node;
    }
    // FALL 4: borttaget element störst.
    else if (index == N - 1)
    {
      previous_node->ptr_to_next_node = nullptr;
      delete current_node;
    }
    // FALL 3: borttaget element mellan två element.
    else
    {
      previous_node->ptr_to_next_node = current_node->ptr_to_next_node;
      delete current_node;
    }
  }
}

bool Sorted_List::empty() const
{
  return ptr_to_first_node == nullptr;
}

int Sorted_List::size() const
{
  if (empty())
  {
    return 0;
  }
  else
  {
    int count{1};
    Node* ptr_to_next_node{ptr_to_first_node->ptr_to_next_node};

    while (ptr_to_next_node != nullptr)
    {
      count += 1;
      ptr_to_next_node = ptr_to_next_node->ptr_to_next_node;
    }
    return count;
  }
}

int Sorted_List::at(int index) const
{
  int N{size()};
  if (empty())
  {
    throw domain_error("List is empty so we can't access any element.");
  }
  else if (index < 0 || index >= N)
  {
    throw out_of_range("Specified index does not belong to the list.");
  }
  else
  {
    Node* current_node{ptr_to_first_node};
    for (int i = 1; i <= index; i++)
    {
      current_node = current_node->ptr_to_next_node;
    }
    return current_node->value;
  }
  //har return 0 här endast för att undvika kompilatorvarning
  return 0;
}

void Sorted_List::clear()
{
  if (!empty())
  {
    int N{size()};
    Node* ptr_to_next_node{};
    for (int i = 1; i <= N ; i++ )
    {
      ptr_to_next_node = ptr_to_first_node->ptr_to_next_node;
      delete ptr_to_first_node;
      ptr_to_first_node = ptr_to_next_node;
    }
  }
}

ostream& operator<<(ostream& out, const Sorted_List& lst)
{
  int N{lst.size()};
  if (lst.empty())
  {
    out << "{}";
    return out;
  }
  else
  {
    out << '{' << lst.at(0);
    for (int i = 1; i < N; i++)
    {
      out << ", " << lst.at(i);
    }
    out << '}';
    return out;
  }
}
