mkdir tmp

g++ -c ./Number/Number.cpp -o ./tmp/Number.o
ar rvs ./tmp/Number.lib ./tmp/Number.o

g++ -c -LNumber ./Vector/Vector.cpp -o ./tmp/Vector.o
g++ -shared -o ./tmp/Vector.dll ./tmp/Vector.o ./tmp/Number.lib
g++ -c -IVector main.cpp -o ./tmp/main.o
g++ ./tmp/Vector.o ./tmp/Number.o ./tmp/main.o -o main

./main

rm -R tmp
pause