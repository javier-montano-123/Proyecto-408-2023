CC = g++
CFLAGS = -Wall -std=c++11
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Nombres de los ejecutables de los tests
TESTS = test1 test2 test3 test4 test5 test6

# Archivos fuente y de código de cada test
TEST_SOURCES = $(wildcard test*.cc)
BD_SOURCE = bd.cc

all: $(TESTS)

$(TESTS): $(TEST_SOURCES) $(BD_SOURCE)
	$(CC) $(CFLAGS) $(filter $@.cc,$(TEST_SOURCES)) $(BD_SOURCE) -o $@ $(GTEST_FLAGS)

test%: %
	./$<

clean:
	rm -f $(TESTS)

