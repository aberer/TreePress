


class TreeElem
{  
public: 
  bool isTip(){return down[0] == nullptr && down[1] == nullptr; }
  TreeElem *down[2]; 
  TreeElem *up;
  char *label;   
}; 


ostream& operator<<(ostream& out, TreeElem &elem); 

