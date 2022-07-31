/*
* Program demonstrating operations on std::vector
*/


#include <iostream> //for cout and cin
#include <vector> //for vector ofcourse!
// I don't want to do 'use namespace std' here as I feel it would pollute global namespace hence not a good practice
/*
* This method prints the elments in the vector
* in: integers - vector to print elments of, note the we receive reference to avoid a copy operation
* returns: nothing
*/
void print(const std::vector<int> &integers)
{
    std:: cout << "\nvector contains: {\t";
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
    std:: cout << "\nPushing back ...\n";
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
* This method inserts a value at the index of the vector
* in: integers - vector to push the elements to
* returns: nothing
*/
void insertAtAnIndex(std::vector<int>& integers)
{
    std:: cout << "\nInserting at an index ...\n";
    int index = 0;
    while(index >= 0)
    {
        std::cout << std::endl;
        std::cout << "Enter an index: ";
        std::cin >> index; //get an index to insert at from the user
        if(index>= 0) // insert only if the index is greater than or equal to zero
        {
            int value = 0;
            std::cout << "Enter a value greater than or equal to zero to insert at the index: ";
            std::cin >> value;
            if(value >= 0)
            {
                integers.insert(integers.begin() + index, value); //Note that to insert()'s first argument you need to pass an iterator, if you pass just an int it won't compile, hence we are passing integers.begin() + index. Another observation is insertion isn't replacement, after insertion at the index, the previous value there is moved to the right and so are the elements at the right.
            }
            else
            {
                std:: cout << "You entered a negative value! \n";
                break;
            }
        }
    }
}


/*
* This method replaces a value at an index of the vector
* in: integers - vector to push the elements to
* returns: nothing
*/
void replaceAtAnIndex(std::vector<int>& integers)
{
    std::cout << "\nReplacing the value at an index ...\n";
    int index = 0;
    while(index >= 0)
    {
        std::cout << std::endl;
        std::cout << "Enter an index: ";
        std::cin >> index; //get an index to replace the value at from the user
        if(index>= 0) // Replace only if the index is greater than or equal to zero
        {
            int value = 0;
            std::cout << "Enter a value greater than or equal to zero to replace at the index: ";
            std::cin >> value;
            if(value >= 0)
            {
                integers.at((unsigned int)index) = value; 
            }
            else
            {
                std:: cout << "You entered a negative value! \n";
                break;
            }
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
    std:: cout << "\nPushing front ...\n";
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
int main() 
{
    std::vector<int> integers;
    std::cout << "vector operations: \n";
    pushToBack(integers);
    print(integers);
    pushToFront(integers);
    print(integers);
    insertAtAnIndex(integers);
    print(integers);
    replaceAtAnIndex(integers);
    print(integers);
}