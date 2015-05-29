all: test
test: graph.o main.o dijkstra.o bellmanford.o
	g++ graph.o main.o dijkstra.o bellmanford.o -o test
graph.o: graph.cc graph.h
	g++ -c graph.cc
main.o: main.cc
	g++ -c main.cc
dijkstra.o: dijkstra.cc dijkstra.h
	g++ -c dijkstra.cc
bellmanford.o: bellmanford.cc bellmanford.h
	g++ -c bellmanford.cc
