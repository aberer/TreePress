#include "TreeReader.hpp" 

#include <string>
#include <fstream>


/**
   @brief a brief hack to get the number of trees in the
   file. Assuming one line per tree.
*/
int getNumTreeHelper(const char *fileName)
{
  int result = 0; 
  
  ifstream ifs(fileName); 
  string temp; 
  while(getline(ifs, temp))
    result++; 

  return result; 
}



TreeReader::TreeReader( char *fileName)
{  
  tr = (All*)calloc(1,sizeof(All)); 

  setupTree(tr, fileName);

  fh = myfopen(fileName, "r"); 

  numTax = tr->mxtips; 
  numTrees = getNumTreeHelper(fileName); 
  treesRead = 0; 
}


TreeReader::~TreeReader()
{
  fclose(fh); 
  free(tr->nodep); 
  free(tr);     
  // :TODO: free tree properly 

}



TreeElem* TreeReader::traverseLegacy(All *tr,node* p , Tree &tree )
{
  TreeElem *elem  = tree.getNextElem();
  if(p->number <= tr->mxtips)
    {
      char *tmp = tr->nameList[p->number]; 
      char *tmp2 = (char*)calloc(strlen(tmp),sizeof(char));
      strcpy(tmp2, tmp); 

      elem->label = tmp2;       
    }
  else 
    {
      elem->down[0] = traverseLegacy(tr, p->next->back, tree); 
      elem->down[1] = traverseLegacy(tr, p->next->next->back, tree); 

      elem->down[0]->up = elem; 
      elem->down[1]->up = elem; 
      
      if(p == tr->start->back)
	{
	  TreeElem* elem2 = elem;
	  elem = tree.getNextElem();
	  elem->down[0] = elem2; 
	  elem->down[1] = traverseLegacy(tr, p->back, tree); 
	  
	  elem->down[0]->up = elem; 
	  elem->down[1]->up = elem; 
	}
    }  

  return elem; 
}


void TreeReader::readTree(Tree &tree)
{
  treesRead++;
  readBootstrapTree(tr,fh); 

  tree.setStart( traverseLegacy(tr, tr->start->back, tree)); 
}
