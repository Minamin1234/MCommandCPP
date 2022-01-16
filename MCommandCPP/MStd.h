#pragma once

#include "MModule.h"

class MStd : public MModule
{
private:
protected:
public:
	MStd();
	void ExecuteCommand(vector<string> args) override;
};