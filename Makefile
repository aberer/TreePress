VERSIONFILE=src/version.hpp
PROGNAME=treePress

include system/Makefile.standard

CC:=$(Q) $(CCACHE) g++ 

SRCDIR:=./src/


# BEGIN customizable stuff 
# mode:=hybrid
FEATURES :=  -D_NOT_PRODUCTIVE -D_OPTIMIZED_FUNCTIONS #  -D_USE_RTS 
WARNING_OFF := -Wno-write-strings -Wno-sign-compare #  -Wno-sign-compare -Wno-strict-prototypes -Wno-missing-prototypes -Wno-old-style-definition -Wno-missing-declarations -Wno-unused-parameter -Wno-unused-function -Wno-redundant-decls
# END 


# DEPS=$(SRCDIR)/ $(SRCDIR)/globalVariables.h
LFLAGS = -lm
OPT :=  -O2 -fomit-frame-pointer -funroll-loops -march=native   
WARN := -Wall -pedantic $(WARNING_OFF) #   -Wunused-parameter -Wredundant-decls  -Wreturn-type  -Wswitch-default -Wunused-value -Wimplicit  -Wimplicit-function-declaration  -Wimplicit-int -Wimport  -Wunused  -Wunused-function  -Wunused-label -Wno-int-to-pointer-cast -Wbad-function-cast  -Wmissing-declarations -Wmissing-prototypes  -Wnested-externs  -Wold-style-definition -Wstrict-prototypes  -Wdeclaration-after-statement -Wpointer-sign -Wextra -Wredundant-decls -Wunused -Wunused-function -Wunused-parameter -Wunused-value  -Wunused-variable -Wformat  -Wformat-nonliteral -Wparentheses -Wsequence-point -Wuninitialized -Wundef -Wbad-function-cast
LANG =   $(WARN)   -std=c++11 # -D_GNU_SOURCE


SRC_EXCLUDE:=%_flymake.cpp %_flymake.hpp %_flymake_master.cpp

CFLAGS:=  $(OPT) $(LANG) $(FEATURES)  # $(VECT_FLAG)
DEBUG_CFLAGS := $(VECT_FLAG) $(LANG) $(FEATURES) -ggdb -D_DEBUG $(WARNING_OFF)


firstTarget : release 


standardTargets : vupdate cmpMessage depend 

.PHONY : clean vupdate cmpMessage

vupdate : 
	@echo "[VERSION]"
	@echo "#define VERSION \"$(NEW_VERSION)\"" > $(VERSIONFILE)

clean:
	@echo "[CLEAN]"
	$(RM) $(OBJDIR) $(TEST_OBJ_DIR) $(DEBUG_OBJ_DIR) $(PROFILE_OBJ_DIR)  $(ALL_TARGETS)  *~ \#* callgrind* cachegrind*  gmon.out 


include system/Makefile.build
include system/Makefile.depend
