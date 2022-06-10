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

std::map<std::string, command_definition> commands = {
	{ "ping", { "A ping command", handle_ping }},
	{ "help", { "A help command", handle_help }},
	{ "info", { "An info command", handle_info }},
};

int main()
{
	/* Setup the bot */
	json configdocument;
	std::ifstream configfile("../config.json");
	configfile >> configdocument;

	dpp::cluster bot(configdocument["token"]);

	bot.on_log(dpp::utility::cout_logger());

	bot.on_ready([&](const dpp::ready_t & event) {
		std::vector<dpp::slashcommand> slash_commands;
		for (auto & def : commands) {
			slash_commands.push_back(
				dpp::slashcommand().
				set_name(def.first).
				set_description(def.second.description).
				set_application_id(bot.me.id)
			);
		}
		bot.global_bulk_command_create(slash_commands);
	});

	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
			dpp::command_interaction cmd_data = event.command.get_command_interaction();
			/* Check for our /dialog command */
			auto command_iter = commands.find(cmd_data.name);
			if (command_iter != commands.end()) {
				command_iter->second.function(bot, event);
			}
	});

	bot.start(false);
}

