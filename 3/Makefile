main:$(patsubst %.cpp,%.o,$(wildcard *.cpp))
	g++ -g *.o -o main
%.o:%.cpp
	g++ -c $*.cpp -o $*.o
.PHONY:clean
clean:
	del -f *.o;del main.exe