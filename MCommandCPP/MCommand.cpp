#include "MCommand.h"

MCommand::MCommand()
{
	this->Initialize();
}

void MCommand::Initialize()
{
	this->DefaultCommands.push_back("help");
	this->DefaultCommands.push_back("quit");
}

void MCommand::Run()
{
	while (true)
	{
		string cmd;
		cin >> cmd;
		auto args = this->DecodeArgs(cmd);
		this->ExeciteCommand(args);
		if (args[0] == "quit") break;
	}
}

vector<string> MCommand::DecodeArgs(string words)
{
	vector<string> args;
	args.push_back("");
	int level = 0;
	bool modulefrag = false;
	for (int i = 0; i < words.length(); i++)
	{
		if (words[i] == this->ModuleSprt && modulefrag == false)
		{
			level++;
			args.push_back("");
			modulefrag = true;
			continue;
		}
		else if (words[i] == this->SprtInArgs)
		{
			level++;
			args.push_back("");
			continue;
		}
		else if (words[i] == '(')
		{
			level++;
			args.push_back("");
			continue;
		}
		else if (words[i] == ')')
		{
			level++;
			args.push_back("");
			continue;
		}

		args[level] += words[i];
	}

	return args;
}

void MCommand::ShowAllModuleCommandInfo()
{
	for (int i = 0; i < this->Modules.size(); i++)
	{
		this->Modules[i].ShowHelp();
	}
}

void MCommand::ShowAllDefaultCommands()
{
	cout << "----------DefaultCommands----------" << endl;
	for (int i = 0; i < this->DefaultCommands.size(); i++)
	{
		cout << this->DefaultCommands[i] << endl;
	}
}

void MCommand::ExeciteCommand(vector<string> args)
{
	cout << "" << endl;
	if (args[0] == this->DefaultCommands[0])
	{
		this->ShowAllDefaultCommands();
		return;
	}

	for (int i = 0; i < this->Modules.size(); i++)
	{
		if (args[0] == this->Modules[i].ModuleName)
		{
			this->Modules[i].ExecuteCommand(args);
			return;
		}
	}
}