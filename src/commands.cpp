#include "commands.hpp"

void heavensbot::commands::ping(const dpp::slashcommand_t &event)
{
    event.reply("Pong!");
}

void heavensbot::commands::help(const dpp::slashcommand_t &event)
{
    std::string footer = std::format("Requested by {}", event.command.usr.username);

    dpp::embed embed = dpp::embed()
                           .set_title("Help")
                           .set_color(0xFF0000)
                           .set_description("This is a list of all the commands available for this bot.")
                           .add_field("ping", "Pings the bot to check if it is online.", true)
                           .add_field("help", "Displays this help message.", true)
                           .set_footer(
                               dpp::embed_footer()
                                   .set_text(footer));

    event.reply(embed);
}