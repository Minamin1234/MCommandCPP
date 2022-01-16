#include "MMath.h"

#define PI 3.14159265359
#define E 2.71828182846

MMath::MMath()
{
	this->ModuleName = "math";
	this->Commands.push_back("abs");
	this->Commands.push_back("sin");
	this->Commands.push_back("cos");
	this->Commands.push_back("tan");
	this->Commands.push_back("rad");
	this->Commands.push_back("pow");
	this->Commands.push_back("sqrt");
	this->Commands.push_back("max");
	this->Commands.push_back("min");
	this->Commands.push_back("pi");
	this->Commands.push_back("e");
	this->Commands.push_back("help");
}

void MMath::ExecuteCommand(vector<string> args)
{
	float val1 = 0.0f;
	float val2 = 0.0f;

	if (args.size() >= 4)
	{
		if (args[2] != "") val1 = stof(args[2]);
		if (args[3] != "") val2 = stof(args[3]);
	}

	if (args[1] == this->Commands[0])
	{
		cout << fabsf(val1) << endl;
	}
	else if (args[1] == this->Commands[1])
	{
		cout << sinf(val1) << endl;
	}
	else if (args[1] == this->Commands[2])
	{
		cout << cosf(val1) << endl;
	}
	else if (args[1] == this->Commands[3])
	{
		cout << tanf(val1) << endl;
	}
	else if (args[1] == this->Commands[4])
	{
		float rad = val1 * (PI / 180);
		cout << rad << endl;
	}
	else if (args[1] == this->Commands[5])
	{
		cout << powf(val1,val2) << endl;
	}
	else if (args[1] == this->Commands[6])
	{
		cout << sqrtf(val1) << endl;
	}
	else if (args[1] == this->Commands[7])
	{
		cout << max(val1,val2) << endl;
	}
	else if (args[1] == this->Commands[8])
	{
		cout << min(val1,val2) << endl;
	}
	else if (args[1] == this->Commands[9])
	{
		cout << PI << endl;
	}
	else if (args[1] == this->Commands[10])
	{
		cout << E << endl;
	}
	else if (args[1] == this->Commands[11])
	{
		this->ShowHelp();
	}
	
}