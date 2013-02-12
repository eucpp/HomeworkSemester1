struct Heap
{
	int *h;
	int size;
};

Heap* createHeap(int *array, const int size);
int leftChild(Heap &h, const int ind);
int rightChild(Heap &h, const int ind);
int parent(Heap &h, const int ind);
int extract(Heap &h);
void heapSort(int *array, const int size);