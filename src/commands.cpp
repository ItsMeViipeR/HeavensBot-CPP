#include "commands.hpp"

void heavensbot::commands::ping(const dpp::slashcommand_t &event)
{
    event.reply("Pong!");
}