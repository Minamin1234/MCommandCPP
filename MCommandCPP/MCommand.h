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
	vector<MModule> Modules;
	vector<string> DefaultCommands;
	char ModuleSprt = ',';
	char SprtInArgs = ',';

	virtual void Initialize();
public:
	string Version = "v1.0";

	void Run();
	vector<string> DecodeArgs(string words);
	void ShowAllModuleCommandInfo();
	void ShowAllDefaultCommands();
	void ExeciteCommand(vector<string> args);
};