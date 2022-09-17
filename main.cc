#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

enum color
{
    black   = 30,
    red     = 31,
    green   = 32,
    yellow  = 33,
    blue    = 34,
    magenta = 35,
    cyan    = 36,
    white   = 37
};

enum style
{
    revert        = 0,
    bold          = 1,
    underline     = 4,
    inverse       = 7,
    bold_off      = 21,
    underline_off = 24,
    inverse_off   = 27
};

template <typename data_t> auto rand_elem(const std::vector<data_t>& data)
{
    return data[rand() % data.size()];
}

std::string fmtstr_rand(const char& c)
{
    std::vector<color> candidates{red, green, yellow, blue, magenta, cyan, white};
    std::string output = "";
    color c_color = rand_elem(candidates);
    style c_style = bold;
    output += "\033[5m\033[" + std::to_string((int)c_style) + ";" + std::to_string((int)c_color) + "m" + c + "\033[0m\033[0m";
    return output;
}

void pchr(const char& c)
{
    if(c==' ') std::cout << c;
    else std::cout << fmtstr_rand(c);
}

void cprnt(const std::string& line)
{
    for (const auto& c: line) pchr(c);
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    std::vector<std::string> stuff
    {
        ".d8888b 888  888 .d8888b .d8888b .d88b. .d8888b .d8888b ",
		"88K     888  888d88P\"   d88P\"   d8P  Y8b88K     88K      ",
		"\"Y8888b.888  888888     888     88888888\"Y8888b.\"Y8888b. ",
		"    X88Y88b  888Y88b.   Y88b.   Y8b.         X88     X88 ",
		" 88888P' \"Y88888 \"Y8888P \"Y8888P \"Y8888  88888P' 88888P' "
    };
    for (const auto& d: stuff) cprnt(d);
    return 0;
}