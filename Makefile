tree.exe : main.cpp tree.o
	g++ -std=c++17 -o tree.exe main.cpp tree.o
	./tree.exe

tree.o : tree.cpp tree.h
	g++ -c -std=c++17 tree.cpp
