#include <iostream>
#include "pch.h"
#include "thread"
#include "mutex"
#include "windows.h"
#include <condition_variable>

CONST INT n = 20;
CONST INT reader_count = 5, writer_count = 5;

std::mutex m;
std::condition_variable cond_var;
bool notified = false, done = false;
int array[n], data = 0;

HANDLE mtx, full, empty;
DWORD WINAPI Writer(PVOID p)
{
	int i = *((int *)p);
	long prev;
	while (1)
	{
		WaitForSingleObject(empty, INFINITE);
		WaitForSingleObject(mtx, INFINITE);
		//std::unique_lock<std::mutex> lock(m);
		//cond_var.wait(lock);
		data++;
		array[data] = rand() % n;
		//notified = true; //оповестили читателей
		printf("writer %d writing %d to %d\n", i, array[data], data);
		ReleaseMutex(mtx);

		ReleaseSemaphore(full, 1, &prev);
		Sleep(1000 + rand() % 1000);
		//done = true;
		//cond_var.notify_one(); //оповещаем след. поток писателей
		return 0;
	}
}

DWORD WINAPI Reader(PVOID p)
{
	/*unique_lock<mutex> lock(m);
	while (!notified)
		{
			cond_var.wait(lock);
		}*/
	int j;
	long prev;
	int i = *((int *)p);
	while (1)
	{
		WaitForSingleObject(full, INFINITE);
		j = array[data];
		printf("reader %d read data %d from %d\n", i, j, data);
		data++;
		Sleep(1000 + rand() % 1000);
	ReleaseSemaphore(empty, 1, &prev);
		
		//notified = false;
	}

}

int main()
{
	int i, x[n];
	DWORD dwThreadId[n], dw;
	HANDLE thread[n];
	empty = CreateSemaphore(NULL, n, n, (LPCWSTR) "Empty");
	full = CreateSemaphore(NULL, 0, n, (LPCWSTR)"Full");
	mtx = CreateMutex(NULL, FALSE, (LPCWSTR)"Mutex");

	for (i = 0; i < n; i++)
	{
		x[i] = i;
		thread[i] = CreateThread(NULL, 0, Writer, (PVOID)&x[i], 0, &dwThreadId[i]);
		if (!thread)
			printf("main process: thread %d not execute!", i);
	}
	for (i = 0; i < n; i++)
	{
		x[i] = i;
		thread[i] = CreateThread(NULL, 0, Reader, (PVOID)&x[i], 0, &dwThreadId[i]);
		if (!thread)
			printf("main process: thread %d not execute!", i);
	}
	WaitForMultipleObjects(n, thread, TRUE, INFINITE);
	CloseHandle(full);
	CloseHandle(empty);
	CloseHandle(mtx);

	//std::thread Writers(ToWrite, writer_count);
	//std::thread Readers(ToRead, reader_count);
	/*std::thread Readers([&]()
	{
		ToRead(reader_count);
	});*/

	//Readers.join();
	//Writers.join();
	return 0;
}
