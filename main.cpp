#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
//TODO: не работает сортировка после добавления нового поезда
using namespace std;

class Train {
protected:
    string numberTrain;                    // номер поезда
    string routeTrain;                     // маршрут
    string timeDeparturesTrain;            // время отправления
    int hourDeparturesTrain;               // час отправления
    int minuteDeparturesTrain;             // минута отправления
    string timeArrivalsTrain;              // время прибытия
    int hourArrivalsTrain;                 // час прибытия
    int minuteArrivalsTrain;               // минута прибытия
    string timeArrivalsTrainInVoronezh;    // время прибытия в Воронеж
    string timeDeparturesTrainFromVoronezh;// время отправления из Воронежа
    int timeParkingTrainInVoronezh;        // время стоянки в Воронеже
    string maintenanceTrain;               //техническое обслуживание
public:
    Train() {
        numberTrain = " ";
        routeTrain = " ";
        timeDeparturesTrain = " ";
        hourDeparturesTrain = 0;
        minuteDeparturesTrain = 0;
        timeArrivalsTrain = " ";
        hourArrivalsTrain = 0;
        minuteArrivalsTrain = 0;
        timeArrivalsTrainInVoronezh = " ";
        timeDeparturesTrainFromVoronezh = " ";
        timeParkingTrainInVoronezh = 0;
        maintenanceTrain = " ";
    }

    Train(string number, string route, string timeDepartures, int hourDepartures, int minuteDepartures, string timeArrivals, int hourArrivals, int minuteArrivals, string timeArrivalsInVoronezh,
          string timeDeparturesFromVoronezh, int timeParkingInVoronezh, string maintenance) {
        numberTrain = number;
        routeTrain = route;
        timeDeparturesTrain = timeDepartures;
        hourDeparturesTrain = hourDepartures;
        minuteDeparturesTrain = minuteDepartures;
        timeArrivalsTrain = timeArrivals;
        hourArrivalsTrain = hourArrivals;
        minuteArrivalsTrain = minuteArrivals;
        timeArrivalsTrainInVoronezh = timeArrivalsInVoronezh;
        timeDeparturesTrainFromVoronezh = timeDeparturesFromVoronezh;
        timeParkingTrainInVoronezh = timeParkingInVoronezh;
        maintenanceTrain = maintenance;
    }

    ~Train() = default;

    int translationEnteringInMinute(Train *train, int n) {
        int inputHour = 0, inputMinute = 0, timeInMinute = 0;
        cout << "Enter requested hour: ";
        cin >> inputHour;
        cout << "Enter requested minute: ";
        cin >> inputMinute;
        timeInMinute = inputHour * 60 + inputMinute;
        cout << "Requested time in minute: " << timeInMinute << endl;
        return timeInMinute;
    }

    string getNumber() {
        return numberTrain;
    }

    string getRoute() {
        return routeTrain;
    }

    string getTimeDepartures() {
        return timeDeparturesTrain;
    }

    int getHourDepartures() {
        return hourDeparturesTrain;
    }

    int getMinuteDepartures() {
        return minuteDeparturesTrain;
    }

    string getTimeArrivals() {
        return timeArrivalsTrain;
    }

    int getHourArrivals() {
        return hourArrivalsTrain;
    }

    int getMinuteArrivals() {
        return minuteArrivalsTrain;
    }

    string getTimeArrivalsInVoronezh() {
        return timeArrivalsTrainInVoronezh;
    }

    string getTimeDeparturesFromVoronezh() {
        return timeDeparturesTrainFromVoronezh;
    }

    int getTimeParkingInVoronezh() {
        return timeParkingTrainInVoronezh;
    }

    string getMaintenance() {
        return maintenanceTrain;
    }

    void setNumber(string number) {
        numberTrain = number;
    }

    void setRoute(string route) {
        routeTrain = route;
    }

    void setTimeDepartures(string timeDepartures) {
        timeDeparturesTrain = timeDepartures;
    }

    void setHourDepartures(int hourDepartures) {
        hourDeparturesTrain = hourDepartures;
    }

    void setMinuteDepartures(int minuteDepartures) {
        minuteDeparturesTrain = minuteDepartures;
    }

    void setTimeArrivals(string timeArrivals) {
        timeArrivalsTrain = timeArrivals;
    }

    void setHourArrivals(int hourArrivals) {
        hourArrivalsTrain = hourArrivals;
    }

    void setMinuteArrivals(int minuteArrivals) {
        minuteArrivalsTrain = minuteArrivals;
    }

    void setTimeArrivalsInVoronezh(string timeArrivalsInVoronezh) {
        timeArrivalsTrainInVoronezh = timeArrivalsInVoronezh;
    }

    void setTimeDeparturesFromVoronezh(string timeDeparturesFromVoronezh) {
        timeDeparturesTrainFromVoronezh = timeDeparturesFromVoronezh;
    }

    void setTimeParkingInVoronezh(int timeParkingInVoronezh) {
        timeParkingTrainInVoronezh = timeParkingInVoronezh;
    }

    void setMaintenance(string maintenance) {
        maintenanceTrain = maintenance;
    }

    void printTrain() {
        cout << "Number of train: " << numberTrain << endl;
        cout << "Route of train: " << routeTrain << endl;
        cout << "Time departures of train: " << timeDeparturesTrain << endl;
        cout << "Hour departures of train: " << hourDeparturesTrain << endl;
        cout << "Minute departures of train: " << minuteDeparturesTrain << endl;
        cout << "Time arrivals of train: " << timeArrivalsTrain << endl;
        cout << "Hour arrivals of train: " << hourArrivalsTrain << endl;
        cout << "Minute arrivals of train: " << minuteArrivalsTrain << endl;
        cout << "Time arrivals of train in Voronezh: " << timeArrivalsTrainInVoronezh << endl;
        cout << "Time departures of train from Voronezh: " << timeDeparturesTrainFromVoronezh << endl;
        cout << "Time parking of train in Voronezh: " << timeParkingTrainInVoronezh << endl;
        cout << "Is maintenance necessary for passing train: " << maintenanceTrain << endl;
        cout << endl;
    }

    friend istream &operator>>(istream &in, Train &train) {
        getline(in, train.numberTrain);
        getline(in, train.routeTrain);
        getline(in, train.timeDeparturesTrain);
        in >> train.hourDeparturesTrain;
        in >> train.minuteDeparturesTrain;
        string tmp;
        getline(in, tmp);
        getline(in, train.timeArrivalsTrain);
        in >> train.hourArrivalsTrain;
        in >> train.minuteArrivalsTrain;
        getline(in, tmp);
        getline(in, train.timeArrivalsTrainInVoronezh);
        getline(in, train.timeDeparturesTrainFromVoronezh);
        in >> train.timeParkingTrainInVoronezh;
        getline(in, tmp);
        getline(in, train.maintenanceTrain);
        return in;
    }

    void operator=(Train &train) {
        numberTrain = train.numberTrain;
        timeDeparturesTrain = train.timeDeparturesTrain;
        hourDeparturesTrain = train.hourDeparturesTrain;
        minuteDeparturesTrain = train.minuteDeparturesTrain;
        timeArrivalsTrain = train.timeArrivalsTrain;
        hourArrivalsTrain = train.hourArrivalsTrain;
        minuteArrivalsTrain = train.minuteArrivalsTrain;
        timeArrivalsTrainInVoronezh = train.timeArrivalsTrainInVoronezh;
        timeDeparturesTrainFromVoronezh = train.timeDeparturesTrainFromVoronezh;
        timeParkingTrainInVoronezh = train.timeParkingTrainInVoronezh;
        maintenanceTrain = train.maintenanceTrain;
    }


    virtual void printInfo(Train *train, int n) {// должна выводить весь файлик
        for (int i = 0; i < n - 1; i++) {
            cout << i + 1 << ")";
            train[i].printTrain();
        }
        cout << endl
             << endl;
    }

    int helpSort(Train *train, int n, string numberTrain) {
        for (int i = 0; i < n; i++) {
            if (train[i].getNumber() == numberTrain && train[i].getNumber() != "-") {
                train[i].printTrain();
            }
        }
        return 0;
    }


    Train *bumbleSort(Train *train, int n) {
        string *array = new string[n];
        for (int i = 0; i < n - 1; i++) {
            array[i] = train[i].numberTrain;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    string time = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = time;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << i << ")";
            cout << helpSort(train, n, array[i]) << endl
                 << endl;
        }
    }
};

class PassingTrain : public Train {
public:
    void printInfo(Train *train, int n) override {
        for (int i = 0; i < n - 1; ++i) {
            if (train[i].getTimeParkingInVoronezh() != 0) {
                cout << i + 1 << ")";
                train[i].printTrain();
            }
        }
        cout << endl
             << endl;
    }
};

class VoronezhInitialStation : public Train {
public:
    void printInfo(Train *train, int n) override {
        for (int i = 0; i < n - 1; ++i) {
            if (train[i].getTimeArrivalsInVoronezh() == "-") {
                cout << i + 1 << ")";
                train[i].printTrain();
            }
        }
        cout << endl
             << endl;
    }

    void trainReadyToBoard(Train *train, int n) {
        int timeDeparturesInMinute = 0;
        int differenceDepartures = 0;

        for (int i = 0; i < n; ++i) {
            if (train[i].getTimeArrivalsInVoronezh() == "-") {
                timeDeparturesInMinute = train[i].getHourDepartures() * 60 + train[i].getMinuteDepartures();
            }
        }

        cout << "Time departures in minute: " << timeDeparturesInMinute << endl;
        differenceDepartures = timeDeparturesInMinute - train->translationEnteringInMinute(train, n);
        cout << "The difference between time departures and entering time: " << differenceDepartures << endl;

        if (differenceDepartures > 0 && differenceDepartures < 40) {
            cout << "The train is ready to board" << endl;
        } else if (differenceDepartures > 40) {
            cout << "The train is not served for boarding" << endl;
        } else if (differenceDepartures < 0) {
            cout << "The train has left!!" << endl;
        }
    }
};

class VoronezhLastStation : public Train {
public:
    void printInfo(Train *train, int n) override {
        for (int i = 0; i < n - 1; i++) {
            if (train[i].getTimeParkingInVoronezh() == 0 && train[i].getTimeArrivalsInVoronezh() != "-") {
                cout << i + 1 << ")";
                train[i].printTrain();
            }
        }
        cout << endl
             << endl;
    }

    void trainOnThePlatformAfterArrival(Train *train, int n) {
        int timeArrivalsInMinute = 0;
        int differenceArrivals = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (train[i].getTimeParkingInVoronezh() == 0 && train[i].getTimeArrivalsInVoronezh() != "-") {
                timeArrivalsInMinute = train[i].getHourArrivals() * 60 + train[i].getMinuteArrivals();
            }
        }

        cout << "Time arrivals in minute: " << timeArrivalsInMinute << endl;
        differenceArrivals = train->translationEnteringInMinute(train, n) - timeArrivalsInMinute;
        cout << "The difference between time departures and entering time: " << differenceArrivals << endl;

        if (differenceArrivals < 0) {
            cout << "The train hasn't arrived yet" << endl;
        } else if (differenceArrivals >= 0 && differenceArrivals <= 20) {
            cout << "The train is on the platform after arrival" << endl;
        } else if (differenceArrivals > 20) {
            cout << "The train left for the depot" << endl;
        }
    }
};

void getInfoForTrain(Train *train, int n, const string &number) {// должна выводить маршрут по введенному номеру поезда
    for (int i = 0; i < n - 1; i++) {
        if (train[i].getNumber() == number) {
            train[i].printTrain();
        }
    }
}

int main() {

    int n = 5;
    ifstream fin("information of train for 5 lababa.txt");
    Train *train = new Train[n];
    PassingTrain *passingTrain = new PassingTrain[n];
    VoronezhInitialStation *voronezhInitialStation = new VoronezhInitialStation[n];
    VoronezhLastStation *voronezhLastStation = new VoronezhLastStation[n];
    for (int i = 0; i < n; i++) {
        fin >> train[i];
    }

    int k;
    do {
        cout << "Choose number from 1 to 6" << endl;
        cout << "1: Print the database from file" << endl;
        cout << "2: Print passing trains" << endl;
        cout << "3: Print trains with Voronezh as the initial station" << endl;
        cout << "4: Print trains with Voronezh as the last station" << endl;
        cout << "5: Sort by number of train" << endl;
        cout << "6: The status of the train for Voronezh is initial station (not filed for boarding, filed for boarding, left)" << endl;
        cout << "7: The status of the train for Voronezh is final station (did not arrive, on the platform, left for the depot)" << endl;
        cout << "8: Info of train by number of train" << endl;
        cout << "9: End working the program" << endl;
        cin >> k;
        switch (k) {

            case 1: {
                train->printInfo(train, n);
                break;
            }

            case 2: {
                passingTrain->printInfo(train, n);
                break;
            }

            case 3: {
                voronezhInitialStation->printInfo(train, n);
                break;
            }

            case 4: {
                voronezhLastStation->printInfo(train, n);
                break;
            }

            case 5: {
                train->bumbleSort(train, n);
                break;
            }

            case 6: {
                voronezhInitialStation->trainReadyToBoard(train, n);
                break;
            }
            case 7: {
                voronezhLastStation->trainOnThePlatformAfterArrival(train, n);
                break;
            }
            case 8: {
                cout << "Enter number of train in order to print info:";
                string number;
                getline(cin, number);
                getline(cin, number);
                getInfoForTrain(train, n, number);
                break;
            }
            default: {
                cout << "Choose number from 1 to 8!" << endl;
            }
        }
    } while (k != 9);
}
