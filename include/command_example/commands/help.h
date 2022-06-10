#pragma once
#include <dpp/dpp.h>

/* This is a forward declaration so that command_example.cpp can #include
 * this file, and find the handle_help function without including the
 * entire source of the command.
 */
void handle_help(dpp::cluster& bot, const dpp::slashcommand_t& event);