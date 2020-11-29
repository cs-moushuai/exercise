#include <iostream>

using namespace std;

class Date
{
    friend void DisplayDate(Date & date);
    friend void AddDate(Date &date, int num);
    friend void MinusDate(Date &date, int num);
public:
    Date(const int year = 0, const int month = 0, const int day = 0): year_(year), month_(month), day_(day) {}
    Date(const Date &rhs) = default;
    bool IsLeapYear()
    {
        return (year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0);
    }
    void DisplayDate();
    void AddDate(int num);
    void MinusDate(int num);


private:
    int year_, month_, day_;
};

void Date::DisplayDate()
{
    cout << "Date: " << year_ << "/" << month_ << "/" << day_ << endl;

}

void DisplayDate(Date &date)
{
    date.DisplayDate();

}
void Date::AddDate(int num)
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(IsLeapYear())
    {
        day_of_month[1] = 29;
    }
    if(num > 28)
    {
        int tmp = day_ + 28 - day_of_month[month_ - 1];
        if(tmp > 0)
        {
            day_ = tmp;

            month_++;
        }
        else
        {
            day_ += 28;
        }
        if(month_ > 12)
        {
            month_ = 1;
            year_++;
        }
        AddDate(num - 28);
    }
    else
    {
        int tmp = day_ + num - day_of_month[month_ - 1];
        if(tmp > 0)
        {
            day_ = tmp;

            month_++;
        }
        else
        {
            day_ += num;
        }
        if(month_ > 12)
        {
            month_ = 1;
            year_++;
        }

    }


}
void AddDate(Date &date, int num)
{
    date.AddDate(num);


}
void Date::MinusDate(int num)
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(IsLeapYear())
    {
        day_of_month[1] = 29;
    }
    if(num > 28)
    {
        int tmp = day_ - 28;
        if(tmp < 0)
        {
            if(month_ == 1)
            {
                month_ = 12;
                year_--;
            }
            else
            {
                month_--;
            }
            day_ = day_of_month[month_ - 1] + tmp;

        }
        else
        {
            day_ = tmp;
        }
        MinusDate( num - 28);
    }
    else
    {
        int tmp = day_ - num;
        if(tmp <= 0)
        {
            if(month_ == 1)
            {
                month_ = 12;
                year_--;
            }
            else
            {
                month_--;
            }
            day_ = day_of_month[month_ - 1] + tmp;

        }
        else
        {
            day_ = tmp;
        }

    }
}

void MinusDate(Date &date, int num)
{
    date.MinusDate(num);
}

class Time
{
public:
    Time(const int hours = 0, const int minutes = 0, const int seconds = 0): hours_(hours), minutes_(minutes), seconds_(seconds) {}
    Time(const Time &rhs) = default;


    void DisplayTime(bool flag)
    {
        cout << "Time: ";
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

class DateTime: public Date, public ZoneTime
{
public:
    DateTime(const int year = 0, const int month = 0, const int day = 0, const int hours = 0, const int minutes = 0, const int seconds = 0, const string &zone = ""):
        Date(year, month, day), ZoneTime(hours, minutes, seconds, zone) {}
    DateTime(const DateTime &rhs): Date(rhs), ZoneTime(rhs) {}


};

int main(void)
{
    DateTime A(2011, 12, 14, 14, 23,12, "UTC");

    A.DisplayDate();
    A.DisplayTime(false);
    A.DisplayZone();

    return 0;
}
