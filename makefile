CC = g++
CFLAGS =-I/Construct/constructor.h -I/Eval/evaluator.cpp
all: test
test: test.o
	${CC} ${CFLAGS} -o test test.cpp
test.o: test.cpp
	${CC} -c test.cpp -Wall

clean:
	rm test.o ALU.o constructor.o evaluator.o test
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