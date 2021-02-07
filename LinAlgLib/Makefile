EXECUTABLE = main
PROJECTFILE = main.cpp

CXX = g++

CXXFLAGS = -Wall -Wextra -pedantic

SOURCES     = $(wildcard *.cpp)
OBJECTS     = $(SOURCES:%.cpp=%.o)

# debug: CXXFLAGS += -g3 -DDEBUG
# debug:
# 	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)_debug


$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(PROJECTFILE) -o $(EXECUTABLE)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp


clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(EXECUTABLE)_debug

HEADERS = Matrix.h LinAlg.h
main.o: main.cpp $(HEADERS)