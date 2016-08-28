.PHONY: all clean

CMPLR=gcc
OPTS=-std=c99 -I"inc" -L"lib"
LIB_NAME=subtrn
OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=inc

all: alldirs lib$(LIB_NAME) exchange selection

clean:
	rm -rf $(OBJ) $(BIN) $(LIB)

alldirs: dir_bin dir_lib dir_obj

dir_bin:
	mkdir -p $(BIN)

dir_lib:
	mkdir -p $(LIB)

dir_obj:
	mkdir -p $(OBJ)

exchange: $(BIN)/exchange

selection: $(BIN)/selection

lib$(LIB_NAME): $(LIB)/lib$(LIB_NAME).a

$(LIB)/lib$(LIB_NAME).a: $(OBJ)/lib$(LIB_NAME).o dir_lib
	ar cr $(LIB)/lib$(LIB_NAME).a $(OBJ)/lib$(LIB_NAME).o
	ranlib $(LIB)/lib$(LIB_NAME).a

$(OBJ)/lib$(LIB_NAME).o: $(SRC)/subroutine.c $(INC)/subroutine.h dir_obj
	$(CMPLR) $(OPTS) -c -o $(OBJ)/lib$(LIB_NAME).o $(SRC)/subroutine.c

$(BIN)/exchange: $(OBJ)/exchange.o lib$(LIB_NAME) dir_bin
	$(CMPLR) $(OPTS) -o $(BIN)/exchange $(OBJ)/exchange.o -L. -l$(LIB_NAME) -Wl,-rpath,.

$(OBJ)/exchange.o: $(SRC)/exchange.c dir_obj
	$(CMPLR) $(OPTS) -c -o $(OBJ)/exchange.o $(SRC)/exchange.c

$(BIN)/selection: $(OBJ)/selection.o lib$(LIB_NAME) dir_bin
	$(CMPLR) $(OPTS) -o $(BIN)/selection $(OBJ)/selection.o -L. -l$(LIB_NAME) -Wl,-rpath,.

$(OBJ)/selection.o: $(SRC)/selection.c dir_obj
	$(CMPLR) $(OPTS) -c -o $(OBJ)/selection.o $(SRC)/selection.c

