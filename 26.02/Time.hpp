#ifndef TIME_H
#define TIME_H

class Time
{
    private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    public:
    Time(unsigned int, unsigned int, unsigned int);
    Time(const Time&);
    bool setHour(unsigned int);
    bool setMinute(unsigned int);
    bool setSecond(unsigned int);
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;
    void print() const;
    unsigned int inSeconds() const;
    bool operator<(const Time& other) const;
    Time operator-(const Time& other) const;
    Time operator+(const Time& other) const;
};


#endif