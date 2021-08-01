#makefile
CFLAGS = -g -Wall

DEPENDS = Johnson.cpp Dijkstra.cpp BellmanFord.cpp FloydWarshall.cpp TestCase.cpp

TEST = TestSet.txt

TARGET = output

Mac:
	clang++ -std=c++11 main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)
Win: 
	g++ -std=c++17 main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)
	
run:
	./$(TARGET) $(TEST)

clean:
	@echo "Removing $(TARGET)"
	rm -f $(TARGET)
