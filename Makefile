PROJECT = bmp

LIBPROJECT = $(PROJECT).a

OBJECTS = main.o BMP_reader.o Turn.o Gaus_filter.o

DEPS = (wildcard *.hpp)

A = ar

AFLAGS = rsv

CXX = g++

CXXFLAGS = -I. -std=c++17 -Werror -Wpedantic -Wall -g -fPIC

LDXXFLAGS = $(CXXFLAGS) -L. -l:$(LIBPROJECT)

.PHONY: default

default: all;

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
$(LIBPROJECT): $(OBJECTS)
	$(A) $(AFLAGS) $@ $^
	
$(PROJECT): main.o $(LIBPROJECT)
	$(CXX) -o $@ main.o $(LDXXFLAGS)

all: $(PROJECT)

.PHONY: clean

clean:
	rm -f *.o

cleanimage:
	rm -f RotatedClockwise.bmp RotatedCounterClockwise.bmp GausFilter.bmp
	
cleanall: clean cleanimage
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	
