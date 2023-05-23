#include <maya/MfnPlugin.h>
#include <maya/MGlobal.h>
#include <maya/MSimple.h>
#include <maya/MFileIO.h>

DeclareSimpleCommand(BatchConvertMocap, "aizwellenstan", "1.0");

MStatus BatchConvertMocap::doIt(const MArgList& args)
{
	char Hello[] = "\n Hello World\nMaya C++\n";
	cout << Hello << endl;
	MGlobal::displayInfo(Hello);
	
	// Open file
	// char fileName[] = "pathToFile.ma";
	// MStatus stat = MFileIO::open(fileName, "mayaAscii", true);
	
	// return stat;

	return MStatus::kSuccess;
}