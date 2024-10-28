all: fsrs

fsrs: FitStudioReg.o List.o Member.o
	g++ -Wall -o fsrs FitStudioReg.o List.o Member.o -std=c++11

FitStudioReg.o: FitStudioReg.cpp List.h Member.h
	g++ -Wall -c FitStudioReg.cpp -std=c++11

List.o: List.h List.cpp
	g++ -Wall -c List.cpp -std=c++11

Member.o: Member.h Member.cpp
	g++ -Wall -c Member.cpp -std=c++11

clean:
	rm -f fsrs *.o