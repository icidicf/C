CC=gcc
SUBDIRS=f1\
	f2\
	main\
	obj
OBJS=f1.o f2.o main.o
BIN=myapplyp
OBJS_DIR=obj
BIN_DIR=bin
LYP_FLAGS=DY

export CC OBJS BIN OBJS_DIR BIN_DIR LYP_FLAGS
			
all:CHECK_DIR $(SUBDIRS)
CHECK_DIR:
	    mkdir -p $(BIN_DIR)
$(SUBDIRS):ECHO
	    @echo "lyp is  $@"
	    make -C $@
ECHO:
	    @echo $(SUBDIRS)
	    @echo begin compile
CLEAN:
	    @$(RM) $(OBJS_DIR)/*.o
	    @rm -rf $(BIN_DIR)
