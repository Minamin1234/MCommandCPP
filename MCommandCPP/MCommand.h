#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "MModule.h"

using namespace std;

class MCommand
{
private:
protected:
	vector<MModule*> Modules;
	vector<string> DefaultCommands;
	char ModuleSprt = '.';
	char SprtInArgs = ',';

	virtual void Initialize();
public:
	string Version = "v1.0";

	MCommand();
	void Run();
	vector<string> DecodeArgs(string words);
	void IncludeNewModule(MModule *newmodule);
	void ShowAllModuleCommandInfo();
	void ShowAllDefaultCommands();
	void ExecuteCommand(vector<string> args);
};