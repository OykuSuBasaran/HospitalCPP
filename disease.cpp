#pragma once
#include <iostream>
#include <string>

class Disease{
private:
    char diseaseName[30], distinctiveSymptom[30], diagnosisDate[10];

public:
    void getDiseaseInfo(){
        std::cout << "Please enter the disease name: " << std::endl;
        std::cin >> diseaseName;

        std::cout << "Please enter the distinctive symptom: " << std::endl;
        std::cin >> distinctiveSymptom;

        std::cout << "Please enter the diagnosis Date: " << std::endl;
        std::cin >> diagnosisDate;
    }

    void showDiseaseInfo(){
        std::cout<<"Disease: "<<diseaseName<< std::endl;
        std::cout<<"Distinctive Symptom: "<<distinctiveSymptom<< std::endl;
        std::cout<<"Diagnosis Date: "<<diagnosisDate<< std::endl;
    }

};

/*int main(){

    Disease d;
    d.getDiseaseInfo();
    d.showDiseaseInfo();

    return 0;
}*/