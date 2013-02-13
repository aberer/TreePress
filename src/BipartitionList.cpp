
#include "global.hpp"
#include "BipartitionList.hpp"


BipartitionList::~BipartitionList()
{
  for(auto bip : bipartitions)
    free(bip); 
}


void BipartitionList::fillList(Tree &tree, unordered_map<string,int> posMeaning)
{ 
  bipMeaning.resize(numTax);  
  for(auto elem : posMeaning)
    bipMeaning[elem.second]= elem.first;
  
  TreeElem *tmp = tree.getStart(),
    *clade1 = tmp->down[0],
    *clade2 = tmp->down[1]; 

  extractBip(clade1, posMeaning); 
  extractBip(clade2, posMeaning); 
}


BitSet<bits>* BipartitionList::extractBip(TreeElem *elem, unordered_map<string,int> &posMeaning)
{
  BitSet<bits>* result = nullptr ; 

  if(not elem->isTip() )
    {
      result =  new BitSet<bits>(numTax);

      BitSet<bits> *left = extractBip(elem->down[0],posMeaning),
	*right = extractBip(elem->down[1],posMeaning); 
      
      if(left != nullptr)
	result->orify(*left);  
      else 
	{
	  string tmp = elem->down[0]->label; 
	  result->set(posMeaning[elem->down[0]->label]);
	}

      if(right != nullptr)
	result->orify(*right); 
      else 
	result->set(posMeaning[elem->down[1]->label]); 

      nat numSet  = result->count(); 

      // TODO this is an ugly hack 
      if(NOT (numSet == 1 || numSet == posMeaning.size()-1))
	bipartitions.push_back(result); 
    }
  
  return result; 
} 
