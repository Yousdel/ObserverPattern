#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H

#include "observer.h"
#include "displayelement.h"
#include "subject.h"
#include <QVector>
#include <iostream>

using namespace std;

class StatisticsDisplay : public Observer, DisplayElement
{
private:
    Subject &weatherData_;
    QVector<float> temps;
    float avg, higher=-999999, lower=999999;
    void calculateValues(){
        float sum=0;
        for (const float t : temps) {
            if (t<lower) lower=t;
            if (t>higher) higher=t;
            sum+=t;
        }
        avg= sum/ temps.size();
    }
public:
    StatisticsDisplay(Subject &weatherData) : weatherData_(weatherData)    {
        weatherData_.registerObserver(this);
    }
    void display() override
    {
        cout << "Temperature AVG "<<avg<< ", Higher : "<< higher<<", lower: "<< lower<<endl;
    }
    void update(float temp, float humidity, float pressure) override {
        temps << temp;
        calculateValues();
        display();
        (void) humidity;
        (void) pressure;
    }
};

#endif // STATISTICSDISPLAY_H
