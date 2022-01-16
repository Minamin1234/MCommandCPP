#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MModule
{
private:
protected:
	vector<string>  Commands;
public:
	string ModuleName = "module";

	virtual void ExecuteCommand(vector<string> args);
	virtual void ShowHelp();
};