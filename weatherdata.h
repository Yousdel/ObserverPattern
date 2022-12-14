#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "observer.h"
#include "subject.h"
#include <QVector>

class WeatherData : public Subject
{
private:
    QVector <Observer *> observers;
    float temperature, humidity, pressure;

public:
    WeatherData()
    {

    }
    virtual ~WeatherData(){}
    void registerObserver(Observer *o) override{
        observers.push_back(o);
    }
    void removeObserver(Observer *o) override{
        const int i= observers.indexOf(o);
        if (i>=0) observers.removeAt(i);
    }
    void notifyObservers() override{
        for (int i = 0; i < observers.size(); ++i) {
            observers[i]->update(temperature,humidity,pressure);
        }
    }
    void measurementsChanged(){
        notifyObservers();
    }
    void setMeasurements(float temperature,float humidity,float pressure){
        this->humidity = humidity;
        this->pressure = pressure;
        this->temperature = temperature;
        measurementsChanged();
    }
};

#endif // WEATHERDATA_H
