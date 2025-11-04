#pragma once
#include <vector>
class Heap
{
public:
	Heap();

	void Insert(int val);
	bool Pop(int& num);
	bool Empty();
	void Print();

private:
	std::vector<int> _items{};
};

