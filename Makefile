CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
TARGET = main
SRC = src/mutex.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
