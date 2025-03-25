#include <iostream>
#include <dpp/dpp.h>
#include "commands.hpp"
#include "events.hpp"

const std::string &BOT_TOKEN = "";
const dpp::snowflake &GUILD_ID = 948709223808778290;

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

    createGuildCommand("ping", "Ping pong!", bot, GUILD_ID);

    bot.start(dpp::st_wait);
}
