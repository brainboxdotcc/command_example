#pragma once
#include <dpp/dpp.h>

/* This is a forward declaration so that command_example.cpp can #include
 * this file, and find the handle_info function without including the
 * entire source of the command.
 */
void handle_info(dpp::cluster& bot, const dpp::slashcommand_t& event);