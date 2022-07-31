/*
* Program demostrating operations on std::list
*/


#pragma warning (push)
#pragma warning (disable:4668)
/*
* This program demonstrates std::list
*/
#include <iostream> //for std:cout and std::in
#include <list> //for std::list ofcourse
#pragma warning (pop)

/*
* This method prints the elments in the list
* in: integers - list to print elments of, note the we receive reference to avoid a copy operation
* returns: nothing
*/
void print(const std::list<int> &integers)
{
    std::cout << "\nIntegers in the list are: {\t";
    for(const int &i : integers)
    {
        std::cout << i << '\t';
    }
    std::cout << "} \n";
}


/*
* This method pushes the input elements to back of the list
* in: integers - list to push the elements to
* returns: nothing
*/
void pushToBack(std::list<int> &integers)
{
    std::cout << "Pushing to the back ...\n";
    int input = 0;
    while(true)
    {
        std::cout << "Enter an integer to insert to the list\n";
        std::cin >> input;
        if(input >= 0)
            integers.push_back(input);
        else
            break;
    }
}


/*
* This method pushes the input elements to front of the list
* in: integers - list to push the elements to
* returns: nothing
*/
void pushToFront(std::list<int> &integers)
{
    std::cout << "Pushing to the front ...\n";
    int input = 0;
    while(true)
    {
        std::cout << "Enter an integer to insert to the list\n";
        std::cin >> input;
        if(input >= 0)
            integers.push_front(input); //Unlike std::vector we have push_front in std::list, so we don't have to use insert() with iterator pointing to the front
        else
            break;
    }

}


/*
* This method inserts a value at the index of the list
* in: integers - list to push the elements to
* returns: nothing
*/
void insertAtAnIndex(std::list<int>& integers)
{
    std:: cout << "\nInserting at an index ...\n";
    int index = 0;
    while(true)
    {
        std::cout << std::endl;
        std::cout << "Enter an index: ";
        std::cin >> index; //get an index to insert at from the user
        if(index >= 0 && index < integers.size()) // insert only if the index is valid
        {
            int value = 0;
            std::cout << "Enter a value greater than or equal to zero to insert at the index: ";
            std::cin >> value; //get a value to insert at the index from the user
            if(value >= 0)
            {
                integers.insert(std::next(integers.begin(),index), value);
            }
            else
            {
                std:: cout << "You entered a negative value! \n";
                break;
            }
        }  
        else
        {
            std:: cout << "You entered an invalid index! \n";
            break;
        }
    }
}


/*
* This method replaces a value at an index of the list
* in: integers - list to push the elements to
* returns: nothing
*/
void replaceAtAnIndex(std::list<int>& integers)
{
    std::cout << "\nReplacing the value at an index ...\n";
    int index = 0;
    while(true)
    {
        std::cout << std::endl;
        std::cout << "Enter an index: ";
        std::cin >> index; //get an index to replace the value at from the user
        if(index>= 0 && index < integers.size()) // Replace only if the index is greater than or equal to zero
        {
            int value = 0;
            std::cout << "Enter a value greater than or equal to zero to replace at the index: ";
            std::cin >> value;
            if(value >= 0)
            {
                std::list<int>::iterator it = std::next(integers.begin(), index);
                *it = value; 
            }
            else
            {
                std:: cout << "You entered a negative value! \n";
                break;
            }
        }else
        {
                std:: cout << "You entered an invalid index \n";
                break;
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
  std::list<int> integers;
  pushToBack(integers);
  print(integers);
  pushToFront(integers);
  print(integers);
  insertAtAnIndex(integers);
  print(integers);
  replaceAtAnIndex(integers);
  print(integers);
  //Note that you don't have random access in list because it is usually implemented as a doubly linked list
}