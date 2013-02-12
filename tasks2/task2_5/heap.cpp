#include "heap.h"

void heapify(Heap &heap, const int top)
{
	int max = top;
	int lchild = leftChild(heap, top);
	int rchild = rightChild(heap, top);
	if ((lchild != -1) && (heap.h[lchild] > heap.h[max]))
	{
		max =  lchild;
	}
	if ((rchild != -1) && (heap.h[rchild] > heap.h[max]))
	{
		max = rchild;
	}
	if (max != top)
	{
		int temp = heap.h[top];
		heap.h[top] = heap.h[max];
		heap.h[max] = temp;
		heapify(heap, max);
	}
}
// при работе с пирамидой используются элементы с индексами от 1 до size включительно
// (нулевой не используется)
Heap* createHeap(int *array, const int size)
{
	Heap *heap = new Heap;
	heap->size = size;
	heap->h = array;
	for (int i = size / 2; i >= 1; i--)
	{
		heapify(*heap, i);
	}
	return heap;
}
int leftChild(Heap &heap, int ind)
{
	int child = 2 * ind;
	if (child > heap.size)
	{
		return -1;
	}
	return child;
}
int rightChild(Heap &heap, int ind)
{
	int child = 2 * ind + 1;
	if (child > heap.size)
	{
		return -1;
	}
	return child;
}
int parent(Heap &heap, int ind)
{
	int parent = ind / 2;
	if (parent < 1)
	{
		return -1;
	}
	return parent;
}
int extract(Heap &h)
{
	int temp = h.h[1];
	h.h[1] = h.h[h.size];
	h.h[h.size] = 0;
	h.size--;
	heapify(h, 1);
	return temp;
}
void heapSort(int *array, const int size)
{
	Heap *heap = createHeap(array, size);
	int last = size;
	for (int i = 1; i <= size; ++i, last--)
	{
		array[last] = extract(*heap);
	}
}


