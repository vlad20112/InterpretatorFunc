CC = g++
all: test
test: test.o
	${CC} -o test test.o constructor.o evaluator.o 
test.o: test.cpp
	${CC} -c test.cpp
constructor.o:
	cd Construct/
	${CC} -c constructor.cpp
	mv constructor.o ../
	cd ../
ALU.o:
	cd EvalSrc/
	${CC} -c ALU.cpp
	mv ALU.o ../
	cd ../
evaluator.o:
	cd EvalSrc/
	${CC} -c evaluator.cpp
	mv evaluator.o ../
	cd ../
clean:
	rm test.o ALU.o constructor.o evaluator.o test