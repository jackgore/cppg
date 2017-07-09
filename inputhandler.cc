#include <string>
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
 * void launchREPL() launches REPL for reading in classnames and
 * generates files appropriately
 */
void InputHandler::launchREPL() {

}

/**
 * void process(istream& in) Reads a line from the inputstream in
 * and passes it along to the generator to have the files generated.
 */
void InputHandler::process(istream& in, Configuration *configuration) {
	string name;
	// Read class name from in
	if(configuration->interactiveMode) {
		launchREPL();
	} else {
		while(in >> name) {
			fileGenerator->generate(name);
		}
	}

}


