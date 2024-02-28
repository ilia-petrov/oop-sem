#include "Time.hpp"
#include <iostream>
#include <cassert>

Time toTime(unsigned int seconds);

Time::Time(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0)
{
    assert(setHour(hour) && setMinute(minute) && setSecond(second));
}

Time::Time(const Time& other)
{
    assert(setHour(other.getHour()) && setMinute(other.getMinute()) && setSecond(other.getSecond()));
}

bool Time::setHour(unsigned int hour)
{
    if(hour < 0 || hour >= 24)
    {
        return false;
    }
    this->hour = hour;
    return true;
}

bool Time::setMinute(unsigned int minute)
{
    if(minute < 0 || minute >= 60)
    {
        return false;
    }
    this->minute = minute;
    return true;
}

bool Time::setSecond(unsigned int second)
{
    if(second < 0 || second >= 60)
    {
        return false;
    }
    this->second = second;
    return true;
}

unsigned int Time::getHour() const
{
    return hour;
}

unsigned int Time::getMinute() const
{
    return minute;
}

unsigned int Time::getSecond() const
{
    return second;
}

void Time::print() const
{
    if(hour < 10)
    {
        std::cout << 0;
    }
    std::cout << hour << ':';
    if(minute < 10)
    {
        std::cout << 0;
    }
    std::cout << minute << ':';
    if(second < 10)
    {
        std::cout << 0;
    }
    std::cout << second << '\n';
}

unsigned int Time::inSeconds() const
{
    return hour * 3600 + minute * 60 + second;
}

bool Time::operator<(const Time& other) const
{
    return inSeconds() < other.inSeconds();
}

Time Time::operator-(const Time& other) const
{
    if(*this < other)
    {
        return toTime(24 * 3600 + inSeconds() - other.inSeconds());
    }else
    {
        return toTime(inSeconds() - other.inSeconds());
    }
}

Time Time::operator+(const Time& other) const
{
    return toTime(other.inSeconds() + inSeconds());
}

Time toTime(unsigned int seconds)
{
    //std::cout << seconds << std::endl;
    return {seconds / 3600, (seconds % 3600) / 60, seconds % 60};
}