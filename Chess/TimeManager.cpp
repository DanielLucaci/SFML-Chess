#include "TimeManager.h"

TimeManager* TimeManager::instance = nullptr;

TimeManager* const timeManager = TimeManager::getInstance();

TimeManager::~TimeManager() {
	if (instance != nullptr) {
		delete(instance);
	}
}

void TimeManager::addTimer(const std::string& timerName)
{
	if (!_timerMap.count(timerName))
		_timerMap[timerName] = sf::Clock();
}

void TimeManager::resetTimer(const std::string& timerName)
{
	if (_timerMap.count(timerName))
		_timerMap[timerName].restart();
}

float TimeManager::getTime(const std::string& timerName)
{
	if (_timerMap.count(timerName))
		return _timerMap[timerName].getElapsedTime().asSeconds();
	return 0.f;
}

void TimeManager::deleteTimer(const std::string& timerName)
{
	_timerMap.erase(timerName);
}

bool TimeManager::isGreaterThan(const std::string& timerName, float max_timer)
{
	return getTime(timerName) > max_timer;
}

TimeManager* TimeManager::getInstance()
{
	if (instance == nullptr) {
		instance = new TimeManager();
	}
	return instance;
}
