#include "command_example/command.h"
#include "command_example/commands/help.h"

/* Example help command.
 * Has an optional 'term' parameter that contains a help topic.
 */
void handle_help(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	auto parameter = event.get_parameter("term");

	/* Check to see if the parameter is provided by the user */
	if (std::holds_alternative<std::string>(parameter)) {

		/* If it is, get it and check what's in it */
		std::string search_term = std::get<std::string>(parameter);
		if (search_term == "ping") {
			/* Some reply to help for PING */
			event.reply("This help left useless as an exercise for the developer.");
		} else {
			/* Anything, something, so long as the bot replies. */
			event.reply("This message intentionally left blank. 🤪");
		}
	}
	/* Help reply */
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
