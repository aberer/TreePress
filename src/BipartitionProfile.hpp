#pragma once 

#include <vector>
#include <unordered_map>

#include "Bipartition.hpp"
#include "Tree.hpp"


class BipHash
{
public: 

  long operator() (const Bipartition &bip ) const
  {
    return bip.getHash(numbers);
  }
  
  static int* numbers;
}; 


class BipartitionProfile
{
public:
  BipartitionProfile(vector<Tree*> trees);
  ~BipartitionProfile(){}; 
  
  friend ostream&  operator<<(ostream &out, const BipartitionProfile& rhs) ;

private:  
  unordered_map<Bipartition, BitSet<bits>*, BipHash>  profile; 
  
}; 



