#include "BitSet.hpp" 

// currently only wraps and inverts  


class Bipartition
{
public: 
  Bipartition(BitSet<uint32_t> *_bip)
    : bip(_bip)
  {
    
  }


  ~Bipartition()
  {
    delete bip; 
  } 
  
  private: 
  BitSet<bits> *bip; 
  
}; 
