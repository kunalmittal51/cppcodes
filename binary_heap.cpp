#include<bits/stdc++.h>
using namespace std;
void swap ( int *i , int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
int heapify (vector<int>&heap,int parent)
{
	int lchild = parent*2+1;
	int rchild = parent*2+2;
	int smallest = parent;
	if ( lchild < heap.size() && heap[lchild] < heap[parent]  )
	{
		smallest = lchild;
	}
	if ( rchild < heap.size() && heap[rchild] < heap[smallest] ) 
	{
	    smallest = rchild;
	} 
	if ( smallest != parent)
	{
		swap(&heap[parent] , &heap[smallest]);
		heapify(heap,smallest);
	}
}
void insertKey(vector<int>&heap,int key)
{
	heap.push_back(key);
	int child = heap.size()-1;
	while ( child > 0 && heap[(child-1)/2] > heap[child] )
	{
		swap(&heap[(child-1)/2],&heap[child]);
		child = (child-1)/2;
	}
}
int getMin(vector<int>&heap)
{
	if ( heap.size() != 0)
	{
		return heap[0];
	}
	else return INT_MAX;	
}
void decreaseKey(vector<int>&heap,int index , int value)
{
	if ( heap.size() > 0)
	{
		heap[index] = value;
		while ( index > 0 && heap[index] < heap[(index-1)/2])
		{
			swap(&heap[index],&heap[(index-1)/2]);
			index = (index-1)/2;
		}
	}
}
int extractMin(vector<int>&heap)
{
	if ( heap.size() == 0)
	{
		return INT_MAX;
	}
	if ( heap.size() == 1)
	{
		int temp = heap[0];
		heap.clear();
		return temp;
	}
	int temp = heap[0];
	swap(&heap[0],&heap[heap.size()-1]);
	heap.pop_back();
	heapify(heap,0);
	return temp;
}
void deleteKey (vector<int>&heap,int index)
{
	decreaseKey(heap,index,INT_MIN);
	int temp = extractMin(heap);
}
int main()
{
	vector<int>heap;
	insertKey(heap,3);
    insertKey(heap,2);
    deleteKey(heap,1);
    insertKey(heap,15);
    insertKey(heap,5);
    insertKey(heap,4);
    insertKey(heap,45);
 	cout << extractMin(heap) << " ";
    cout << getMin(heap) << " ";
    decreaseKey(heap,2, 1);
    cout << getMin(heap);
    return 0;
}

