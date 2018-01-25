#pragma once
#include <vector>
#include <tuple>
class kClosestPointsToOrigin2
{
public:
	void executeFunction();
	void findDistances(std::tuple<int, int, int> points[],int sizeOfArray);
	void printPoints(std::tuple<int, int, int> points[],int sizeOfArray);
	void quickSort(std::tuple<int, int, int> arr[], int beg, int end);
	int partition(std::tuple<int, int, int> arr[], int beg, int end);
	void swap(int* a, int* b);
	void swapTuples(std::tuple<int, int, int>* a, std::tuple<int, int, int>* b);
	kClosestPointsToOrigin2();
	~kClosestPointsToOrigin2();
};

