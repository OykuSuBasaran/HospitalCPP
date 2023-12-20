#pragma once
#include <iostream>
#include <string>

class Person{
    private:
        char name[30], phoneNumber[10], address[40], mailAddress[30];
        int age;

    public:
        void getPersonData(){
            std::cout << "Please enter the person's name: " << std::endl;
            std::cin >> name;

            std::cout << "Please enter the person's age: " << std::endl;
            std::cin >> age;

            std::cout << "Please enter the person's phone number: " << std::endl;
            std::cin >> phoneNumber;

            std::cout << "Please enter the person's address: " << std::endl;
            std::cin >> address;

            std::cout << "Please enter the person's mail address: " << std::endl;
            std::cin >> mailAddress;
        }


        void showPersonData(){
            std::cout << "Name: "<< name << std::endl;
            std::cout << "Age: "<< age << std::endl;
            std::cout << "Phone Number: "<< phoneNumber << std::endl;
            std::cout << "Address: "<< address << std::endl;
            std::cout << "Mail Address: "<< mailAddress << std::endl;
        }


};

/*int main(){
    Person p;

    p.getPersonData();
    p.showPersonData();

    return 0;
}*/