#include "BipartitionList.hpp"
#include "BipartitionProfile.hpp"

int *BipHash::numbers ; 


BipartitionProfile::BipartitionProfile(vector<Tree*> trees)
{
  unordered_map<string,int> name2pos; 
  
  vector<string> names = trees[0]->getTaxaNames(); 
  int ctr = 0; 
  for(auto name : names )
    name2pos[name] = ctr++; 

  profile.reserve( 20 * trees.size() * trees[0]->getNumTax()); 

  // some random numbers 
  int *
    randNum = new int[trees[0]->getNumTax()]; 
  for(int i = 0; i < trees[0]->getNumTax(); ++i)
    randNum[i] = rand();   
  BipHash::numbers = randNum; 

  ctr = 0; 
  for (auto thisTree : trees )
    { 
      BipartitionList bl(trees[0]->getNumTax());      
      bl.fillList(*thisTree, name2pos);

      // add to the profile hash 
      for( auto b : bl)
	{ 
	  Bipartition bp (b->size());
	  bp = *b; 

	  auto match = profile.find(bp) ; 
	  if(  match == profile.end()) 
	    {
	      BitSet<bits> *occurenceVector = new BitSet<bits>(trees.size()); 
	      occurenceVector->set(ctr); 
	      profile[bp] = occurenceVector; 
	    }
	  else 	    
	    {
	      BitSet<bits> *occurenceVector = match->second; 
	      occurenceVector->set(ctr); 
	    }
	}
      ctr++; 
    }
 }




ostream&  operator<<(ostream &out, const BipartitionProfile& rhs)
{
  for(auto aPair : rhs.profile) 
    out << aPair.first << " ====> " << *aPair.second << "\tfreq: " << aPair.second->count() << "\ttaxaInSmallPartition: " << aPair.first.count() << endl; 
  return out; 
}

