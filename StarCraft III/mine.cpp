#include "libs.h"
#include "ui.h"
#include "mine.h"


Mine::Mine()
{
	setlevel(1);
	setadditionalExtractionPerLevel(20);
	setbasicCost(10);
	setcostIncrease(20); //TODO buffs and nerfs
}

int Mine::upgrade(int resources)
{
	Ui ui;
	int action = 0;
	action = ui.showMineStats(level, getExtraction(), getNextLevelExtraction(), nextLevelCost());
	if(action == 1)
	{
		if(resources>=nextLevelCost()) //check if can afford upgrade
		{
			//mine.upgrade();
			level++;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return -1;
	}
	
}