// double_linked_list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "exception.cpp"
template <class Item> class DoubleLinkedList
{
	struct Element
	{
		Item inf;
		Element *next;
		Element *prev;
		Element(Item x) : inf(x), next(0), prev(0) {}
	};
	Element *head;
	Element *tail;
	int size;
	Element *Find(int index)
	{
		if ((index < 1) || (index > size))
		{
			return NULL;
		}
		else
		{
			Element *cur = head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->next;
			}
			return cur;
		}
	}
public:
	DoubleLinkedList() : head(0), tail(0), size(0) {}
	~DoubleLinkedList()
	{
		while (!Empty())
		{
			Remove(1);
		}
	}
	bool Empty()
	{
		return head == 0;
	}
	int GetLength()
	{
		return size;
	}
	Item Get(int index)
	{
		if ((index < 1) || (index > size))
		{
			throw DoubleListException("Exception: get - double-linked list error");
		}
		else
		{
			Element *r = Find (index);
			Item i = r->inf;
			return i;
		}
	}
	void InsertLeft(int index, Item data)
	{
		if ((index < 1) || (index > size + 1))
		{
			throw DoubleListException("Exception: get - double-linked list error");
		}
		else
		{
			Element *newPtr = new Element(data);
			size = GetLength() + 1;

			Element *cur = Find(index);
			if (cur == NULL)
			{
				head = newPtr;
				tail = newPtr;
			}
			else
			{
				newPtr->next = cur;
				newPtr->prev = cur->prev;
				cur->prev = newPtr;
				if (cur == head)
				{
					head = newPtr;
				}
				else
				{
					newPtr->prev->next = newPtr;
				}
			}
		}
	}
	void InsertRight(int index, Item data)
	{
		if ((index < 1 && head != NULL) || (index > size + 1))
		{
			throw DoubleListException("Exception: get - double-linked list error");
		}
		else
		{
			Element *newPtr = new Element(data);
			size = GetLength() + 1;

			Element *cur = Find(index);
			if (cur == NULL)
			{
				head = newPtr;
				tail = newPtr;
			}
			else
			{
				newPtr->next = cur->next;
				newPtr->prev = cur;
				cur->next = newPtr;
				if (cur == tail)
				{
					tail = newPtr;
				}
				else
				{
					newPtr->next->prev = newPtr;
				}
			}
		}
	}
	void Remove(int index)
	{
		if ((index < 1) || (index > size))
		{
			throw DoubleListException("Exception: get - double-linked list error");
		}
		else
		{
			Element *cur = Find(index);
			--size;
			if (size == 0)
			{
				head = NULL;
				tail = NULL;
			}
			else if (cur == head)
			{
				head = head->next;
				head->prev = NULL;
			}
			else if (cur == tail)
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			else
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
			}
			cur->next = NULL;
			cur->prev = NULL;
			delete cur;
		}
	}
	void PrintLeftToRight()
	{
		for (Element *cur = head; cur != NULL; cur = cur->next)
		{
			out << cur->inf << ' ';
		}
		out << endl;
	}
	void PrintRightToLeft()
	{
		for (Element *cur = tail; cur != NULL; cur = cur->prev)
		{
			out << cur->inf << ' ';
		}
		out << endl;
	}
	};


