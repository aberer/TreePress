#include "global.hpp"



void errorExit(int e)
{
  cout << "usage: ./treePress  newickFile" << endl; 
  exit(-e); 
}



FILE *myfopen(const char *path, const char *mode)
{
  FILE *fp = fopen(path, mode);

  if(strcmp(mode,"r") == 0 || strcmp(mode,"rb") == 0)
    {
      if(fp)
	return fp;
      else
	{
	  printf("The file %s you want to open for reading does not exist, exiting ...\n", path);
	  errorExit(-1);
	  return (FILE *)NULL;
	}
    }
  else
    {
      if(fp)
	return fp;
      else
	{	
	  printf("The file %s RAxML wants to open for writing or appending can not be opened [mode: %s], exiting ...\n", path, mode);
	  errorExit(-1);
	  return (FILE *)NULL;
	}
    }


}
