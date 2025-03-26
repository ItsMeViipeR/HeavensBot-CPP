#ifndef DOTENV_H
#define DOTENV_H

#include <iostream>
#include <map>
#include <fstream>

class Dotenv
{
public:
    Dotenv(std::string path);
    std::string get(std::string key);
    std::map<std::string, std::string> get_all();

private:
    std::string path;
    std::map<std::string, std::string> env;
};

#endif // DOTENV_H