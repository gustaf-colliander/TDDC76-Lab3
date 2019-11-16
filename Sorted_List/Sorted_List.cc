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
// Sorted_List constructor

//Körs om tom lista skapas
Sorted_List::Sorted_List()
  : first_node{nullptr} {}

//   Lägger in heltalen i initializer_list (sida 110 och 244 i boken) i en vector och sortera vectorn med störst heltal på index 0.
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
// Sorted_List function definitions


void Sorted_List::insert(int element)
{
  Node* current_node{first_node};
  Node* next_node{};
  bool eol{false};

  while (element > current_node->value)
  {
    next_node = current_node->next_node;
    cout << "insatt element större än nuvarande nods element" << endl;
    if (next_node == nullptr)
    {
      cout << "nått slutet på listan. Så element är störst av alla element" << endl;
      eol = true;
      // skapa och insert element korrekt i listan här med nullpekare, och ändra pekare på den noden till vänster så den pekar på nya elementet
      break;
    }
    else
    {
      current_node = next_node;
    }
  }
  if (eol == false)
  {
    cout << "Vi har inte nått slutet på listan än men insatt element större än nuvarande nods element" << endl;
    // skapa och insert element korrekt i listan här med pekare till next_node, och ändra pekare på den noden till vänster så den pekar på nya elementet
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
