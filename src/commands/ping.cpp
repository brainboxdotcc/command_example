#include "command_example/command.h"
#include "command_example/commands/ping.h"
#include <fmt/format.h>

/* Example ping command
 * Calculates rest + websocket ping
 */
void handle_ping(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	/* Get websocket ping of first shard */
	float ws_ping = bot.get_shard(0)->websocket_ping;

	/* Ping reply */
	event.reply(
		dpp::message().add_embed(
			dpp::embed().
			set_color(dpp::colors::yellow).
			set_title("PONG!").
			set_description(
				fmt::format("Ping is: {0:.02f} ms", (bot.rest_ping + ws_ping) * 1000)
			)
		)
	);
}
