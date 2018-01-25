#include "kClosestPointsToOrigin.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <math.h>
using namespace std;

void kClosestPointsToOrigin::executeFunction()
{
	std::tuple<int, int> point(1, 2);

	std::vector<std::tuple<int, int>> points = {{-2,4},{0,-2},{-1,0},{3,5},{-2,-3},{3,2}};
	std::tuple<int, int> ptsArr[] = { {-2,4},{0,2},{-1,0},{3,5},{-2,3},{3,2}};
	int ptsSize = sizeof(ptsArr) / sizeof(ptsArr[0]);
	int* arrDist = NULL;
	arrDist = new int[ptsSize];
	distanceOfPoints(points, arrDist);
	//printArray(arrDist,ptsSize); 
	quickSort(arrDist, 0, ptsSize - 1);
	int indicesWanted;
	std::cout << "\nHow many points do you want?\n";
	std::cin >> indicesWanted;
	//printArray(arrDist, ptsSize);
	
	checkVectorsWithCorrespondingDistances(arrDist, points, indicesWanted);
}
void kClosestPointsToOrigin::distanceOfPoints(std::vector<std::tuple<int, int>> points, int arr[])
{
	std::cout << "Points Given\n";
	std::vector<int> distances;
	
	int pythag = 0;
	for (int i = 0; i < points.size(); i++)
	{
		std::cout << "(" << std::get<0>(points[i]) << "," << std::get<1>(points[i]) << ")\n";
		pythag = pow(std::get<0>(points[i]), 2) + pow(std::get<1>(points[i]),2);
		//std::cout << "->" << pythag << "\n";
		arr[i] = pythag;
		//std::cout << "->" << arr[i] << "\n";
		//distances.push_back(pythag);
	}
	
}

std::vector<int> kClosestPointsToOrigin::indexesOfClosesPoints(int arr[], int size,int amountOfIndexes)
{
	std::vector<int> indexes;
	for (int i = 0; i < amountOfIndexes; i++)
	{
		indexes.push_back(arr[size - i]);
	}
	return indexes;
}
void kClosestPointsToOrigin::quickSort(int arr[], int beg, int end)
{
	if (beg < end)
	{
		int partitionIndex = partition(arr, beg, end);
		quickSort(arr, beg, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, end);
	}
}
int kClosestPointsToOrigin::partition(int arr[], int beg, int end)
{
	int pivot = arr[end];
	int pIndex = beg;
	for (int i = beg; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	}
	swap(&arr[pIndex], &arr[end]);
	return pIndex;
}
void kClosestPointsToOrigin::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void kClosestPointsToOrigin::printArray(int arr[],int size)
{
	std::cout <<"\nPrint Array\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i]<<"\n";
	}
}
void kClosestPointsToOrigin::checkVectorsWithCorrespondingDistances(int arr[], std::vector < std::tuple<int, int>> points, int amount)
{
	int pythag = 0;
	int tieCount = false;
	std::cout <<"\n"<< amount << " of points closest to the origin\n";
	for (int i = 0; i < points.size(); i++)
	{
		pythag = pow(std::get<0>(points[i]), 2) + pow(std::get<1>(points[i]), 2);
		if (pythag <= arr[amount-1])
		{
			std::cout << "(" << std::get<0>(points[i]) << "," << std::get<1>(points[i]) << ")\n";
		}
	}
}
kClosestPointsToOrigin::kClosestPointsToOrigin()
{
}


kClosestPointsToOrigin::~kClosestPointsToOrigin()
{
}
