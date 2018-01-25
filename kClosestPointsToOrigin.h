#pragma once
#include <vector>
class kClosestPointsToOrigin
{
public:
	kClosestPointsToOrigin();
	void executeFunction();
	void distanceOfPoints(std::vector<std::tuple<int, int>> points, int arr[]);
	std::vector<int> indexesOfClosesPoints(int arr[],int size, int amountOfIndexes);
	void quickSort(int arr[],int beg,int end);
	int partition(int arr[], int beg, int end);
	void swap(int* a, int* b);
	void printArray(int arr[],int size);
	void checkVectorsWithCorrespondingDistances(int arr[], std::vector < std::tuple<int, int>> points, int amount);
	~kClosestPointsToOrigin();
};

