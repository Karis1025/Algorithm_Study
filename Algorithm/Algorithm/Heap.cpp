#include "Heap.h"
#include <iostream>

using namespace std;
Heap::Heap()
{
	// [Dummy]
	_items.push_back(0);
}

void Heap::Insert(int val)
{
	// 1. 현재 인덱스 * 2 -> 왼쪽 자식의 인덱스
	// 2. 현재 인덱스 * 2 + 1 -> 오른쪽 자식의 인덱스
	// 3. 현재 인덱스 / 2 -> 부모의 인덱스

	// [Insert]
	_items.push_back(val);

	// [Sort]
	int lastIndex = _items.size() - 1;
	int parentIndex = lastIndex / 2;

	while (parentIndex > 0)
	{
		if (_items[parentIndex] > _items[lastIndex])
			break;

		int temp = _items[parentIndex];
		_items[parentIndex] = _items[lastIndex];
		_items[lastIndex] = temp;

		lastIndex = parentIndex;
		parentIndex = lastIndex / 2;
	}
}

bool Heap::Pop(int& num)
{
	// [뽑을게 없다면]
	if (Empty())
		return false;

	// [뽑을게 있다면]
	num = _items[1];
	
	int temp = _items[1];
	_items[1] = _items.back();
	_items[_items.size() - 1] = _items[1];
	_items.pop_back();

	// [정렬]
	int currentIndex = 1;
	int leftIndex = currentIndex * 2;
	int rightIndex = currentIndex * 2 + 1;
	while ((leftIndex < _items.size() - 1)) // 왼쪽 노드 존재(완전 이진 트리는 왼쪽부터 쌓임)
	{
		int largeIndex = leftIndex;
		if (rightIndex < _items.size() - 1) // 오른쪽 노드 존재한다면
		{
			largeIndex = _items[leftIndex] > _items[rightIndex] ? leftIndex : rightIndex;
		}

		// [현재 노드와 가장 큰 노드의 교환]
		if (_items[currentIndex] < _items[largeIndex])
		{
			int temp = _items[currentIndex];
			_items[currentIndex] = _items[largeIndex];
			_items[largeIndex] = temp;
		}

		currentIndex = largeIndex;
		leftIndex = largeIndex * 2;
		rightIndex = largeIndex * 2 + 1;
	}

	return true;
}

bool Heap::Empty()
{
	if (_items.size() == 1)
	{
		return true;
	}

	return false;
}

void Heap::Print()
{
	for (int i = 1; i < _items.size(); i++)
	{
		cout << _items[i] << " ";
	}
}
