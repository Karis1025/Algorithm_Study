#include <iostream>
#include "Heap.h"

int main()
{
	// 9, 2, 3, 4 Ãâ·Â
	Heap max_heap;
	max_heap.Insert(8);
	max_heap.Insert(6);
	max_heap.Insert(7);
	max_heap.Insert(2);
	max_heap.Insert(5);
	max_heap.Insert(4);

	int max{};
	max_heap.Pop(max);
	std::cout << "max = " << max << std::endl;

	max_heap.Print();
}