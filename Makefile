COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++14
INCLUDE_DIRECTORY = -I. -I./srcgen
COMPILE = $(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_DIRECTORY) -c
LINK = $(COMPILER) $(COMPILER_FLAGS) -o

default: cppa2z

run:
	./cppa2z
	
cppa2z: main.o non_modifying_sequence.t.o modifying_sequence.t.o partitioning.t.o sorting.t.o binary_search.t.o set_operations.t.o heap.t.o min_max.t.o permutation.t.o	numeric_operations.t.o iterator_adaptors.t.o stream_iterators.t.o iterator_operations.t.o parse_util.t.o parse_util.o
	$(LINK) cppa2z main.o non_modifying_sequence.t.o modifying_sequence.t.o  partitioning.t.o sorting.t.o binary_search.t.o set_operations.t.o heap.t.o min_max.t.o permutation.t.o numeric_operations.t.o iterator_adaptors.t.o stream_iterators.t.o iterator_operations.t.o parse_util.t.o parse_util.o

	./cppa2z

main.o: main.cpp
	$(COMPILE) main.cpp

#
# algorithms
#
non_modifying_sequence.t.o: ./algorithms/non_modifying_sequence.t.cpp
	$(COMPILE) ./algorithms/non_modifying_sequence.t.cpp

modifying_sequence.t.o: ./algorithms/modifying_sequence.t.cpp
	$(COMPILE) ./algorithms/modifying_sequence.t.cpp

partitioning.t.o: ./algorithms/partitioning.t.cpp
	$(COMPILE) ./algorithms/partitioning.t.cpp

sorting.t.o: ./algorithms/sorting.t.cpp
	$(COMPILE) ./algorithms/sorting.t.cpp

binary_search.t.o: ./algorithms/binary_search.t.cpp
	$(COMPILE) ./algorithms/binary_search.t.cpp

set_operations.t.o: ./algorithms/set_operations.t.cpp
	$(COMPILE) ./algorithms/set_operations.t.cpp

heap.t.o: ./algorithms/heap.t.cpp
	$(COMPILE) ./algorithms/heap.t.cpp

min_max.t.o: ./algorithms/min_max.t.cpp
	$(COMPILE) ./algorithms/min_max.t.cpp

permutation.t.o: ./algorithms/permutation.t.cpp
	$(COMPILE) ./algorithms/permutation.t.cpp

numeric_operations.t.o: ./algorithms/numeric_operations.t.cpp
	$(COMPILE) ./algorithms/numeric_operations.t.cpp

#
# iterators
#
iterator_adaptors.t.o: ./iterators/iterator_adaptors.t.cpp
	$(COMPILE) ./iterators/iterator_adaptors.t.cpp

stream_iterators.t.o: ./iterators/stream_iterators.t.cpp
	$(COMPILE) ./iterators/stream_iterators.t.cpp

iterator_operations.t.o: ./iterators/iterator_operations.t.cpp
	$(COMPILE) ./iterators/iterator_operations.t.cpp

#
# strgen
#
parse_util.o: ./srcgen/parse_util.h ./srcgen/parse_util.cpp
	$(COMPILE) ./srcgen/parse_util.cpp

parse_util.t.o: ./srcgen/parse_util.h ./srcgen/parse_util.t.cpp
	$(COMPILE) ./srcgen/parse_util.t.cpp


.PHONY: clean
clean:
	$(RM) cppa2z *.o

