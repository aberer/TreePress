
#include "global.hpp" 
#include "TreeElem.hpp"


ostream& operator<<(ostream& out, TreeElem &elem)
{
  if(elem.isTip())
    return out << elem.label; 
  else
    return out <<  "("  << *(elem.down[0]) << "," <<  *(elem.down[1]) << ")"; 
}
