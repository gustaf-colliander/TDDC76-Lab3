//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Sorted_List.h"
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream> //debugging
using namespace std;




//=================================
// Sorted_List konstruktorer

//Körs om tom lista skapas
Sorted_List::Sorted_List()
: first_node{nullptr} {}

// Kopieringskonstruktor
Sorted_List::Sorted_List(Sorted_List const & old_list)
{
  if (!old_list.empty())
  {
    first_node = old_list.first_node->clone();
  }
  else
  {
    first_node = nullptr;
  }
}

// Kopieringstilldelning
Sorted_List& Sorted_List::operator=(Sorted_List const& rhs)
{
  clear();
  first_node = rhs.first_node->clone();
  return *this;
}

// Flyttkonstruktor
Sorted_List::Sorted_List(Sorted_List && rhs)
: first_node{rhs.first_node}
{
  rhs.first_node = nullptr;
}

// Flyttilldelning
Sorted_List& Sorted_List::operator=(Sorted_List && rhs)
{
  clear();
  first_node = rhs.first_node;
  rhs.first_node = nullptr;
  return *this;
}



//   Lägger in heltalen i initializer_list i en vektor och sortera vektorn så största heltalet är på index 0.
//   Skapa noderna och länka dem samman, låt medlemsvariabeln first_node peka på första noden i kedjan.
Sorted_List::Sorted_List(initializer_list<int> lst)
{
  Node* new_node{};
  Node* previous_node{};
  vector<int> v = lst;
  if (lst.size() > 0)
  {
    sort(v.begin(), v.end(), greater<int>());
    new_node = new Node{v[0], nullptr};
    previous_node = new_node;
    for (unsigned int i=1; i < v.size(); i++)
    {
      new_node = new Node{v[i], previous_node};
      previous_node = new_node;
    }
    first_node = new_node;
  }
  else
  {
    //det här kommer inte hända. Om lst.size() == 0 så körs ju istället default konstruktorn för Sorted_List
  }
}

//=================================
// Sorted_List funktioner

// Kan ta in godtyckligt antal argument. Exempel: insert({5,-3,6,2,9,...})
void Sorted_List::insert(initializer_list<int> lst)
{
  int element{};
  vector<int> v = lst;
  for (unsigned int i = 0; i < v.size(); i++)
  {
    element = v[i];
    if (empty())
    {
      //Listan är tom.
      Node* ins_node{new Node{element, nullptr}};
      first_node = ins_node;
    }
    else if (element <= first_node->value)
    {
      //Insatta noden är minst av alla element i listan.
      Node* ins_node{new Node{element, first_node}};
      first_node = ins_node;
    }
    else
    {
      Node* current_node{first_node};
      Node* next_node{};
      while (element > current_node->value)
      {
        next_node = current_node->next_node;
        if (next_node == nullptr)
        {
          //Insatta noden är störst av alla element i listan.
          Node* ins_node{new Node{element, nullptr}};
          current_node->next_node = ins_node;
          break;
        }
        else if (element < next_node->value)
        {
          //Insatt nod ligger mellan de två noderna current_node och next_node i listan.
          Node* ins_node{new Node{element, next_node}};
          current_node->next_node = ins_node;
          break;
        }
        else
        {
          current_node = next_node;
        }
      }
    }
  }
}

void Sorted_List::erase(int index)
{
  int N{size()};
  if (empty())
  {
    cout << "kastar undantag: tom lista" << endl;
    // FALL 1: borttagning i tom lista.
    // kasta undantag här
  }
  else if (index < 0 || index >= size())
  {
    cout << "kastar undantag: angivet index utanför tillåtna index" << endl;
    // kasta undantag här
  }
  else
  {
    Node* current_node{first_node};
    Node* previous_node{};
    for (int i = 1; i <= index; i++)
    {
      previous_node = current_node;
      current_node = current_node->next_node;
    }
    // FALL 2: borttaget element minst av alla element i listan.
    if (index == 0)
    {
      first_node = current_node->next_node;
      delete current_node;
    }
    // FALL 4: borttaget element störst.
    else if (index == N - 1)
    {
      previous_node->next_node = nullptr;
      delete current_node;
    }
    // FALL 3: borttaget element mellan två element.
    else
    {
      previous_node->next_node = current_node->next_node;
      delete current_node;
    }
  }
}

bool Sorted_List::empty() const
{
  return first_node == nullptr;
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
    Node* next_node{first_node->next_node};

    while (next_node != nullptr)
    {
      count += 1;
      next_node = next_node->next_node;
    }
    return count;
  }
}

int Sorted_List::at(int index) const
{
  if (empty())
  {
    cout << "kastar undantag: tom lista" << endl;
    // kasta undantag här
  }
  else if (index < 0 || index >= size())
  {
    cout << "kastar undantag: angivet index utanför tillåtna index" << endl;
    // kasta undantag här
  }
  else
  {
    Node* current_node{first_node};
    for (int i = 1; i <= index; i++)
    {
      current_node = current_node->next_node;
    }
    return current_node->value;
  }
  //har return 0 temporärt för att undvika jobbig kompilatorvarning
  return 0;
}

void Sorted_List::clear()
{
  if (!empty())
  {
    int N{size()};
    Node* next_node{};
    for (int i = 1; i <= N ; i++ )
    {
      next_node = first_node->next_node;
      delete first_node;
      first_node = next_node;
    }
  }
}


ostream& operator<<(ostream& out, const Sorted_List& lst)
{
  if (lst.empty())
  {
    out << "{}";
    return out;
  }
  else
  {
    out << '{' << lst.at(0);
    for (int i = 1; i < lst.size(); i++)
    {
      out << ", " << lst.at(i);
    }
    out << '}';
    return out;
  }
}
