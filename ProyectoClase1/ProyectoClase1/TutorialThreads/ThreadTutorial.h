#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#pragma region Functions Declarations Header

void PrintElapsedTime(std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName);

void Example01();
void Example02();
void Example03();
void Example04();
void Example05();
void Example06();
void Count(unsigned long long maxVounter, std::string threadName);

#pragma endregion 


#pragma region Global Variables

std::chrono::system_clock::time_point startDate;

#pragma endregion
void ThreadTutorialTest()
{

	startDate = std::chrono::system_clock::now();

	int exampleUsed = 1;

	switch (exampleUsed)
	{
	case 1:
		Example01();
		break;
	case 2:
		Example02();
		break;
	case 3:
		Example03();
		break;
	case 4:
		Example04();
		break;
	case 5:
		Example05();
		break;
	case 6:
		Example06();
		break;
	}

	std::cout << "example 0" << exampleUsed << "finished" << std::endl;
	std::string text = "";
	std::getline(std::cin, text);

}

void PrintElapsedTime(std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName)
{
	std::chrono::duration<double> elapsedTime = end - start;
	std::cout << "Thread: " << threadName << " - Elapsed time: " << elapsedTime.count() << " seconds" << std::endl;
}

void Count(unsigned long long maxCounter, std::string threadName)
{
	for (unsigned long long i = 0; i < maxCounter; i++)
	{

	}

	std::chrono::system_clock::time_point endDate = std::chrono::system_clock::now();
	PrintElapsedTime(startDate, endDate, threadName);

}

void Example01()
{

	unsigned long long totalCount = 100000000ull;

	std::thread* counter1 = new std::thread(Count, totalCount, "1");
	std::thread* counter2 = new std::thread(Count, totalCount, "2");
	std::thread* counter3 = new std::thread(Count, totalCount, "3");

	counter1->join();
	counter2->join();
	counter3->join();

	Count(totalCount, "0");

}

void Example02()
{

}

void Example03()
{

}

void Example04()
{

}

void Example05()
{

}

void Example06()
{

}