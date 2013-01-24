#include "Tree.hpp"

Tree::Tree(int numTax)
  :elemsUsed(0) 
{
  allocatedElems = (TreeElem*) calloc(2 * numTax + 1 ,sizeof(TreeElem));   
}


Tree::~Tree()
{
  free(allocatedElems); 
}


ostream& operator<<(ostream &out, Tree &tree)
{
  
  return out << *(tree.getStart()); 
}
