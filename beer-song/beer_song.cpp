#include "beer_song.h"

namespace beer_song {

// TODO: add your solution here

std::string verse(const int v_nr) {
    std::string result {};
    if (v_nr == 0) {
        result = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n";
    }else if (v_nr == 1){
        result = "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n";
    }else if (v_nr == 2) {
        result = "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n";
    }
    else {
        result  = std::to_string(v_nr) + " bottles of beer on the wall, " + std::to_string(v_nr) + " bottles of beer.\nTake one down and pass it around, " + std::to_string(v_nr - 1) + " bottles of beer on the wall.\n";


    }
        return result;
}

std::string sing(int start, int end) {
    std::string result;
    for (int i = start; i >= end; --i) {
        result += verse(i);
        if (i != end)
            result += '\n';
    }
    return result;
}

std::string sing(int start) {
    std::string result;
    for (int i = start; i >= 0; --i) {
        result += verse(i);
        if (i != 0)
            result += '\n';
    }
    return result;
}

}  // namespace beer_song
