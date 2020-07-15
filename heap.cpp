#include<bits/stdc++.h>
using namespace std;
class heap
{
	public:
	vector<int>arr;
	
	int leftchild(int i)
	{  return 2*i+1;  }
	
	int rightchild(int i)
	{  return 2*i+2;   }
	
	int parent(int i)
	{  return (i-1)/2; }
	
	bool hasleftchild(int i)
	{  return (leftchild(i)<arr.size()); }
	
	bool hasrightchild(int i)
	{  return (rightchild(i)<arr.size()); }
		
	bool hasparent(int i)
	{  return (parent(i)>=0);  }
	
	int top()
	{
		try {
			if (arr.size() == 0)
				throw out_of_range("Vector<X>::at() : "
						"index is out of range(Heap underflow)");

			return arr[0];
			}
		// catch and print the exception
		catch (const out_of_range& oor) {
			cout << "\n" << oor.what();
			} 					
	}
	heapifydown()
	{
		int x=0;
		while(hasleftchild(x))
		{
			int small=leftchild(x);
			if(hasrightchild(x)&&rightchild(x)<leftchild(x))
			small=rightchild(x);
			if(arr[x]>arr[small])
			{
				swap(arr[x],arr[small]);
				x=small;
			}
			else break;
		}
	}
	heapifyup()
	{
		int index=arr.size()-1;
		while(hasparent(index))
		{
			if(parent(index)>arr[index])
			{
				swap(arr[parent(index)],arr[index]);
				index=parent(index);
			}
			else break;
		}
	}
	int pop()
	{
			try {
			if (arr.size() == 0)
				throw out_of_range("Vector<X>::at() : "
						"index is out of range(Heap underflow)");
			int item=arr[0];
			arr[0]=arr[arr.size()-1];
			heapifydown();
			return item;
			}
			catch (const out_of_range& oor) {
			cout << "\n" << oor.what();
			}	
	}
	void push(int item)
	{
//		cout<<arr.size();
			arr.push_back(item);
//			cout<<"enter";
			cout<<arr[arr.size()-1];
			heapifyup();
	}
	void print()
	{
		try{
			if(arr.size()==0)
			throw out_of_range("no element");
				for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
		}
			catch (const out_of_range& oor) {
			cout << "\n" << oor.what();
			}
	}
	
};
int main()
{
	heap h;
	h.push(3);
	h.pop();
	h.print();
	
}
