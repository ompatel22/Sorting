#include<iostream>
using namespace std;

void swap(int& a,int& b)
{
	int temp=a;a=b;b=temp;
}
//with Out Recursion
void Adjust(int a[],int n,int i)
{
	int j;
	int key=a[i];
	for(j=(2*i)+1;j<n;j=(j*2)+1)//directly moving j to next left
	{
		//Finding Max. from left & right
		if(j<n-1)
		{
			if(a[j]<a[j+1])
			j++;
		}
		if(key > a[j])//No need to go further
		{
			break;
		}
		//o.w. if key<a[j]
		//insertion at root(j)-->which is j-1/2
		a[(j-1)/2]=a[j];
	}
	//insertion of key at root(j)-->which is j-1/2
	a[(j-1)/2]=key;
}
//with Recursion
void MaxHeapify(int a[],int size,int ind)
{
	//In concept of Heapify we have to convert Complete Binary Tree in to a Max Heap
	//for this we are finding max from left and right of current node & after that we are performing swaping
	int largest=ind;
	int right=2*ind+1;
	int left=2*ind+2;
	if(left<size && a[left]>a[largest])
	{
		largest=left;
	}
	if(right<size && a[right]>a[largest])
	{
		largest=right;
	}
	if(largest!=ind)
	{
		swap(a[ind],a[largest]);
		MaxHeapify(a,size,largest);//for the current element which we have swapped this fun will be called again because now current node will be at largest position.
	}
}

void HeapSort(int a[],int size)
{
	//first we have to create a Max Heap Tree From a Complete Binary Tree
	//And for this we have to heapify only the Non-leaf nodes 
	//because all the leaf nodes are Max Heap, because there are no elements below them
	//No. of leaf nodes in a complete Binary Tree= total nodes/2
	
	for(int i=(size/2)-1;i>=0;i--)//i starts From last non-leaf node upto first non-leaf node
	{
		//MaxHeapify(a,size,i);
		Adjust(a,size,i);
	}
	
	//Now we are performing Deletion Of First Element, which is the largest Element
	//here we are moving this element to the last of the Array
	//After that we have to re-heapify the Tree so 2nd largest will at first position And So on..
	
	for(int i=size-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		//MaxHeapify(a,i,0);//new size -> i-1 & we have to heapify for fisrt element
		Adjust(a,i,0);
	}
}
int main()
{
	int a[]={22,34,67,90,12,45,83,14};
	int n=8;
	HeapSort(a,n);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
