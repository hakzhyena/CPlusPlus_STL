/*
* This program is part of the exercise of the course on STL that I am doing. This basically teaches about common things across containers that we can do
* - despite the implementation differences.
*/
//Need to disable warning 4668 that comes for standard library headers
#pragma warning (push)
#pragma warning (disable:4668)
#include <iostream> //ofcourse for std::cout and std::cin, without it most of the C++ code is incomplete right?
#include <fstream> //for std::ifstream since we need to read data from a text file
#include <list> //for std::list
#include <vector> //for std::vector
#include <string> //since we would be storing names and genders of the guests in a string
//We need class for better representation of data that primitive types or struct, I know struct vs class difference is only in default access specifier in C++ but I would still prefer class over struct for intent.
#include <iterator>
#pragma warning (pop) //restore the warning level back to last push
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


class Container
{
    public:
    void populateGuests();
    void printGuests();
    bool printGuestByIndex(int index);
    bool removeGuestByIndex(int index);
    float calculateAverageAge();
    private:
    #if defined(USE_VECTOR)
        typedef std::vector<Guest> Guests;
    #elif defined(USE_LIST)
        typedef std::list<Guest> Guests;
    #endif
    Guests guests;
};


/*
* This function reads the guests from text file and populates the container
* input: guests - container that should hold all the guests in memory
* returns: nothing
*/
void Container::populateGuests()
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
void Container::printGuests()
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
* This function prints the guest's data by index
* input: 
*       guests: Container of guests
*       index: the index of the Guest to be printed
* returns: true on successful print
*/
bool Container::printGuestByIndex(int index)
{
    if((index < 0) || (static_cast<unsigned int>(index) >= guests.size()))
    {
        std::cout << "Index out of bounds" << std::endl;
        return false; 
    }
    
    #if defined(USE_VECTOR)
    //Note that if USE_LIST is defined, then you would get an error saying at is not a member of std::list as expected, since std::list doesn't allow
    //random access, so in that case I would want to traverse through the list to the index and print the values
        std::cout << "\n-----guest at index " << index << "-------\n";
        std::cout << guests.at(static_cast<unsigned int>(index)).getName() << std::endl;
        std::cout << guests.at(static_cast<unsigned int>(index)).getGender() << std::endl;
        std::cout << guests.at(static_cast<unsigned int>(index)).getAge() << std::endl;
        std:: cout << "---------------------------------\n";
    #elif defined(USE_LIST)
        std::cout << "\n-----guest at index " << index << "-------\n";
        
        Guests::iterator it = std::next(guests.begin(), index);
        
        // while(index)
        // {   it++;
            // index--;
        // }
        std::cout << it->getName() << std::endl;
        std::cout << it->getGender() << std::endl;
        std::cout << it->getAge() << std::endl;
        std:: cout << "---------------------------------\n";
    #endif
    
    return true;
}


/*
* This function prints the guest's data by index
* input: guests: Container of guests
         index: the index of the Guest to be printed
* returns: nothing
*/
bool Container::removeGuestByIndex(int index)
{
    if((index < 0) || static_cast<unsigned int>(index) >= guests.size())
    {
         std::cout << "Index out of bounds" << std::endl;
         return false;
    }
    #if defined(USE_VECTOR)
        guests.erase(guests.begin() + index); // note that this doesn't work on std::list as it doesn't provide random access. However std::next() works on vectors but that seems inefficient since you have random access available for vectors, you can just use it 
    #elif defined (USE_LIST)
        guests.erase(std::next(guests.begin(), index)); // This wraps std:advance() which does operator++ on iterator index times
    #endif
    
    return true;
}


/*
* This method calculates the average age of guests
*input: guests
*/
float Container::calculateAverageAge()
{
    float output = 0.0f, number = 0.0f;
    for(auto &guest : guests)
    {
        output += static_cast<float>(guest.getAge());
        number++;
    }    
    return output / number;
}

/*
* From this is where the execution starts
* input: nothing
* return: an implicit int 0
*/
int main()
{
    Container guestsContainer;
    guestsContainer.populateGuests();
    guestsContainer.printGuests();

    int index = 0;
    while(true)
    {
        std::cout << "Enter the index of the guest you want to see in particular:\t";
        std::cin >> index;
        if(guestsContainer.printGuestByIndex(index) == false)
            break;    
    }
    std::cout << "You entered invalid index" << std::endl;
    
    while(true)
    {
        std::cout << "Enter the index of the guest you want to remove from the guest list:\t";
        std::cin >> index;
        if(guestsContainer.removeGuestByIndex(index) == false)
        {
            break;
        }
        else 
        {
            std::cout << "Guest list after deletion: " << std::endl;
            guestsContainer.printGuests();
            std::cout << std::endl;
        }
    }
    std::cout << "You entered invalid index" << std::endl;
    
    std::cout << "Average age of guests is: " << guestsContainer.calculateAverageAge() << std::endl;
}