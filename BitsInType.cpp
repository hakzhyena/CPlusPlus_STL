#include <iostream> //for std::cout
using namespace std;

//function sizeInBits is defined generically so that we can use it for different data types later
template <typename T> //T will serve as parameter in template

int sizeInBits( const T &a) //receives a param of type T
{
	return sizeof(a) * 8; //sizeof returns the bytes required to store a in memory.
}

int main()
{
	cout << "size in bits for char "<< sizeInBits('c') << endl;
	cout << "size in bits for int " << sizeInBits(1) <<  endl;
	cout << "size in bits for float " << sizeInBits(1.1f) <<  endl;
	cout << "size in bits for double " << sizeInBits(1.1) <<  endl;
	
	return 0;
}
