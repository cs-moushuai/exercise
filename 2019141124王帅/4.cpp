#include <iostream>

using namespace std;

class Time
{
public:
    Time(const int hours = 0, const int minutes = 0, const int seconds = 0): hours_(hours), minutes_(minutes), seconds_(seconds) {}
    Time(const Time &rhs) = default;


    void DisplayTime(bool flag)
    {
        if(!flag)
        {
            if(hours_ > 12)
            {
                cout << hours_ - 12 << ":" <<  minutes_ << ":" << seconds_ << " PM" << endl;
            }
            else
            {
                cout << hours_ << ":" <<  minutes_ << ":" << seconds_ << " AM" << endl;
            }

        }
        else
        {
            cout << hours_ << ":" <<  minutes_ << ":" << seconds_ << endl;
        }

    }

    void AddTime(int hours, int minutes, int seconds)
    {
        seconds_ += seconds;
        minutes_ += minutes;
        hours_ += hours;

        minutes_ += seconds_ / 60;
        seconds_ %= 60;
        hours_ += minutes_ / 60;
        minutes_ %= 60;
        hours_ %= 24;
    }

    void MinusTime(int hours, int minutes, int seconds)
    {
        seconds_ -= seconds;
        minutes_ -= minutes;
        hours_ -= hours;

        if(seconds_ < 0)
        {
            minutes_ -= (-seconds_) / 60;
            seconds_ = 60 - seconds_ % 60;
        }
        if(minutes_ < 0)
        {
            hours_ -= (-minutes_) / 60;
            minutes_ = 60 - minutes_ % 60;

        }
        if(hours_ < 0)
        {
            hours_ = 24 - (-hours_) % 24;
        }
    }




private:
    int hours_, minutes_, seconds_;
};

class ZoneTime: public Time
{
public:
    ZoneTime(const int hours = 0, const int minutes = 0, const int seconds = 0, const string &zone = ""): Time(hours, minutes, seconds), zone_(zone) {}
    ZoneTime(const ZoneTime &rhs): Time(rhs), zone_(rhs.zone_) {}
    void DisplayZone()
    {
        cout << "Timezone: " << zone_ << endl;
    }

    void set_zone(const string &zone)
    {
        zone_ = zone;
    }


private:
    string zone_;

};

int main(void)
{
    ZoneTime A(12, 2, 3, "UTC");

    A.DisplayZone();
    A.set_zone("UTC+1");
    A.DisplayZone();


    return 0;
}
