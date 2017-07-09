#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__
#include <sstream>
#include "filegenerator.h"
#include "configuration.h"
class InputHandler {
public:
	void process(std::istream& in, Configuration *);
	InputHandler();
	~InputHandler();
private:
	void launchREPL(std::istream& in);
	bool getResponse(std::istream& in);
	FileGenerator *fileGenerator;
};	
#endif
