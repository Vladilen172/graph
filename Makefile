CXX = g++
ALL_FLAGS = -std=c++17 -Wall -Wextra -Werror -g
TEST_FLAGS = -lgtest -lpthread
MAIN = src/main.cpp
OUT_FILE = src/graph_program.out
OUT_TEST_FILE = tests/tests.out

all: build test

build:
	$(CXX) $(ALL_FLAGS) $(MAIN) -o $(OUT_FILE)

test:
	$(CXX) -o $(OUT_TEST_FILE) tests/graph_tests.cpp $(TEST_FLAGS)

run: build
	./$(OUT_FILE) src/graph.txt

run_tests: test
	./$(OUT_TEST_FILE)

clean:
	rm -f $(OUT_FILE) $(OUT_TEST_FILE)

.PHONY: all build test clean
