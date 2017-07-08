#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__
#include <sstream>
#include "filegenerator.h"
class InputHandler {
public:
	void process(std::istream& in);
	InputHandler();
	~InputHandler();
private:
	FileGenerator *fileGenerator;
};	
#endif
