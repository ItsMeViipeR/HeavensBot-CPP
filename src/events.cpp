#include "events.hpp"

void heavensbot::events::on_ready(dpp::cluster &bot, const dpp::ready_t &event)
{
    const dpp::snowflake GUILD_ID = dotenv.get("GUILD_ID");

    dpp::presence presence = dpp::presence(dpp::presence_status::ps_online, dpp::activity(dpp::activity_type::at_game, "with you", "", ""));

    bot.set_presence(presence);

    if (dpp::run_once<struct register_bot_commands>())
    {
        bot.guild_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id), GUILD_ID);
        bot.guild_command_create(dpp::slashcommand("help", "Send help", bot.me.id), GUILD_ID);
    }
}

void heavensbot::events::on_slashcommand(dpp::cluster &bot, const dpp::slashcommand_t &event)
{
    const std::string &command_name = event.command.get_command_name();

    if (command_name == "ping")
    {
        heavensbot::commands::ping(event);
    }
    else if (command_name == "help")
    {
        heavensbot::commands::help(event);
    }
}