#makefile
CFLAGS = -g -Wall

DEPENDS = Johnson.cpp Dijkstra.cpp BellmanFord.cpp FloydWarshall.cpp TestCase.cpp

TARGET = output

FILES = $(wildcard Tests/*.txt)
Mac:
	clang++ -std=c++11 main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)
Win: 
	g++ -std=c++17 main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)
	
run:
	./$(TARGET) $(FILES)

clean:
	@echo "Removing $(TARGET)"
	rm -f $(TARGET)
