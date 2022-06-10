#include "command_example/command.h"
#include "command_example/commands/info.h"

/* Example info command
 */
void handle_info(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	event.reply(
		dpp::message().add_embed(
			dpp::embed().
			set_color(dpp::colors::yellow).
			set_title("My awesome D++ bot").
			set_description("A real bot would have something witty here...")
		)
	);
}