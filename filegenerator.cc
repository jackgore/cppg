#include <sstream>
#include <iostream>
#include <fstream>
#include "filegenerator.h"
using std::string;
using std::stringstream;
using std::ostream;

/**
 * bool exists(const string& s) consumes a classname and returns 
 * true if either a .cc or .h file exists
 */
bool FileGenerator::exists(const string& className) {
	string file = toLowerCase(className);	
	return (fileExists(file + ".h") || fileExists(file + ".cc"));
}

/**
 * void toUpperCase(string& s) converts s to uppercase
 * and returns that string
 */
string FileGenerator::toUpperCase(const string& s) {
	stringstream ss;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] >= 'a' && s[i] <= 'z') {
			ss << static_cast<char>((s[i] - 'a' + 'A'));
		} else {
			ss << static_cast<char>(s[i]);
		}
	}
	return ss.str();
}

/**
 * void toLowerCase(string& s) converts s to lowercase
 * and returns that string
 */
string FileGenerator::toLowerCase(const string& s) {
	stringstream ss;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			ss << static_cast<char>((s[i] - 'A' + 'a'));
		} else {
			ss << static_cast<char>(s[i]);
		}
	}
	return ss.str();
}

/**
 *	void printFileExistenceWarning() prints a warning regarding the 
 *	existence of a file
 */
void FileGenerator::printFileExistenceWarning(const string& fileName) {
	std::cerr << WARNING << " " << fileName << ".h or " << fileName << ".cc detected." << std::endl;
}

/**
 *	void generateImplFile(const string& className) generates .cc file 
 *	from className
 */
void FileGenerator::generateImplFile(const string& className) {
	string file = toLowerCase(className);
	file += ".cc";
	// Delete file
	remove(file.c_str());
	std::ofstream out{file.c_str()};
	// Generate Header Guard
	out << INCLUDE << " \"" << toLowerCase(className) << ".h\"" << std::endl;
	out.close();
}

/**
 * void generateClass(const string& className, ostream& out) generates class
 * based on the class name and prints it to out.
 */
void FileGenerator::generateClass(const string& className, ostream& out) {
	out << CLASS << " " << className << " {" << std::endl;
	out << std::endl;
	out << "};" << std::endl;
}

/*
 * void generateHeaderFile(const string& fileName) generates
 * header file name fileName.h
 * Note: Regardless of the existence of fileName it will be overwritten
 */
void FileGenerator::generateHeaderFile(const string& className) {
	string file = toLowerCase(className);
	file += ".h";
	// Delete file
	remove(file.c_str());
	std::ofstream out{file.c_str()};
	// Generate Header Guard
	out << IFNDEF << " __" << toUpperCase(className) << "_H__" << std::endl;
	out << DEFINE << " __" << toUpperCase(className) << "_H__" << std::endl;
	generateClass(className, out);
	out << ENDIF << std::endl;
	out.close();
}

/**
 * void generate(string& name) generates .h and .cc files
 * from the given class name.
 * Requires: name must be in the format of the name of the class created
 */
void FileGenerator::generate(string& name) {
	string filePrefix = toLowerCase(name);
	// If the file exists we don't really want to do anything
	if(fileExists(name + ".h") || fileExists(name + ".cc")) {
		printFileExistenceWarning(filePrefix);
		return;
	}
	generateHeaderFile(name);
	generateImplFile(name);
}

/**
 * bool fileExists(const string& fileName) determines if a 
 * file exists
 */
bool FileGenerator::fileExists(const std::string& fileName) {
	std::ifstream f{fileName.c_str()};
    return f.good();
}

