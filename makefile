CC = g++
CFLAGS =-I/Construct/constructor.h -I/Eval/evaluator.cpp -I/Libs/operations.cpp

all: test.exe
test: test.o
	${CC} ${CFLAGS} -o test.exe test.cpp
test.o: test.cpp
	${CC} -c test.cpp -Wall

test_comb: test_combinator.o operations.o
	${CC} ${CFLAGS} -o test_comb.exe test_combinator.cpp operations.o -Wall
test_combinator.o: test_combinator.cpp
	${CC} -c test_combinator.cpp -Wall

operations.o:
	cd Libs/
	${CC} -c operations.cpp -Wall
	mv operations.o ../
	cd ../
clean:
	rm test.o ALU.o constructor.o evaluator.o test.exe
clean_test:
	rm combinator test_combinator.o operations.o test_comb.exe
object_files: obj-m := constructor.o evaluator.o  

constructor.o:
	cd Construct/
	${CC} -c constructor.cpp
	mv constructor.o ../
	cd ../
evaluator.o:
	cd Eval/
	${CC} -c evaluator.cpp
	mv evaluator.o ../
	cd ../