#include "command_example/command.h"
#include "command_example/commands/info.h"
#include <dpp/fmt/format.h>

/* Example info command
 */
void handle_info(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	event.reply(
		dpp::message().add_embed(
			dpp::embed().
			set_color(dpp::colors::yellow).
			set_title("My awesome D++ bot").
			set_description("A real bot would have something witty here...").
			add_field("Uptime", bot.uptime().to_string(), true).
			add_field("Users", std::to_string(dpp::get_user_count()), true).
			add_field("Library Version", fmt::format("[{}]({})", dpp::utility::version(), "https://github.com/brainboxdotcc/DPP"), true)
		)
	);
}