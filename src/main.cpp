#include <iostream>
#include <dpp/dpp.h>
#include "commands.hpp"
#include "events.hpp"
#include "globals.hpp"

const std::string BOT_TOKEN = dotenv.get("BOT_TOKEN");

void createGuildCommand(std::string name, std::string description, dpp::cluster &bot, dpp::snowflake guild_id)
{
    bot.guild_command_create(dpp::slashcommand(name, description, bot.me.id), guild_id);
}

void createGlobalCommand(std::string name, std::string description, dpp::cluster &bot)
{
    bot.global_command_create(dpp::slashcommand(name, description, bot.me.id));
}

int main()
{
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t &event)
                        { heavensbot::events::on_slashcommand(bot, event); });

    bot.on_ready([&bot](const dpp::ready_t &event)
                 { heavensbot::events::on_ready(bot, event); });

    bot.start(dpp::st_wait);
}
