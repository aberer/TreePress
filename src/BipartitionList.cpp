
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


BitSet<uint64_t>* BipartitionList::extractBip(TreeElem *elem, unordered_map<string,int> &posMeaning)
{
  BitSet<uint64_t>* result = nullptr ; 

  if(not elem->isTip() )
    {
      result =  new BitSet<uint64_t>(numTax);

      BitSet<uint64_t> *left = extractBip(elem->down[0],posMeaning),
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

      bipartitions.push_back(result); 
    }
  
  return result; 
} 
