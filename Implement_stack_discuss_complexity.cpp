
#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class myStack {

	std::vector<T> m_storage;
	int size;

public:
	myStack<T>(){}
	void push(const T& val) {
		std::cout << "storaged address is" << &val <<std::endl;
		m_storage.push_back(val);
	}
  
	T& top()
	{
		if (isEmpty())
		{
			throw std::out_of_range("stack is empty");
		}
		return m_storage.back();
	}
	void pop()
	{
		if (isEmpty())
		{
			throw std::out_of_range("stack is empty");
		}
		m_storage.pop_back();
	}
	bool isEmpty()
	{
		return m_storage.empty();
	}

};

struct myData
{
	int a;
	char b;
	int c;
	myData(int x) { a = x, b = a - '0'; c = x + 3; }

};
int main()
{
	myStack<myData> S;
	S.top();
	auto a = myData(1);
	std::cout << "address of pushed element is  " << &a << std::endl;

	S.push(a);
	myData& p = S.top();
	std::cout << "address of top element is  " << &p << std::endl;

}

// Complexity:
Operation: Push() Adds an element to the end of the std::vector.
Average Time Complexity: 𝑂(1) (amortized).
In most cases, adding an element to the end of a std::vector takes constant time.
However, when the vector runs out of capacity, it needs to allocate a larger block of memory and copy existing elements, which takes 
𝑂(𝑛) O(n), where 𝑛 is the current size of the vector.This happens infrequently, so the amortized complexity remains 
𝑂(1)

pop() - Removing the last element is a constant-time operation since no elements need to be shifted or moved o(1)
top() - Accesses the last element in the std::vector o(1)

