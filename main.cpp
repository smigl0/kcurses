#pragma clang diagnostic ignored "-Wformat"

#include <ncurses.h>
#include <locale.h>
#include <fmt/format.h>
#include <fmt/xchar.h>
int main(void){
    
    setlocale(LC_ALL,"");


    initscr();
    noecho();
    curs_set(0);
    
    int maxX = getmaxx(stdscr);
    int maxY = getmaxy(stdscr);

    int block1 = L'\u2581';
    std::wstring mesg1;

    for(int i=0;i<8;i++){
        mesg1= fmt::format(L"{}",static_cast<wchar_t>(block1+i));
        mvaddwstr(1,1+i,mesg1.c_str());
    } 

    refresh();

    getch();
    endwin();
    return 0;
}
