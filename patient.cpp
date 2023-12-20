#include "person.cpp"
#include "disease.cpp"
#include <iostream>
#include <fstream>
#include <cstring> //for C language character functions

class Patient: public Person{ //Patient class generated from Person class
private:
    int patientId;
    Disease disease;
    std::string dateOfAppointment;
    char patientFile[30] = "patientData.dat";
    char patientFileTemp[30] = "patientData2.dat";

public:
    void getPatientData(){
        std::cout << "Please enter the patient data." << std::endl;
        getPersonData(); //subclass method 1

        std::cout << "Please enter the disease data." << std::endl;
        disease.getDiseaseInfo(); //subclass method 2

        std::cout << "Please enter a appointment date: " << std::endl;
        std::cin >> dateOfAppointment;
    }

    void addPatient(){
        std::cout << "Enter the patinet's ID: " << std::endl;
        std::cin >> patientId;

        getPatientData();
        std::ofstream patientDatabase(patientFile, std::ios::binary | std::ios::out | std::ios::app);//binary, writing mode, append
        patientDatabase.write((char*)this, sizeof(Patient));
    }

    void showPatientInfo(){
        std::cout << "Patient's Information: " << std::endl;
        std::cout << "Patient's ID: " << patientId << std::endl;
        showPersonData();
        disease.showDiseaseInfo();
        std::cout << "Appointment Date: " << dateOfAppointment<< std::endl;
    }

    void showPatientInfoFromFile(){
        std::ifstream readDataFromDatabase(patientFile, std::ios::binary | std::ios::in);
        while(!readDataFromDatabase.eof()){ //read as long as not "end of file"
            if(readDataFromDatabase.read((char*)this, sizeof(Patient))){
                showPatientInfo();
            }
        }
    }

    void deletePatient(){
        int delID, flag = 0;

        std::cout << "Please enter the ID of the patient you want to delete." << std::endl;
        std::cin >> delID;

        std::ifstream ifpatient;
        ifpatient.open(patientFile, std::ios::in | std::ios::binary);

        std::ofstream ofpatient;
        ofpatient.open(patientFileTemp, std::ios::out | std::ios::binary);

        while(!ifpatient.eof()){ //there is a more secure way!
            ifpatient.read((char*)this, sizeof(Patient));
            if(ifpatient){
                if(delID == patientId){
                    flag = 1; //the id of the patient to be deleted was found 
                }
                else{
                    ofpatient.write((char*)this, sizeof(Patient));
                }
            }
        }

        ifpatient.close();
        ofpatient.close();
        remove(patientFile);
        rename(patientFileTemp, patientFile);

        if(flag == 1){
            std::cout << "Record has been deleted!" << "\n";
        }
        else{
            std::cout << "Record is not found!" << "\n";
        }   
    }

    void editPatientInfo(){
        int editID, currentPosition, flag = 0;
        std::cout << "Please enter the ID of the patient you want to edit: " << "\n";
        std::cin >> editID;

        std::fstream fpatient; //read and write
        fpatient.open(patientFile, std::ios::binary | std::ios::in | std::ios::out);

        while(!fpatient.eof()){
            currentPosition = fpatient.tellg(); //save the current position
            fpatient.read((char*)this, sizeof(Patient));
            if(fpatient){
                if(editID == patientId){
                    flag = 1; //the patient to be edited was found

                    getPatientData(); //take new informations about patiente
                    fpatient.seekp(currentPosition);
                

                    fpatient.write((char*)this, sizeof(Patient));
                    showPatientInfo();
                    break;
                }
            }
        }
        fpatient.close();
        if(flag == 1){
            std::cout << "Record has been modified!" << "\n";
        }
        else{
            std::cout << "Record is not found!" << "\n";
        }
    }

    void choosePatientActivity(){
        int choice;
        char contToAdd;
        do{
            std::cout << "Please press 1 to add a new patient." << "\n";
            std::cout << "Please press 2 to show all informations." << "\n";
            std::cout << "Please press 3 to delete a patient." << "\n";
            std::cout << "Please press 4 to edit a patinet's information." << "\n";
            std::cout << "Please press 5 to exit." << "\n";
            std::cin >> choice;

            switch(choice){
                case 1:
                    do{
                        addPatient();
                        std::cout << "Do you want to add another patient (Press 1 for yes)? " << "\n";
                        std::cin >> contToAdd; 
                    }while(contToAdd == 1);
                    break;
                case 2:
                    showPatientInfoFromFile();
                    break;
                case 3:
                    deletePatient();
                    break;
                case 4:
                    editPatientInfo();
                    break;
                case 5:
                    break;
                default:
                    std::cout << "Invalid choice! " << "\n";
                    break;
            }
        }while(((int)choice < 5) && ((int)choice > 0));
    }

};

/*int main(){
    Patient p;
    p.choosePatientActivity();

    return 0;
}*/