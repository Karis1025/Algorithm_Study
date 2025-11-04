#include <iostream>
#include "Heap.h"

int main()
{
	// 9, 2, 3, 4 Ãâ·Â
	Heap max_heap;
	max_heap.Insert(3);
	max_heap.Insert(4);
	max_heap.Insert(2);
	max_heap.Insert(9);
	
	max_heap.Print();
}