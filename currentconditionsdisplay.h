#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H

#include "subject.h"
#include "observer.h"
#include "displayelement.h"

#include <iostream>

class CurrentConditionsDisplay : public Observer, DisplayElement
{
private:
    float temperature, humidity;
    Subject &weatherData_;
public:
    CurrentConditionsDisplay(Subject &weatherData) : weatherData_(weatherData)
    {
        this->weatherData_.registerObserver(this);
    }
    virtual ~CurrentConditionsDisplay() {
        weatherData_.removeObserver(this);
    }
    void update(float temp, float humidity, float pressure) override{
        temperature=temp;
        this->humidity=humidity;
        display();

        (void) pressure;
    }
    void display() override {
        std::cout << "Current conditions: "<<temperature<<" F degrees and "<<
                     humidity<<" % humidity"<<std::endl;
    }
};

#endif // CURRENTCONDITIONSDISPLAY_H
