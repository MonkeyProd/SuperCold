g++ -I include src/*.cpp $(pkg-config --libs --cflags sfml-window sfml-system sfml-graphics) -o main.out
