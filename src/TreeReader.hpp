#pragma once 

#include "global.hpp"
#include "raxmlLegacy.hpp"
#include "Tree.hpp"


class TreeReader
{
public: 
  TreeReader( char *fileName); 
  ~TreeReader(); 
  void readTree(Tree &tree);
  bool hasMoreTrees(){return treesRead < numTrees; }
  int getNumTax(){return numTax; }

private: 
  TreeElem* traverseLegacy(All *tr,node* p , Tree &tree ); 

  int numTrees; 
  int treesRead; 
  int numTax; 			// NOTICE all our trees need to have the same number of taxa  
  FILE *fh; 
  All *tr ; 
}; 
