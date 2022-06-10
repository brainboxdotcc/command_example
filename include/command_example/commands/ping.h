#pragma once
#include <dpp/dpp.h>

/* This is a forward declaration so that command_example.cpp can #include
 * this file, and find the handle_ping function without including the
 * entire source of the command.
 */
void handle_ping(dpp::cluster& bot, const dpp::slashcommand_t& event);