#include <string>
#include <iostream>
#include "inputhandler.h"
using std::istream;
using std::string;

// Constructor
InputHandler::InputHandler() {
	fileGenerator = new FileGenerator();
}

// Destructor
InputHandler::~InputHandler() {
	delete fileGenerator;
}

/**
 *	void getResponse(istream& in) consumes an istream 
 *	and tries to read a yes or no value.
 *	Returns: true for yes
 *			 false for no
 */
bool InputHandler::getResponse(istream& in) {
	string response;
	in >> response;
	response = fileGenerator->toLowerCase(response);

	if(response == "y" || response == "yes") {
		return true;	
	}

	if(response == "n" || response == "no") {
		return false;
	}
	
	// If we get here invalid response.. try again
	std::cout << "Invalid response please enter (y/n)" << std::endl;
	return getResponse(in);
}

/**
 * void launchREPL() launches REPL for reading in classnames and
 * generates files appropriately
 */
void InputHandler::launchREPL(istream& in) {
	string className;
	bool response;
	while(in) {
		std::cout << "Please enter the class names you would like to create:" << std::endl;
		in >> className;
		if(className == "q" || className == "Q") return;
		if(fileGenerator->exists(className)) {
			std::cout << "Files for " << className << " detected, overwrite these files? (y/n)" << std::endl;
			response = getResponse(in);
			// If we don't want to overwrite continue loop
			if(!response) continue;
		}
		fileGenerator->generate(className);
	}
}

/**
 * void process(istream& in) Reads a line from the inputstream in
 * and passes it along to the generator to have the files generated.
 */
void InputHandler::process(istream& in, Configuration *configuration) {
	string name;
	// Read class name from in
	if(configuration->interactiveMode) {
		launchREPL(in);
	} else {
		while(in >> name) {
			fileGenerator->generate(name);
		}
	}

}

