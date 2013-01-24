#include "global.hpp"
#include "TreeElem.hpp"

class Tree
{
public: 
  Tree(int numTax); 
  ~Tree(); 
  TreeElem* getNextElem(){return &(allocatedElems[elemsUsed++]); } 
  TreeElem* getStart(){return start;} 
  void setStart(TreeElem *_start){start = _start; }

private: 
  TreeElem *allocatedElems; 
  int elemsUsed;   
  TreeElem* start; 
}; 



ostream& operator<<(ostream &out, Tree &tree);
