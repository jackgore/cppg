#ifndef __FILEGENERATOR_H__
#define __FILEGENERATOR_H__
class FileGenerator {
public:
	void generate(std::string& name);
	void generateHeaderFile(const std::string& fileName);
	void generateImplFile(const std::string& fileName);
private:
	bool fileExists(const std::string& fileName);
	void printFileExistenceWarning(const std::string& fileName);
	std::string toLowerCase(const std::string& s);

	const std::string WARNING = "WARNING";
	const std::string IFNDEF = "#ifndef";
	const std::string ENDIF = "#endif";
	const std::string IFNDEF = "#define";
};
#endif