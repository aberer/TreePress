#pragma once 

#include "BitSet.hpp" 

// currently only wraps and inverts  


class Bipartition  : public BitSet<bits>
{
public: 
  Bipartition(nat size)
    : BitSet<bits>(size)
  {    
  }

  Bipartition& operator=( const BitSet<bits>& rhs )
  {    
    // TODO all of this is dirty, I know and I am sorry for that 
    
    // assuming that it has been initialized accordingly 
    assert(rhs.size() == this->size());   

    for (nat i = 0; i < internalSize(); ++i )
      bv[i] = rhs.getPart(i); 
    
    if(this->count() > this->size() / 2 
       || ( this->count() == this->size() / 2 && NOT this->test(0) ) )
      this->flip(); 

    return *this; 
  }



  long getHash(const int* const numbers) const
  {
    long result = 0; 
    for(nat i = 0; i < size(); ++i)
      if(test(i))
	result ^= numbers[i]; 
    return result; 
  }
  
  friend bool operator==(const Bipartition& lhs , const Bipartition& rhs); 

};
 
