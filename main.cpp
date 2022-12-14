#include <QCoreApplication>
#include "weatherdata.h"
#include "currentconditionsdisplay.h"
#include "statisticsdisplay.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WeatherData weatherData ;
    CurrentConditionsDisplay currentConditionsDisplay(weatherData);
    StatisticsDisplay statisticsDisplay(weatherData);
    weatherData.setMeasurements(80, 65, 30.4f);
    weatherData.setMeasurements(82, 70, 29.2f);
    weatherData.setMeasurements(78, 90, 29.2f);

    return a.exec();
}
