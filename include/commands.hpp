#ifndef COMMANDS_H
#define COMMANDS_H

#include <dpp/dpp.h>
#include <format>

namespace heavensbot::commands
{
    void ping(const dpp::slashcommand_t &event);
    void help(const dpp::slashcommand_t &event);
}

#endif // COMMANDS_H