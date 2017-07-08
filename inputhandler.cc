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
 * void process(istream& in) Reads a line from the inputstream in
 * and passes it along to the generator to have the files generated.
 */
void InputHandler::process(istream& in) {
	string name;
	// Read class name from in
	in >> name;
	fileGenerator->generate(name);

}


