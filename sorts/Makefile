BINARIES:=exchange selection bubble merge quick
LIBRARIES:=subroutine
CMPLR:=gcc
CMMN_OPTS:=-std=c99
CMPL_OPTS:=-I"inc"
LINK_OPTS:=-L"lib"
OBJ:=obj
BIN:=bin
LIB:=lib
SRC:=src
INC:=inc

LIB_BINDS:=$(patsubst %,-l%,$(LIBRARIES))
LIB_HEADERS:=$(patsubst %,$(INC)/%.h,$(LIBRARIES))
LIB_NAMES:=$(patsubst %,lib%,$(LIBRARIES))
LIB_FILES:=$(patsubst %,$(LIB)/lib%.a,$(LIBRARIES))
CMPL_OPTS:=$(CMMN_OPTS) $(CMPL_OPTS)
LINK_OPTS:=$(CMMN_OPTS) $(LINK_OPTS)

.PHONY: all clean libs bins report_libs
.PRECIOUS: $(OBJ)/lib%.o $(OBJ)/%.o $(LIB)/lib%.a $(BIN)/%

all: bins

libs: report_libs $(LIB_FILES)

report_libs:
	@echo "lib names : $(LIB_NAMES)"
	@echo "lib headers : $(LIB_HEADERS)"
	@echo "lib files : $(LIB_FILES)"

bins: $(BINARIES)

clean:
	rm -rf $(OBJ) $(BIN) $(LIB)

%: $(BIN)/%
	@echo "MADE $@"

$(BIN)/%: $(OBJ)/%.o $(LIB_FILES)
	@if [ ! -d ./$(BIN)/ ] ; then echo "mkdir $(BIN)"; mkdir $(BIN) ; fi
	$(CMPLR) $(LINK_OPTS) -o $@ $< -L. $(LIB_BINDS) -Wl,-rpath,.

$(LIB)/lib%.a: $(OBJ)/lib%.o
	@if [ ! -d ./$(LIB)/ ] ; then echo "mkdir $(LIB)"; mkdir $(LIB) ; fi
	ar cr $@ $<
	ranlib $@

$(OBJ)/%.o: $(SRC)/%.c $(LIB_HEADERS)
	@if [ ! -d ./$(OBJ)/ ] ; then echo "mkdir $(OBJ)"; mkdir $(OBJ) ; fi
	$(CMPLR) $(CMPL_OPTS) -c -o $@ $<

$(OBJ)/lib%.o: $(SRC)/%.c $(INC)/%.h
	@if [ ! -d ./$(OBJ)/ ] ; then echo "mkdir $(OBJ)"; mkdir $(OBJ) ; fi
	$(CMPLR) $(CMPL_OPTS) -c -o $@ $<
