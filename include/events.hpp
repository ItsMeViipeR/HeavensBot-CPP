#ifndef EVENTS_H
#define EVENTS_H

#include <dpp/dpp.h>
#include "commands.hpp"

namespace heavensbot::events
{
    void on_ready(dpp::cluster &bot, const dpp::ready_t &event);
    void on_slashcommand(dpp::cluster &bot, const dpp::slashcommand_t &event);
}

#endif // EVENTS_H