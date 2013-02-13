#include "global.hpp"
#include "BipartitionProfile.hpp"
#include "TreeReader.hpp"



int main(int argc, char* argv[])
{
  if(argc != 2 )
    errorExit(-1); 

  TreeReader
    tr = TreeReader(argv[1]); 
  
  vector<Tree*> trees; 

  while(tr.hasMoreTrees())
    {
      Tree *tmp =  new Tree(tr.getNumTax());
      tr.readTree(*tmp); 
      trees.push_back(tmp); 
    }  


  BipartitionProfile bipProfile(trees); 
  cout << bipProfile << endl; 

  
  return EXIT_SUCCESS; 
}
