
all:
	g++ -c Mundo.cpp -o Mundo.o
	g++ -c Agente.cpp -o Agente.o
	g++ -c Walls.cpp -o Walls.o
	g++ -c Agente.o Presa.cpp -o Presa.o
	g++ -c Agente.o Predador.cpp -o Predador.o
	g++ main.cpp Presa.o Predador.o Walls.o Agente.o Mundo.o -o main.exe

run:
	./main.exe

clean:
	rm *.o
	rm *.exe
	rm *.txt
	
