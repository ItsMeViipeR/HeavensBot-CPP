#include "dotenv.hpp"

Dotenv::Dotenv(std::string path)
{
    this->env = {};
    this->path = path;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line))
    {
        std::string key = line.substr(0, line.find('='));
        std::string value = line.substr(line.find('=') + 1);
        // value starts with
        if (value[0] == '"' && value[value.size() - 1] == '"')
        {
            value = value.substr(1, value.size() - 2);
        }
        this->env[key] = value;
    }

    file.close();
}

std::string Dotenv::get(std::string key)
{
    return this->env[key];
}

std::map<std::string, std::string> Dotenv::get_all()
{
    return this->env;
}