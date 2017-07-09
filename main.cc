#include <iostream>
#include <string>
#include <algorithm>
#include "inputhandler.h"
#include "configuration.h"

/** 
 * char* getCmdOption(char** begin, char** end, const std::string& option) consumes
 * a beginning string word pointer and an end. As well as option to get the argument 
 * for. Undefined behaviour if the option given doesn't have a argument with it.
 * Example:
 *		getCmdOption(argv, argv + argc, "-f")
 *	
 */
char* getCmdOption(char** begin, char** end, const std::string& option) {
    char** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return 0;
}

/**
 * bool cmdOptionExists(char** begin, char** end, const std::string& option) 
 * determines if the given option exists within the bounds of the begin and end 
 * char arrays.
 */
bool cmdOptionExists(char** begin, char** end, const std::string& option) {
    return std::find(begin, end, option) != end;
}

int main(int argc, char * argv[]) {
    Configuration *configuration = new Configuration();
	// Check for interactive mode
	if(cmdOptionExists(argv, argv+argc, "-i") ||
		cmdOptionExists(argv, argv+argc, "--interactive-mode")) {
        configuration->interactiveMode = true;
    }

    //char * filename = getCmdOption(argv, argv + argc, "-f");

	InputHandler ih;
	ih.process(std::cin, configuration);
	delete configuration;
    return 0;
}

