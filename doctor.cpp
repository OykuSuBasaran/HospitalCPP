#include "person.cpp"
#include "disease.cpp"
#include "availability.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class Doctor: public Person{
private:
    int doctorID;
    char docSpecialization[25];
    Disease disease;
    Availability availability;
    char docFile[30] = "doctorInfo.dat";
    char docFileTemp[30] = "doctorInfo2.dat";

public:

    void getDocInfo(){
        std::cout << "Please enter the doctor's data." << "\n";
        getPersonData();

        std::cout << "Please enter the doctor ID: " << "\n";
        std::cin >> doctorID;
        std::cout << "Please enter the spealization: " << "\n";
        std::cin >> docSpecialization;
        std::cout << "Please enter the necessary informations below." << "\n";
        //disease.getDiseaseInfo(); //edit maybe
        availability.enterAvailability();
    }

    void showDocInfo(){
        std::cout << "ID: " << doctorID << "\n";
        showPersonData();
        //disease.showDiseaseInfo();
        availability.showAvailability();
        std::cout << "\n";
    }

    void addDocInfo(){
        getDocInfo();
        std::ofstream docDataBase(docFile, std::ios::binary | std::ios::out | std::ios::app); //writing mode
        docDataBase.write((char*)this, sizeof(Doctor));
    }

    void showDocInfoFromFile(){
        std::ifstream readDataFromDatabase(docFile, std::ios::binary | std::ios::in); //reading mode
        while(!readDataFromDatabase.eof()){ //as long as its not end of the file
            if(readDataFromDatabase.read((char*)this, sizeof(Doctor))){
                showPersonData();
            }
        }
    }

    void deleteDoctor(){
        int docID, flag = 0;
        std::cout << "Please enter the id of the doctor you want to delete: " << "\n";
        std::cin >> docID;

        std::ifstream ifdoc;
        ifdoc.open(docFile, std::ios::binary | std::ios::in);
        std::ofstream ofdoc;
        ofdoc.open(docFileTemp, std::ios::binary | std::ios::out);

        while(!ifdoc.eof()){
            ifdoc.read((char*)this, sizeof(Doctor));
            if(ifdoc){
                if(docID == doctorID){
                    flag =1;
                }
                else{
                    ofdoc.write((char*)this, sizeof(Doctor)); //writing to temp file
                }
            }
        }
        ifdoc.close();
        ofdoc.close();
        remove(docFile);
        rename(docFileTemp, docFile);

        if(flag == 1)
            std::cout << "Doctor's information removed from the system!" << "\n";
        else
            std::cout << "Record is not found!" << "\n";
    }

    void editDoctorInfo(){
        int docid, currPos, flag = 0;
        std::cout << "Please enter the doctor's ID you want to edit: " << "\n";
        std::cin >> docid;

        std::fstream fdoc;
        fdoc.open(docFile, std::ios::binary | std::ios::in | std::ios::out);

        while(!fdoc.eof()){
            currPos = fdoc.tellg();
            fdoc.read((char*)this, sizeof(Doctor));

            if(fdoc){
                if(docid == doctorID){
                    flag = 1;
                    getDocInfo();
                    fdoc.seekp(currPos);
                    fdoc.write((char*)this, sizeof(Doctor));
                    showDocInfo();
                    break;
                }
            }
        }
        fdoc.close();
        if(flag == 1)
            std::cout << "Doctor's information has been edited." << "\n";
        else
            std::cout << "Record has not been found!" << "\n";
    }

    void chooseDoctorActivity(){
        int choice_;
        char continueToAdd;
        do{
            std::cout << "Please press 1 to add a new doctor." << "\n";
            std::cout << "Please press 2 to show all informations." << "\n";
            std::cout << "Please press 3 to delete a doctor." << "\n";
            std::cout << "Please press 4 to edit a doctor's information." << "\n";
            std::cout << "Please press 5 to exit." << "\n";
            std::cin >> choice_;

            switch(choice_){
                case 1:
                    do{
                        addDocInfo();
                        std::cout << "Do you want to add another doctor (Press 1 for yes)? " << "\n";
                        std::cin >> continueToAdd; 
                    }while(continueToAdd == 1);
                    break;
                case 2:
                    showDocInfoFromFile();
                    break;
                case 3:
                    deleteDoctor();
                    break;
                case 4:
                    editDoctorInfo();
                    break;
                case 5:
                    break;
                default:
                    std::cout << "Invalid choice! " << "\n";
                    break;
            }
        }while(((int)choice_ < 5) && ((int)choice_ > 0));
    }

};

/*int main(){
    Doctor d;
    d.chooseDoctorActivity();
    return 0;
}*/