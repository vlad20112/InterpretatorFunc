cd Construct/
g++ -c constructor.cpp
mv constructor.o ../
cd ../
cd EvalSrc/
g++ -c ALU.cpp
mv ALU.o ../
cd ../
cd EvalSrc/
g++ -c evaluator.cpp
mv evaluator.o ../
cd ../
make