#makefile
CFLAGS = -g -Wall

DEPENDS = Johnson.cpp Dijkstra.cpp BellmanFord.cpp FloydWarshall.cpp

TEST = TestSet.txt

TARGET = output

Mac:
	clang main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)
Win: 
	g++ main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)
	
run:
	./$(TARGET) $(TEST)

clean:
	@echo "Removing $(TARGET)"
	rm -f $(TARGET)