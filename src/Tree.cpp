#include "Tree.hpp"

Tree::Tree(int _numTax)
  :elemsUsed(0)
  , numTax(_numTax)
  , allocatedElems(2*numTax+1)
{
}


ostream& operator<<(ostream &out, Tree &tree)
{
  
  return out << *(tree.getStart()); 
}


void nameExtractionHelper(TreeElem* elem, vector<string> &names)
{
  if( elem->isTip())
    names.push_back(string(elem->label));
  else 
    {
      nameExtractionHelper(elem->down[0], names);
      nameExtractionHelper(elem->down[1],names);
    }
}


vector<string> Tree::getTaxaNames()
{
  vector<string> result; 
  
  nameExtractionHelper(start, result); 
  assert(result.size() == numTax); 
  
  return result; 
}
