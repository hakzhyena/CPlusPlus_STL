#include <iostream>

int main()
{
   int arr[4]{0,1,2,3};
   int* begin = arr;
   int *end = &arr[4]; //valid
   int *twoPastEnd = &arr[5]; //invalid, hence underfined
   int *firstElement = &arr[1];
   int *lastElement = &arr[3];
   std::cout << "Distance between 1st element and 0th element is " << firstElement - begin << std::endl;
   std::cout << "Distance between last element and 0th element is " << lastElement - begin << std::endl;
   std::cout << "Distance between one past last element and 0th element is "<< end - begin << std::endl; // one past last element - begin = length
   std::cout << "What exists in the distance of 2 from one past last element is " << *(end - 2) << std::endl; // 0 1 2 3 onepastlastelement, so should be 2
   std::cout << twoPastEnd - begin << std::endl; // illegal - hence undefined
   //std::cout << (*(firstElement - begin)); //illegal indirection compilation error, because you're trying to find out what is at an address, but this is not an address rather difference between two pointers
}