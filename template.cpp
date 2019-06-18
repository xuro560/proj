#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	int GetSize() { return Size; }
	T& operator[](int index);

private:
	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr)
		{ 
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node <T> *head;


};
template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{

}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);


	}
	Size++;
}

template<typename T>
T & List<T>::operator[]( int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (current->data == index)
		{
			return current->data;
		}
		
	}
	

}


int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(22);

	//cout << lst[22];

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

    return 0;
}

