CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = sort_analysis

all: $(TARGET)

$(TARGET): main.cpp ArrayGenerator.h SortAlgorithms.h SortTester.h
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

visualize: run
	python3 visualize.py

clean:
	rm -f $(TARGET) test_quick src/*.csv plots/*.png

.PHONY: all run test visualize clean
