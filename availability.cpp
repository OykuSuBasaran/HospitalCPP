#include <iostream>
#include <string>
#include <time.h>

class Availability{
private:
    char dayofWeek[15][7], firstShift[24], secondShift[24];
    int i, numberOfDays;

public:
    void enterAvailability(){
        std::cout << "Please enter the number of available days (0-7): " << std::endl; //first try
        std::cin >> numberOfDays;

        while((numberOfDays < 0) || (numberOfDays > 7)){ //as long as the entered number is out of range
            std::cout << "Out of range! Please enter a valid number:" << std::endl;
            std::cin >> numberOfDays;
        }

        std::cout << "Enter the days that the doctor is available: " << std::endl;
        for(i = 0; i < numberOfDays; i++){ //can be improved with switch-case statement
            std::cin >> dayofWeek[i];
        }

        std::cout << "Enter the doctor's first shift: " << std::endl;
        std::cin >> firstShift;

        std::cout << "Enter the doctor's second shift: " << std::endl;
        std::cin >> secondShift;    
    }

    void showAvailability(){
        time_t currentTime;
        time(&currentTime);
        struct tm* timeinfo; //structure to represent time value
        timeinfo = localtime(&currentTime);
        std::cout << "Current time: " << std::endl;
        std::cout << asctime(timeinfo) << std::endl; //readable format

        std::cout << "Doctor is available for " << numberOfDays << " days this week. " << std::endl;
        std::cout << "This available days are: " << std::endl;

        for(i = 0; i < numberOfDays; i++){
            std::cout << dayofWeek[i] << std::endl;
        }

        std::cout << "Doctor's first shift at " << firstShift << " am. " << std::endl;
        std::cout << "Doctor's second shift at " << secondShift << " am. " << std::endl;
    }

};

/*int main(){
    Availability a;
    a.enterAvailability();
    a.showAvailability();

    return 0;
}*/