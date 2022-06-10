# D++ Multiple Command Example

This is a C++ bot for demonstrating a simple way to have each command in a separate file while using the D++ library.

There are many ways to approach this, and this method is an example of how to do it without having to have a base class and inheritence. All that is needed in each command file is one function which matches a format declares in `command.h`.

Three sample commands are implemented called `ping`, `info` and `help`.

## Compilation

    mkdir build
    cd build
    cmake ..
    make -j

If DPP is installed in a different location you can specify the root directory to look in while running cmake 

    cmake .. -DDPP_ROOT_DIR=<your-path>

## Running the bot

Create a config.json in the directory above the build directory:

```json
{
"token": "your bot token here", 
}
```

Start the bot:

    cd build
    ./command_example

Using the bot:

Type any one of the three example commands to see it running. Note that this bot registers global commands, and uses bulk registration, so any other global commands registered upon this bot token will be **replaced** by the three examples in this program!
