lab3: ShelterBST.o lab3.o 
	g++ lab3.o ShelterBST.o -o lab3 

lab3.o: lab3.cpp ShelterBST.h 
	g++ -c -Wall -Werror -pedantic -std=c++11 lab3.cpp 

ShelterBST.o : ShelterBST.h ShelterBST.cpp 
	g++ -c -Wall -Werror -pedantic -std=c++11 ShelterBST.cpp 
