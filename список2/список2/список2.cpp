// список2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
using namespace std;
#include "double_linked_list.cpp"

ifstream in("input.txt");
ofstream out ("output.txt");

int main()
{
	DoubleLinkedList<int> l;
	int value,x;
	in >> x;

	while (in >> value)
	{
		l.InsertRight(l.GetLength(), value);
	}
	in.close();
	out << "Ishodnyi spisok: ";
	l.PrintLeftToRight();
	for (int i = 1; i <= l.GetLength();)
	{
		if (l.Get(i) == x)
		{
			l.Remove(i);
		}
		else
		{
			i++;
		}
	}
	out << "Izmenennyi spisok: ";
	l.PrintLeftToRight();
	out.close();
	l.~DoubleLinkedList();
	return 0;
}






