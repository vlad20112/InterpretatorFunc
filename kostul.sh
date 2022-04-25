cd Construct/
g++ -c constructor.cpp
mv constructor.o ../
cd ../
cd Eval/
g++ -c evaluator.cpp
mv evaluator.o ../
cd ../
make
rm constructor.o
rm evaluator.o
rm test.o
