/*
* This program demonstrates std::vector
*/
#include <iostream> //for cout and cin
#include <vector> //for vector ofcourse!
// I don't want to do 'use namespace std' here as I feel it would pollute global namespace hence not a good practice
/*
* This method prints the elments in the vector
* in: integers - vector to print elments of, note the we receive back reference to avoid a copy operation
* returns: nothing
*/
void print(const std::vector<int> &integers)
{
    std:: cout << "vector contains: {\t";
    for(const int &index : integers)
    {
        std:: cout << index << '\t';
    }
    std::cout << "}" << std::endl;
}


/*
* This method pushes the input elements to back of the vector
* in: integers - vector to push the elements to
* returns: nothing
*/
void pushToBack(std::vector<int>& integers)
{
    std:: cout << "Pushing back ...\n";
    int input = 0;
    while(input >= 0)
    {
        std::cout << std::endl;
        std::cout << "Enter a positive integer to store: ";
        std::cin >> input; //get an integer from user
        if(input >= 0) // keep getting the inputs from the user till he/she enters positive numbers or zero
        {
            integers.push_back(input); // insert only positive integers to the vector
        }
    }
}


/*
* This method pushes the input elements to back of the vector
* in: integers - vector to push the elements to
* returns: nothing
*/
void pushToFront(std::vector<int>& integers)
{
    std:: cout << "Pushing front ...\n";
    int input = 0;
    while(input >= 0)
    {
        std::cout << std::endl;
        std::cout << "Enter a positive integer to store: ";
        std::cin >> input; //get an integer from user
        if(input >= 0) // keep getting the inputs from the user till he/she enters positive numbers or zero
        {
            integers.insert(integers.begin(), input); // Note that we don't have push_front(), so instead we call insert() and mention where
        }
    }
}


/*
* starting point of the program
* in: nothing
& returns: returns implicit zero
*/
//
int main() 
{
    std::vector<int> integers;
    std::cout << "vector operations: \n";
    pushToBack(integers);
    print(integers);
    pushToFront(integers);
    print(integers);
}