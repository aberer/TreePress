#include "global.hpp"
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

  Tree &treeHere = *(trees[0]); 
  cout << treeHere << endl; 

  // int i = 0 ;
  // for(Node *node : treeHere.getNodes()) 
  // for(i = 0; i < 150; ++i)
  //   {
  //     Node *node = treeHere.getNode(i); 
  //     printf( "%s\n" , node->name); 
  //   }


  return EXIT_SUCCESS; 
}



