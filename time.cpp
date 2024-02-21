#include <iostream>
#include <cassert>
#include <cstring>

const int MAX_LENGTH = 128;

struct Time;

Time toTime(unsigned int seconds);

struct Time
{
    unsigned int hour = 0;
    unsigned int minute = 0;
    unsigned int second = 0;

    void print() const
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

    unsigned int inSeconds() const
    {
        return hour * 3600 + minute * 60 + second;
    }

    bool operator<(const Time& other) const
    {
        return inSeconds() < other.inSeconds();
    }

    Time operator-(const Time& other) const
    {
        if(*this < other)
        {
            return toTime(24 * 3600 + inSeconds() - other.inSeconds());
        }else
        {
            return toTime(inSeconds() - other.inSeconds());
        }
    }

    Time operator+(const Time& other) const
    {
        return toTime(other.inSeconds() + inSeconds());
    }
};

Time toTime(unsigned int seconds)
{
    //std::cout << seconds << std::endl;
    return {seconds / 3600, (seconds % 3600) / 60, seconds % 60};
}

struct Event
{
    char title[MAX_LENGTH + 1];
    char organizer[MAX_LENGTH + 1];
    Time startTime;
    Time endTime;

    Time getDuration() const
    {
        return endTime - startTime;
    }
};

int main()
{
    unsigned int n;
    std::cin >> n;

    Time totalTime;
    Event events[MAX_LENGTH];

    for(int i = 0; i < n; ++ i)
    {
        char title[MAX_LENGTH + 1], organizer[MAX_LENGTH + 1], ch;
        unsigned int h1, m1, s1, h2, m2, s2;
        std::cin.ignore();
        std::cin.getline(title, MAX_LENGTH);
        std::cin.getline(organizer, MAX_LENGTH);
        std::cin >> h1 >> ch >> m1 >> ch >> s1 >> h2 >> ch >> m2 >> ch >> s2;
        assert(h1 < 24 && m1 < 60 && s1 < 60 && h2 < 24 && m2 < 60 && s2 < 60);

        strcpy(events[i].title, title);
        strcpy(events[i].organizer, organizer);
        events[i].startTime = {h1, m1, s1};
        events[i].endTime = {h2, m2, s2};
        //(events[i].endTime - events[i].startTime).print();
        totalTime = totalTime + (events[i].endTime - events[i].startTime);
    }

    /*for(int i = 0; i < n; ++ i)
    {
        events[i].startTime.print();
        events[i].endTime.print();
        std::cout << std::endl;
    }*/

    totalTime.print();

    return 0;
}

/*
3
asd
ads
12:00:00
13:00:00
fds
fas
07:43:21
15:00:00
dg
df
21:00:00
04:00:00
*/