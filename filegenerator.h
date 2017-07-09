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
	void generateClass(const std::string& className, std::ostream& out);
	std::string toLowerCase(const std::string& s);
	std::string toUpperCase(const std::string& s);

	const std::string WARNING	= "WARNING";
	const std::string IFNDEF	= "#ifndef";
	const std::string ENDIF		= "#endif";
	const std::string DEFINE	= "#define";
	const std::string INCLUDE	= "#include";
	const std::string CLASS		= "class";
};
#endif
