#pragma once
#include <dpp/dpp.h>

/* Definition of our function callback for a command.
 * As it uses std::function it can be a function pointer, a lambda, 
 * or a std::bind to an object method.
 * In this example we use function pointers.
 * The command functions take two referneces, one to the dpp::cluster,
 * and one to the slashcommand event struct.
 */
using command_function = std::function<void(dpp::cluster&, const dpp::slashcommand_t&)>;

/**
 * @brief A definition of a command for the command map
 */
struct command_definition {
	/**
	 * @brief Description of the command, must be lower case, no spaces.
	 */
	std::string description;
	/**
	 * @brief Callback function
	 */
	command_function function;
	/**
	 * @brief Parameters of the slash command
	 */
	std::vector<dpp::command_option> parameters = {};
};
