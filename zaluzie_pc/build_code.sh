g++ -c ../libraries/shutter_unit/*.cpp
g++ -c main.cpp
g++ *.o -o main
rm *.o

