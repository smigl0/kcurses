win:
	x86_64-w64-mingw32-g++ -I. -o logo.exe logo.cpp -L. -l:pdcurses.a
all:
	g++ -I. -o logo logo.cpp -lncurses
