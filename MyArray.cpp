
/*
* I implemented my own version of std::array just to understand how it works internally. I went through an existing implementation of std::array for reference.
* MyArray supports the following:
	Member types:
		value_type
		size_type
		difference_type
		reference
		const_reference
		pointer
		const_pointer
	Element access:
		at()
		operator[]
		front()
		back()
		data()
	Capacity:
		empty()
		size()
		max_size()
	Operations:
		fill()
		swap()

Note that with USE_STD_ARRAY same code works with std::array

*/

#include <iostream>
#include <array>
#include "MyArray.h" /*Interestingly the case of the characters in the file name is not guaranteed to be significant, so I can't name my header file as Array.h which in turn means that my custom class can't be Array.h*/

//#define USE_STD_ARRAY
int main()
{
#ifdef USE_STD_ARRAY
	std::array<int, 5> arr1{ 0, 1, 2, 3, 4 };
	std::array<int, 0> arr2;
	std::array<int, 5> arr3{ 5, 4, 3, 2, 1 };
	using size_type = std::array<int, 5>::size_type;
#else
	MyNamespace::MyArray<int, 5> arr1{ 0, 1, 2, 3, 4 };
	MyNamespace::MyArray<int, 0> arr2;
	MyNamespace::MyArray<int, 5> arr3{ 5, 4, 3, 2, 1 };
	using size_type = MyNamespace::MyArray<int, 5>::size_type;
#endif
	try
	{
		size_type numOfelements = arr1.size();
		std::cout << "arr1 looks like this initially {";

		for (size_type i = 0; i < numOfelements; i++)
			std::cout << arr1.at(i) << ' ';

		std::cout << '}' << std::endl;

		numOfelements = arr2.size();
		std::cout << "arr2 looks like this initially {";

		for (size_type i = 0; i < numOfelements; i++)
			std::cout << arr2.at(i) << ' ';

		std::cout << '}' << std::endl;

		numOfelements = arr3.size();
		std::cout << "arr3 looks like this initially {";

		for (size_type i = 0; i < numOfelements; i++)
			std::cout << arr3.at(i) << ' ';

		std::cout << '}' << std::endl;

		std::cout << "Enter the pos:\t";
		size_type pos = 0;
		std::cin >> pos;

		std::cout << "value present at pos " << pos << " at arr1 using at() is " << arr1.at(pos) << std::endl;

		std::cout << "value present at pos " << pos << " at arr1 using operator[] is " << arr1[pos] << std::endl;

		std::cout << "First element from the arr1 using front() " << arr1.front() << std::endl;

		std::cout << "Last element from the arr1 using back() " << arr1.back() << std::endl;

		std::cout << std::boolalpha;

		std::cout << "arr1 array is empty : " << arr1.empty() << std::endl;

		std::cout << "arr2 array is empty : " << arr2.empty() << std::endl;

		std::cout << "arr1 has max_size() of " << arr1.max_size() << std::endl;

		std::cout << "arr1 has size() of " << arr1.size() << std::endl;

		std::cout << "arr2 has max_size() of " << arr2.max_size() << std::endl;

		std::cout << "arr2 has size() of " << arr2.size() << std::endl;

		arr1.fill(5);

		numOfelements = arr1.size();
		std::cout << "arr1 looks like this  now after fill(5) {";

		for (size_type i = 0; i < numOfelements; i++)
			std::cout << arr1.at(i) << ' ';

		std::cout << '}' << std::endl;

		arr1.swap(arr3);

		std::cout << "arr1 looks like this  now after swap with arr3 {";

		numOfelements = arr3.size();
		for (size_type i = 0; i < numOfelements; i++)
			std::cout << arr1.at(i) << ' ';

		std::cout << '}' << std::endl;

		numOfelements = arr3.size();
		std::cout << "arr3 looks like this  now after swap with arr1 {";

		for (size_type i = 0; i < numOfelements; i++)
			std::cout << arr3.at(i) << ' ';

		std::cout << '}' << std::endl;

	}
	catch (std::out_of_range const& exc)
	{
		std::cout << exc.what() << std::endl;
	}

}
