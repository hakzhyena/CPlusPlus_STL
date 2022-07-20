/*
* This program demonstrates std::vector
*/
#include <iostream> //for cout and cin
#include <vector> //for vector ofcourse!
// I don't want to do 'use namespace std' here as I feel it would pollute global namespace hence not a good practice
/*
* This method prints the elments in the vector
* in: integers - vector to print elments of
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
//program's starting point
int main() 
{
    std::vector<int> integers;
    int input = 0;
    std::cout << "vector operations: \n";
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
    print(integers);
}