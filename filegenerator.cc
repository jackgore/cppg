#include <sstream>
#include <iostream>
#include <fstream>
#include "filegenerator.h"
using std::string;
using std::stringstream;

/**
 * void toLowerCase(string& s) converts s to lowercase
 * and returns that string
 */
string FileGenerator::toLowerCase(const string& s) {
	stringstream ss;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			ss << (s[i] - 'A' + 'a');
		} else {
			ss << s[i];
		}
	}
	return ss.str();
}

/**
 * void toUpperCase(string& s) converts s to uppercase
 * and returns that string
 */
string FileGenerator::toLowerCase(const string& s) {
	stringstream ss;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			ss << (s[i] - 'A' + 'a');
		} else {
			ss << s[i];
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

void FileGenerator::generateImplFile(const string& fileName) {

}

/*
 * void generateHeaderFile(const string& fileName) generates
 * header file name fileName.h
 * Note: Regardless of the existence of fileName it will be overwritten
 */
void FileGenerator::generateHeaderFile(const string& fileName) {
	string file = fileName;
	file += ".h";
	// Delete file
	remove(file.c_str());
	std::ofstream out{file.c_str()};
	// Generate Header Guard
	out << IFNDEF << " __" << toUpperCase(fileName) << "_H__" << std::endl;
	out << DEFINE << " __" << toUpperCase(fileName) << "_H__" << std::endl;
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
