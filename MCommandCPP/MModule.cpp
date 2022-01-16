#include "MModule.h"

void MModule::ExecuteCommand(vector<string> args)
{

}

void MModule::ShowHelp()
{
	cout << "----------Commands----------" << endl;
	for (int i = 0; i < this->Commands.size(); i++)
	{
		cout << this->ModuleName << "." << this->Commands[i] << endl;
	}
}