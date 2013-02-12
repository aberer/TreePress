#pragma once 
#include "global.hpp"
#include "Tree.hpp"
#include "BitSet.hpp"


class BipartitionList
{
public:  
  BipartitionList(int _numTax) : numTax(_numTax){} 
  ~BipartitionList();
  void fillList(Tree& tree, unordered_map<string,int> posMeaning); 
  vector<BitSet<bits>*> getList(){return bipartitions;}  
  vector<string> getMeaning(){return bipMeaning; }

private:
  BitSet<bits>* extractBip(TreeElem *elem, unordered_map<string,int> &posMeaning); 
  vector<BitSet<bits>*> bipartitions;
  vector<string> bipMeaning; 
  int numTax;  
};
