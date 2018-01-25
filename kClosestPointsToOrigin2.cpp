#include "kClosestPointsToOrigin2.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
using namespace std;
void kClosestPointsToOrigin2::executeFunction()
{
	std::cout << "Efficient version\n";
	std::tuple<int, int, int> points[] = { { -2,4,NULL },{ 0,-2,NULL },{ -1,0,NULL },{ 3,5,NULL },{ -2,-3,NULL },{ 3,2,NULL } };
	int sizeOfArray = sizeof(points) / sizeof(points[0]);
	findDistances(points,sizeOfArray);
	printPoints(points, sizeOfArray);
	quickSort(points, 0, sizeOfArray - 1);
	printPoints(points, sizeOfArray);
}
void kClosestPointsToOrigin2::findDistances(std::tuple<int, int, int> points[],int sizeOfArray)
{
	int pythag = 0;
	for (int i = 0; i < sizeOfArray; i++)
	{
		pythag = pow(std::get<0>(points[i]), 2) + pow(std::get<1>(points[i]), 2);
		std::get<2>(points[i]) = pythag;
	}
}
void kClosestPointsToOrigin2::printPoints(std::tuple<int, int, int> points[], int sizeOfArray)
{
	std::cout << "\nPrinting Points";
	for (int i = 0; i < sizeOfArray; i++)
	{
		std::cout << "\n(" << std::get<0>(points[i]) << "," << std::get<1>(points[i]) << ")\t->" << std::get<2>(points[i]);
	}
}
void kClosestPointsToOrigin2::quickSort(std::tuple<int, int, int> arr[], int beg, int end)
{
	if (beg < end)
	{
		int partitionIndex = partition(arr, beg, end);
		quickSort(arr, beg, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, end);
	}
}
int kClosestPointsToOrigin2::partition(std::tuple<int, int, int> arr[], int beg, int end)
{
	int pivot = std::get<2>(arr[end]);
	int pIndex = beg;
	for (int i = beg; i < end; i++)
	{
		if (std::get<2>(arr[i]) <= pivot)
		{
			swapTuples(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	}
	swapTuples(&arr[pIndex], &arr[end]);
	return pIndex;
}
void kClosestPointsToOrigin2::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void kClosestPointsToOrigin2::swapTuples(std::tuple<int, int, int>* a, std::tuple<int, int, int>* b)
{
	std::tuple<int, int, int> t = *a;
	*a = *b;
	*b = t;
}
kClosestPointsToOrigin2::kClosestPointsToOrigin2()
{
}


kClosestPointsToOrigin2::~kClosestPointsToOrigin2()
{
}
