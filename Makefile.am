AUTOMAKE_OPTIONS=foreign

WARN_FLAGS=  -Wall --pedantic -Wno-write-strings #  -Wunused-parameter -Wredundant-decls  -Wreturn-type  -Wswitch-default -Wunused-value -Wimplicit  -Wimplicit-function-declaration  -Wimplicit-int -Wimport  -Wunused  -Wunused-function  -Wunused-label -Wno-int-to-pointer-cast -Wbad-function-cast -Wnested-externs  -Wold-style-definition -Wpointer-sign -Wextra -Wredundant-decls -Wunused -Wunused-function -Wunused-parameter -Wunused-value  -Wunused-variable -Wformat  -Wformat-nonliteral -Wparentheses -Wsequence-point -Wuninitialized -Wundef -Wbad-function-cast #   -Wstrict-prototypes   -Wdeclaration-after-statement  -Wmissing-prototypes  
LANG_FLAGS=-std=c++11 # because of asm 

CFLAGS=
CXXFLAGS=

AM_CXXFLAGS=$(OPT_FLAGS) $(WARN_FLAGS) $(LANG_FLAGS)

if WITH_DEBUG
AM_CXXFLAGS+=-g3 -O0
else
AM_CXXFLAGS+=-O2 -fomit-frame-pointer -funroll-loops
endif

treepress_SOURCES=src/BipartitionList.cpp  src/BipartitionProfile.cpp  src/BitSet.cpp  src/global.cpp  src/main.cpp  src/raxmlLegacy.cpp  src/Tree.cpp  src/TreeElem.cpp  src/TreeReader.cpp src/Bipartition.cpp

bin_PROGRAMS=treepress 

include flymake.mk
