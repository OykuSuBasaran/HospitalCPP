#include "patient.cpp"
#include "doctor.cpp"

int main(){
    Doctor doctor;
    Patient patient;

    int choice__;

    do{
        std::cout << "Please enter 1 for doctor related work." << "\n";
        std::cout << "Please enter 2 for patient related work. " << "\n";
        std::cin >> choice__;

        switch (choice__){
            case 1:
                std::cout << "***DOCTOR***" << "\n";
                doctor.chooseDoctorActivity();
                break;
            case 2:
                std::cout << "***PATIENT***" << "\n";
                patient.choosePatientActivity();
                break;
            default:
                std::cout << "Invalid choice!" << "\n";
                break;
        }
    }while(choice__ == 1 | choice__ == 2);


    return 0;
}