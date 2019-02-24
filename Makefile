
all:
	g++ --std=c++11 src/*.cpp -lncurses -o snake

pot:
	xgettext --keyword=_ --language=C++ --add-comments --sort-output -o po/snake.pot src/*.cpp src/*.hpp

clean:
	rm snake
