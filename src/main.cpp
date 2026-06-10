#include <curses.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <clocale>
#include <codecvt>
#include <locale>

// Reads a UTF-8 file and converts it into wide strings (std::wstring)
std::vector<std::wstring> loadWideWordArt(const std::string& filename) {
    std::vector<std::wstring> lines;
    std::wifstream file(filename);
    
    // Set the file stream to read UTF-8
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

    if (!file.is_open()) {
        return lines; 
    }

    std::wstring line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

int main() {
    std::setlocale(LC_ALL, "");

    std::vector<std::wstring> art = loadWideWordArt("wordart.txt");
    if (art.empty()) {
        std::cerr << "Error: Could not read 'wordart.txt' or file is empty.\n";
        return 1;
    }

    int art_height = static_cast<int>(art.size());
    size_t max_width = 0;
    for (const auto& line : art) {
        if (line.length() > max_width) {
            max_width = line.length();
        }
    }
    int art_width = static_cast<int>(max_width);

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);

    bool running = true;
    while (running) {
        int win_height, win_width;
        getmaxyx(stdscr, win_height, win_width);

        clear();

        int start_y = (win_height - art_height) / 2;
        int start_x = (win_width - art_width) / 2;

        for (int i = 0; i < art_height; ++i) {
            int current_y = start_y + i;
            if (current_y >= 0 && current_y < win_height) {
                mvaddwstr(current_y, start_x, art[i].c_str());
            }
        }

        refresh();

        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            running = false;
        }
    }

    endwin();
    return 0;
}
