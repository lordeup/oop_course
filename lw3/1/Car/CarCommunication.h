#pragma once

class CCarCommunication
{
public:
	CCarCommunication(std::istream& input, std::ostream& output, CCar& car);

	void ProcessingCommand();

private:
	void PrintInfo(CCar& car);
	bool CheckForNumber(int& number);
	void SetGearMode(CCar& car);
	void SetSpeedMode(CCar& car);

	std::istream& m_input;
	std::ostream& m_output;
	CCar& m_car;
};
