#include "command_example/command.h"
#include "command_example/commands/help.h"

void handle_help(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	auto parameter = event.get_parameter("term");
	if (std::holds_alternative<std::string>(parameter)) {
		std::string search_term = std::get<std::string>(parameter);
		if (search_term == "ping") {
			event.reply("This help left useless as an exercise for the developer.");
		} else {
			event.reply("This message intentionally left blank. 🤪");
		}
	}
	event.reply(
		dpp::message().add_embed(
			dpp::embed().
			set_color(dpp::colors::yellow).
			set_title("Help lol").
			set_description("Help goes here").
			add_field("/help", "This command, moron").
			add_field("/info", "See some info").
			add_field("/ping", "Pong?")
		)
	);
}