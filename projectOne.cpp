/*
 *  ProjectOne.cpp
 *
 *  Date: 1/22/23
 *  Author: David Schmidt
 *  Some help with algorithams were utilized from github
 */

#include<iostream>

using namespace std;

//class _24HourTime

class _24HourTime;

// enum to track AM or PM in 12 hour clock

enum AMPM{
    AM , PM
}
ampm;

//class Time

class Time{
    public:
    int hour;
    int minute;
    int second;
    virtual void addOneHour() = 0;
    virtual void addOneMinute() = 0;
    virtual void addOneSecond() = 0;
};


class _12HourTime : public Time{
    public:

_12HourTime(int h , int m , int s){
    hour = h;
    minute = m;
    second = s;
    ampm = AM;
}

void addOneHour(){
if(hour == 11){
    hour = 0;
    ampm = ampm == AM ? PM : AM;
}
else {
    hour += 1;
}

}

void addOneMinute(){
    if(minute == 59){
        minute = 0;
        addOneHour();
    }
else {
    minute += 1;
}

}

void addOneSecond(){
    if(second == 59){
        second = 0;
        addOneMinute();
}
else{
    second += 1;
    }
}


friend void displayTime(const _12HourTime& ,const _24HourTime&);

};


class _24HourTime : public Time{

public:

_24HourTime(int h , int m , int s)

{

hour = h;

minute = m;

second = s;

}

void addOneHour(){
    if(hour == 23){
        hour = 0;
}
else{
    hour += 1;
    }

}

void addOneMinute(){
    if(minute == 59){
        minute = 0;
        addOneHour();
}
else {
    minute += 1;
    }

}

void addOneSecond(){
    if(second == 59){
        second = 0;
        addOneMinute();
}
else{
    second += 1;
    }

}

friend void displayTime(const _12HourTime& ,const _24HourTime&);
};

void displayTime(const _12HourTime& time12 ,const _24HourTime& time24){
    cout << "12-Hour Clock\t24-Hour Clock\n";
    if(time12.hour < 10) cout << "0"; cout << time12.hour << ":";
    if(time12.minute < 10 ) cout << "0" ; cout <<  time12.minute << ":";
    if(time12.second < 10) cout << "0"; cout << time12.second;
    if(ampm == AM ) cout << " AM \t"; else cout << " PM \t";
    if(time24.hour < 10) cout << "0"; cout << time24.hour << ":";
    if(time24.minute < 10 ) cout << "0" ; cout << time24.minute << ":";
    if(time24.second < 10) cout << "0"; cout << time24.second << "\t";

cout << "\n";
}

int main(){

_12HourTime time_12_Clock(11 , 59 , 59 );

_24HourTime time_24_Clock(23,59,59);

displayTime(time_12_Clock , time_24_Clock);

while(true){
    cout << "\n";
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit Program\n";



int choice;

cin >> choice;

switch (choice){
    case 1:
    time_12_Clock.addOneHour();
    time_24_Clock.addOneHour();
    displayTime(time_12_Clock , time_24_Clock);
    break;
    
    case 2:
    time_12_Clock.addOneMinute();
    time_24_Clock.addOneMinute();
    displayTime(time_12_Clock , time_24_Clock);
    break;
    
    case 3:
    time_12_Clock.addOneSecond();
    time_24_Clock.addOneSecond();
    displayTime(time_12_Clock , time_24_Clock);
    break;
    
    case 4:
    exit(1);
    break;
    
    default:
    cout << "Invalid choice\n";
    break;
    }
}

}