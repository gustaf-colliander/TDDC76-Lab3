//=================================
// include guard
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

//=================================
// forward declared dependencies


//=================================
// included dependencies
#include "Sorted_List.h"
#include <string>

//=================================

class Sorted_List : public ListHandler  {
public:
  Sorted_List() = default;
  Sorted_List(std::string infix_expr_);
  Sorted_List(Sorted_List const & old_tree);
  Sorted_List& operator=(Sorted_List const&);

  virtual ~Sorted_List() {}
  virtual double evaluate() const;
  virtual std::string get_postfix() const;
  virtual std::string get_infix() const;
  virtual AbstractNode* clone() const;
  virtual void delete_expr_nodes();
  virtual bool has_variable(Variable*) const;
  virtual bool set_variable_value(Variable*);

  bool empty() const;
  void swap(Sorted_List& Expr);
  void delete_expr(Sorted_List& Expr);

};
#endif
