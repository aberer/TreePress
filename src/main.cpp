#include "global.hpp"
#include "BipartitionList.hpp"
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
  
  // printing the tree works in principle, but we do not get the
  // raxml-style unrooted format again 
  Tree &thisTree = *(trees[0]); 
  cout << thisTree << endl; 

  // extract a mapping of taxon names to bitset position (reuse that!)
  unordered_map<string,int> name2pos ; 
  vector<string> names = thisTree.getTaxaNames(); 
  int ctr = 0; 
  for(auto name : names )
    name2pos[name] = ctr++; 
  
  // now we can extract bipartitions (efficiently enough) from the tree  
  BipartitionList bl(thisTree.getNumTax()); 
  bl.fillList(thisTree, name2pos);

  for(auto bip : bl.getList()) 
    cout <<  *bip << endl; 

  return EXIT_SUCCESS; 
}
