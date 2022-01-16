#include "MCommand.h"

#include "MStd.h"
#include "MMath.h"

MCommand::MCommand()
{
	this->Initialize();
}

void MCommand::Initialize()
{
	this->DefaultCommands.push_back("help");
	this->DefaultCommands.push_back("quit");
	this->IncludeNewModule(MStd());
	this->IncludeNewModule(MMath());
}

void MCommand::Run()
{
	while (true)
	{
		string cmd;
		getline(cin,cmd);
		auto args = this->DecodeArgs(cmd);
		this->ExecuteCommand(args);
		if (args[0] == "quit") break;
	}
}

void MCommand::IncludeNewModule(MModule newmodule)
{
	this->Modules.push_back(newmodule);
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

void MCommand::ExecuteCommand(vector<string> args)
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