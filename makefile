#makefile
CFLAGS = -g -Wall

DEPENDS = Johnson.cpp Dijkstra.cpp BellmanFord.cpp FloydWarshall.cpp TestCase.cpp

TARGET = output

FILES = $(wildcard nNotSparseFalse/*.txt) $(wildcard nNotSparseTrue/*.txt) $(wildcard nSparseFalse/*.txt) $(wildcard nSparseTrue/*.txt) $(wildcard pNotSparseFalse/*.txt) $(wildcard pNotSparseTrue/*.txt) $(wildcard pSparseFalse/*.txt) $(wildcard pSparseTrue/*.txt)

DIRECT = nNotSparseFalse nNotSparseTrue nSparseFalse nSparseTrue pNotSparseFalse pNotSparseTrue pSparseFalse pSparseTrue

graphs:
	mkdir $(DIRECT)
	g++ -std=c++11 GraphGenerator.cpp -o testCases
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
	rm -rf $(DIRECT)
