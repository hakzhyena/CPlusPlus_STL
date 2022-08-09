/*
* MyArray is a static (fixed-size) array with it's size given at the time of definition
*/


#ifndef _MY_ARRAY_          //class array must be only defined once, hence introducing include guards
#define _MY_ARRAY_
#include <cstddef> //for std::size_t, std::ptrdiff_t
#include <algorithm> //for iter_swap
namespace MyNamespace
{
	template <class T, std::size_t N>
	class MyArray
	{
	public:

		//member types
		using value_type = T;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;

		//I just don't understand how iterators work internally at this point, so I am not defining them. I will come back to them later.
		//using iterator =  
		//using const_iterator =
		//using reverse_iterator = 
		//using const_reverse_iterator = 

		//Element access
		reference at(size_type pos)
		{
			if (pos >= N)
			{
				throw std::out_of_range("invalid subscript");
			}

			return elements[pos];
		}

		reference operator[](size_type pos) //doesn't do bound checking
		{
			return elements[pos];
		}

		const_reference operator[](size_type pos) const //doesn't do bound checking
		{
			return elements[pos];
		}

		reference front()
		{
			return elements[0];
		}

		const_reference front() const
		{
			return elements[0];
		}

		reference back()
		{
			return elements[N - 1];
		}

		const_reference back() const
		{
			return elements[N - 1];
		}

		const_pointer data() const noexcept
		{
			return elements;
		}

		pointer data() noexcept
		{
			return elements;
		}

		//Capacity
		bool empty() const noexcept
		{
			return N == 0;
		}

		size_type size() const
		{
			return N;
		}

		//size() and max_size() return same value since current number of elements and max number of elements is constant (fixed size) in an array.
		size_type max_size() const noexcept
		{
			return N;
		}

		//Operations
		void fill(const T& value)
		{
			std::fill_n(elements, N, value);
		}

		void swap(MyArray& other) noexcept
		{
			for (int i = 0; i < N; i++)
			{
				std::swap(elements[i], other[i]);
			}
		}

		T elements[N];

	};
}
#endif