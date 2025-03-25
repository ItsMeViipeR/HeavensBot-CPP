#include "events.hpp"

void heavensbot::events::on_ready(dpp::cluster &bot, const dpp::ready_t &event)
{
    if (dpp::run_once<struct register_bot_commands>())
    {
        bot.guild_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id), 948709223808778290);
    }
}

void heavensbot::events::on_slashcommand(dpp::cluster &bot, const dpp::slashcommand_t &event)
{
    const std::string &command_name = event.command.get_command_name();

    if (command_name == "ping")
    {
        heavensbot::commands::ping(event);
    }
}