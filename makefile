#makefile
CFLAGS = -g -Wall

DEPENDS = Johnson.cpp Dijkstra.cpp BellmanFord.cpp FloydWarshall.cpp TestCase.cpp

TARGET = output

FILES = $(wildcard negNotSparseFalse/*.txt) $(wildcard negNotSparseTrue/*.txt) $(wildcard negSparseFalse/*.txt) $(wildcard negSparseTrue/*.txt) $(wildcard posNotSparseFalse/*.txt) $(wildcard posNotSparseTrue/*.txt) $(wildcard posSparseFalse/*.txt) $(wildcard posSparseTrue/*.txt)

graphs:
	g++ -std=c++17 GraphGenerator.cpp -o testCases
	./testCases

Mac:
	clang++ -std=c++11 main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)
Win: 
	g++ -std=c++17 main.cpp $(CFLAGS) $(DEPENDS) -o $(TARGET)

run: 
	./$(TARGET) $(FILES)


clean:
	@echo "Removing $(TARGET)"
	rm -f $(TARGET)
	#rm -f $(FILES)
