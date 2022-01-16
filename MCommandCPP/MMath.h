#pragma once

#include "MModule.h"

class MMath : public MModule
{
private:
protected:
public:
	MMath();
	void ExecuteCommand(vector<string> args) override;
};