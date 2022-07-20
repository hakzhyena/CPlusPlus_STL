/*
* This program demonstrates std::list
*/
#include <iostream> //for std:cout and std::in
#include <list> //for std::list ofcourse


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
    while(input >= 0)
    {
        std::cout << "Enter an integer to insert to the list\n";
        std::cin >> input;
        if(input >= 0)
            integers.push_back(input);
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
    while(input >= 0)
    {
        std::cout << "Enter an integer to insert to the list\n";
        std::cin >> input;
        if(input >= 0)
            integers.push_front(input); //Unlike std::vector we have push_front in std::list, so we don't have to use insert() with iterator pointing to the front
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
  //Note that you don't have random access in list because it is usually implemented as a doubly linked list
}