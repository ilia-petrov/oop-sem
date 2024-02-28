#ifndef EVENT_HPP
#define EVENT_HPP

#include "Time.hpp"

const int MAX_LENGTH = 128;

class Event
{
    private:
    char title[MAX_LENGTH + 1];
    char organizer[MAX_LENGTH + 1];
    Time startTime;
    Time endTime;

    public:
    Event(const char*, const char*, const Time&, const Time&);
    bool setTitle(const char*);
    bool setOrganizer(const char*);
    bool setStartTime(const Time&);
    bool setEndTime(const Time&);
    const char* getTitle() const;
    const char* getOrganizer() const;
    Time getStartTime() const;
    Time getEndTime() const;
    Time getDuration() const;
};

#endif