/**
 * D++ multiple command example.
 */

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <dpp/fmt/format.h>
#include <fstream>
#include <iostream>
#include <map>
#include "command_example/command.h"
#include "command_example/commands/ping.h"
#include "command_example/commands/info.h"
#include "command_example/commands/help.h"

using json = nlohmann::json;

/* We define all our commands here.
 * Each command has a name, a description, a command handler function and optionally a
 * list of command parameters (each is of type dpp::command_option).
 * To demonstrate this example we declare each of these handlers, e.g. handle_ping,
 * handle_help and handle_info in separate files (see src/commands folder and
 * include/commands folder) with individual header files. You can arrange this however
 * you like, or you could even directly put a lambda into this map, but this would
 * defeat the point of the example.
 */
std::map<std::string, command_definition> commands = {
	{ "ping", { "A ping command", handle_ping }},
	{ "help", {
		"A help command", handle_help , { 
			/* One optional string parameter */
			{ dpp::command_option(dpp::co_string, "term", "Help term", false) },
		}
	}},
	{ "info", { "An info command", handle_info }},
};

int main()
{
	/* Setup the bot, reading token from config.json */
	json configdocument;
	std::ifstream configfile("../config.json");
	configfile >> configdocument;
	dpp::cluster bot(configdocument["token"]);

	/* Default basic logger */
	bot.on_log(dpp::utility::cout_logger());

	/* In the on_ready we translate the commands map into a vector of dpp::slashcommand.
	 * The vector of dpp::slashcommand is then passed to the command registration
	 * method, dpp::cluster::global_bulk_command_create().
	 */
	bot.on_ready([&](const dpp::ready_t & event) {
		if (dpp::run_once<struct bulk_register>()) {
			std::vector<dpp::slashcommand> slash_commands;
			for (auto & def : commands) {
				dpp::slashcommand c;
				c.set_name(def.first).
				  set_description(def.second.description).
				  set_application_id(bot.me.id);
				c.options = def.second.parameters;
				slash_commands.push_back(c);
			}
			bot.global_bulk_command_create(slash_commands);
		}
	});

	/* Handle slash commands */
	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
			dpp::command_interaction cmd_data = event.command.get_command_interaction();
			/* Check for commands that exist in our command map */
			auto command_iter = commands.find(cmd_data.name);
			if (command_iter != commands.end()) {
				/* If we find a matching command, call its handler function,
				 * passing in this event's information and the bot cluster
				 * as references.
				 */
				command_iter->second.function(bot, event);
			}
	});

	bot.start(false);
}
