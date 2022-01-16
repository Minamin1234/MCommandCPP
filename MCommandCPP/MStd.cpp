#include "MStd.h"

MStd::MStd()
{
	this->ModuleName = "std";
	this->Commands.push_back("print");
	this->Commands.push_back("help");
}

void MStd::ExecuteCommand(vector<string> args)
{
	if (args[1] == this->Commands[0])
	{
		cout << args[2] << endl;
	}
	else if (args[1] == this->Commands[1])
	{
		this->ShowHelp();
	}
}