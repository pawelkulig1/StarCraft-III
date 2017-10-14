#ifndef mine_h
#define mine_h

class Mine
{
	int level;
	int additionalExtractionPerLevel;
	int basicCost;
	int costIncrease;
	public:
		Mine();		

		int getlevel()
		{
			return level;
		}

		void setlevel(int level)
		{
			this->level = level;
		}

		int getadditionalExtractionPerLevel()
		{
			return additionalExtractionPerLevel;
		}

	 	void setadditionalExtractionPerLevel(int additionalExtractionPerLevel)
	 	{
	 		this->additionalExtractionPerLevel = additionalExtractionPerLevel;
	 	}

	 	void setbasicCost(int basicCost)
	 	{
	 		this->basicCost = basicCost;
	 	}

	 	int getbasicCost()
	 	{
	 		return basicCost;
	 	}

	 	void setcostIncrease(int costIncrease)
	 	{
	 		this->costIncrease = costIncrease;
	 	}

	 	int getcostIncrease()
	 	{
	 		return costIncrease;
	 	}

	 	int getExtraction()
		{
			return level * additionalExtractionPerLevel;
		}

		int getNextLevelExtraction()
		{
			return (level + 1) * additionalExtractionPerLevel;
		}

	 	int nextLevelCost()
	 	{
	 		return basicCost + level * costIncrease;
	 	}

	 	int upgrade(int resources);
};

#endif