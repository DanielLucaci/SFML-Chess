#pragma once
#include <map>
#include <string>
#include <SFML/System.hpp>

class TimeManager
{
public:
	TimeManager(const TimeManager&) = delete;
	~TimeManager();

	void addTimer(const std::string&);
	void resetTimer(const std::string&);
	float getTime(const std::string&);
	void deleteTimer(const std::string&);

	bool isGreaterThan(const std::string&, float);
	
	static TimeManager* getInstance();
private:
	TimeManager() = default;

	static TimeManager* instance;
	std::map<std::string, sf::Clock> _timerMap;
};

extern TimeManager* const timeManager;