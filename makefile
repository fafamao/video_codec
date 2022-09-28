CXX=g++
RM=rm -rf ./out/*

clean:
	$(RM)

build: main.cpp
	$(CXX) -o ./out/codec main.cpp