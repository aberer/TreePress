#pragma once 



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>


#include <sys/times.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <unistd.h>



typedef char boolean;

/* GENERAL  */
#define NOT ! 
#define TRUE             1
#define FALSE            0
#define CALLOC(num, size) calloc(num, size)
#define ABS(x)    (((x)<0)   ?  (-(x)) : (x))
#define FOR_0_LIMIT(iter,limit) for(iter=0;iter < (limit); iter++)
#define FOR_N_LIMIT(iter,n,limit) for(iter=(n); iter < (limit); iter++)
#define PR printBothOpen
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#define USE_UPPER_TRIANGLE_LSI(matrix,a,b,c) (matrix[a][b][(c)-(b)])
#define USE_UPPER_TRIANGLE_TII(matrix,x,y) (matrix[(x)][(y-x)]) /* assumes that x < y */
#define MIN(a,b) (((a) > (b)) ? (b) : (a))
#define MAX(a,b) (((a) < (b)) ? (b) : (a))

#define GET_FROM_UPPER_TRIANGLE(matrix,a,b,c) ((b<c) ? matrix[a][b][(c)-(b)] : matrix[a][c][(b)-(c)])


#define NUM_BRANCHES   128
#define MASK_LENGTH 32


typedef struct ent
{
  unsigned int *bitVector;
  unsigned int *treeVector;
  unsigned int amountTips;
  int *supportVector;
  unsigned int bipNumber;
  unsigned int bipNumber2;
  unsigned int supportFromTreeset[2]; 
  struct ent *next;
} entry;

typedef struct
{
  unsigned int *vector; 
  int support;   
  struct noderec *oP;
  struct noderec *oQ;
} branchInfo;

typedef  struct noderec
{
  unsigned int    isPresent[NUM_BRANCHES / MASK_LENGTH];
  struct noderec  *backs[NUM_BRANCHES];
  char            xs[NUM_BRANCHES];
  branchInfo      *bInf;
  double           z[NUM_BRANCHES];
  struct noderec  *next;
  struct noderec  *back;
  unsigned int   hash;
  int              support;
  int              number;
  char             x;
  double **insertionLWs;
} node, *nodeptr;

typedef struct stringEnt
{
  int nodeNumber;
  char *word;
  struct stringEnt *next;
} stringEntry ;

typedef struct
{
  unsigned int tableSize;
  stringEntry **table;
}  stringHashtable;


typedef struct _All
{
  nodeptr start;
  int mxtips;
  int numberOfTrees;
  int bitVectorLength;
  nodeptr *nodep;
  int ntips;
  int nextnode; 
  int numBranches;
  boolean partitionSmoothed[NUM_BRANCHES];
  boolean rooted;
  stringHashtable *nameHash;
  boolean grouped;
  int *constraintVector;
  char **nameList;
  char *tree_string;
  int treeStringLength;
  double fracchange;
} All;

typedef struct
{
  unsigned int tableSize;
  entry **table;
  unsigned int entryCount;
}  hashtable;


#define FC_INIT               20
#define zmin       1.0E-15  /* max branch prop. to -log(zmin) (= 34) */
#define NO_BRANCHES      -1

#define BIPARTITIONS_ALL       0
#define GET_BIPARTITIONS_BEST  1
#define DRAW_BIPARTITIONS_BEST 2
#define BIPARTITIONS_BOOTSTOP  3
#define BIPARTITIONS_RF  4
#define defaultz       0.9         /* value of z assigned as starting point */
#define nmlngth        1024         /* number of characters in species name */
#define VECTOR_LENGTH (NUM_BRANCHES / MASK_LENGTH)

void bitVectorInitravSpecial(unsigned int **bitVectors, nodeptr p, int numsp, unsigned int vectorLength, hashtable *h, int treeNumber, int function, branchInfo *bInf, int *countBranches, int treeVectorLength, boolean traverseOnly, boolean computeWRF);
hashtable *initHashTable(unsigned int n);
void freeHashTable(hashtable *h);
// ProfileElem *addProfileElem(entry *helem, int vectorLength, int treeVectorLength, int numberOfTrees) ;


// BitVector *neglectThoseTaxa(All *tr, char *toDrop);
void pruneTaxon(All *tr, unsigned int k, boolean considerBranchLengths);
// BitVector **initBitVector(All *tr, BitVector *vectorLength);



boolean setupTree (All *tr, char *bootstrapFile); 

void readBootstrapTree(All *tr, FILE *file); 


char *writeTreeToString(All *tr, boolean printBranchLengths); 
