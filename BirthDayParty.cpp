/*
* This program is part of the exercise of the course on STL that I am doing. This basically teaches about common things across containers that we can do
* - despite the implementation differences.
*/
#include <iostream> //ofcourse for std::cout and std::cin, without it most of the C++ code is incomplete right?
#include <fstream> //for std::ifstream since we need to read data from a text file
#include <list> //for std::list
#include <vector> //for std::vector
#include <string> //since we would be storing names and genders of the guests in a string
//We need class for better representation of data that primitive types or struct, I know struct vs class difference is only in default access specifier in C++ but I would still prefer class over struct for intent.
#define USE_LIST


/* Represets a Guest of the Birth day party*/
class Guest
{
public:
    
    void setGender(std::string input)
    {
     if(input.at(0) == 'M' ||  input.at(0) == 'm') 
        gender = "Male";
    else
        gender = "Female";
    }
    
    void setName(std::string input)
    {
        name = input;
    }
    
    void setAge(std::string input)
    {
        age = std::stoi(input);
    }
    
    std::string getName()
    {
        return name;
    }
    
    std::string getGender()
    {
        return gender;
    }
    
    int getAge()
    {
        return age;
    }
    
private:
    std::string name;
    std::string gender;
    int age;
};



#if defined(USE_VECTOR)
    typedef std::vector<Guest> Container;
#elif defined(USE_LIST)
    typedef std::list<Guest> Container;
#endif


/*
* This function reads the guests from text file and populates the container
* input: guests - container that should hold all the guests in memory
* returns: nothing
*/
void populateGuests(Container &guests)
{
    std::ifstream guestsData("Guests.txt");
    std::string line;
    Guest guest;
    while(std::getline(guestsData, line))
    {
        guest.setName(line);
        std::getline(guestsData, line);
        guest.setGender(line);
        std::getline(guestsData, line);
        guest.setAge(line);
        
        guests.push_back(guest);
    }
}


/*
* This function prints the guests from container
* input: guests - container that holds all the guests in memory
* returns: nothing
*/
void printGuests(Container &guests)
{
    for(auto guest: guests)
    {
        std:: cout << "\n---------------------------------\n";
        std::cout << guest.getName() << std::endl;
        std::cout << guest.getGender() << std::endl;
        std::cout << guest.getAge() << std::endl;
        std:: cout << "---------------------------------\n";
    }
}


/*
* From this is where the execution starts
* input: nothing
* return: an implicit int 0
*/
int main()
{
    Container guests;
    populateGuests(guests);
    printGuests(guests);
    
}