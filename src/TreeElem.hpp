#pragma once 


class TreeElem
{  
public: 
  TreeElem()
  {
    down[0] = nullptr; 
    down[1] = nullptr; 
    up  = nullptr; 
  }
  bool isTip(){return down[0] == nullptr && down[1] == nullptr; }

  TreeElem *down[2]; 
  TreeElem *up;
  string label; 
}; 


ostream& operator<<(ostream& out, TreeElem &elem); 

