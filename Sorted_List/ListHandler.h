//=================================
// include guard
#ifndef LISTHANDLER_H
#define LISTHANDLER_H

//=================================
// forward declared dependencies


//=================================
// included dependencies


//=================================

class ListHandler{
public:
  ListHandler() = default;
  ListHandler(ListHandler const &);
  ListHandler& operator= (ListHandler const& rhs);
  virtual ~ListHandler()
    {}


};
#endif
