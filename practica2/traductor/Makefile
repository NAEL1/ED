SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebatraductor documentacion

# ************ Generación de documentación ******************
documentacion:
	doxygen ./doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/pruebatraductor: $(OBJ)/pruebatraductor.o $(LIB)/libtraductor.a
	$(CXX) -I$(INC) -L$(LIB) $(OBJ)/pruebatraductor.o -ltraductor -o $(BIN)/pruebatraductor

# Creacion de biblioteca

$(LIB)/libtraductor.a: $(OBJ)/traductor.o $(OBJ)/palabra.o
	ar -rvs $(LIB)/libtraductor.a  $(OBJ)/traductor.o $(OBJ)/palabra.o


# Creación de los objetos.

$(OBJ)/palabra.o: $(SRC)/palabra.cpp $(INC)/palabra.h
	$(CXX) $(CPPFLAGS) $(SRC)/palabra.cpp -o $(OBJ)/palabra.o
	
$(OBJ)/traductor.o: $(SRC)/traductor.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) $(SRC)/traductor.cpp -o $(OBJ)/traductor.o

$(OBJ)/pruebatraductor.o: $(SRC)/pruebatraductor.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebatraductor.cpp -o $(OBJ)/pruebatraductor.o
	
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
