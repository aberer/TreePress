#include "Bipartition.hpp"



bool operator==(const Bipartition& lhs , const Bipartition& rhs)
{
  const BitSet<bits> *a = &lhs,
    *b = &rhs; 
  
  assert(a->internalSize() == b->internalSize()); 
  for(nat i = 0; i < a->internalSize() ;++i)
    if(a->getPart(i) != b->getPart(i))
      return false;
  return true; 
}
