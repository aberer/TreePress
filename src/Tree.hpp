#pragma once 
#include "global.hpp"
#include "TreeElem.hpp"

class Tree
{
public: 
  Tree(int numTax); 
  TreeElem* getNextElem(){return &(allocatedElems[elemsUsed++]); } 
  int getNumTax(){return numTax;}
  TreeElem* getStart(){return start;} 
  void setStart(TreeElem *_start){start = _start; }
  vector<string> getTaxaNames();

private: 
  int elemsUsed;   
  int numTax; 
  vector<TreeElem> allocatedElems; 
  TreeElem* start; 
}; 



ostream& operator<<(ostream &out, Tree &tree);


