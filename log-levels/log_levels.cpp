#include <string>

namespace log_line {
std::string message(std::string line) {
    int index {(int)line.find(":")};
    return (line.substr(index+2)); // index is the ":", then one space, then the first letter
}

std::string log_level(std::string line) {
    int index {(int)line.find("]")};
    return (line.substr(1, --index));
}

std::string reformat(std::string line) {
    std::string msg {message (line)};
    std::string lvl {log_level (line)};
    std::string result {msg + " (" + lvl + ")"};
    return result;
}
}  // namespace log_line
