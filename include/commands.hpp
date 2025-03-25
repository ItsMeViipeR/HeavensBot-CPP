#ifndef COMMANDS_H
#define COMMANDS_H

#include <dpp/dpp.h>

namespace heavensbot::commands
{
    void ping(const dpp::slashcommand_t &event);
}

#endif // COMMANDS_H