# SAI [ 3 Sep 2009 ]
INC = 
LIB = 

OBJ = .Main.o \
      .InputReader.o

test: $(OBJ)
	g++ -o $@ -g -O3 $(OBJ) $(LIB)

.%.o: %.cpp
	g++ -o $@ -g -O3 -c -I. $(INC) $<

clean:
	@ rm -f .*.o test
