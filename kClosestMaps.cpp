#include "kClosestMaps.h"
#include "kClosestMaps.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
void kClosestMaps::executeFunction()
{
	std::cout << "Using Heaps\n";
	std::tuple<int, int> points[] = { { -2,4 },{ 0,-2 },{ -1,0 },{ 3,5 },{ -2,-3 },{ 0,1 } };
	int sizeOfArray = sizeof(points) / sizeof(points[0]);
	std::map<int, std::tuple<int, int>> mapPoints = findDistances(points, sizeOfArray);
	int countEnd = 2;
	int count = 0;
	for (std::map<int, std::tuple<int, int>>::iterator it = mapPoints.begin(); it != mapPoints.end(); ++it)
	{
		if (count != countEnd)
		{
			std::cout << it->first << ":  " << std::get<0>(mapPoints[it->first]) << "," << std::get<1>(mapPoints[it->first]) << "\n";
			count++;
		}
		else
		{
			break;
		}

	}
}
void kClosestMaps::mapIterator(std::map<int, std::tuple<int, int>> points)
{
	for (std::map<int, std::tuple<int, int>>::iterator it = points.begin(); it != points.end(); ++it)
	{
		std::cout << it->first << "\n";
	}
}
std::map<int, std::tuple<int, int>> kClosestMaps::findDistances(std::tuple<int, int> points[], int sizeOfArray)
{
	int pythag = 0;
	std::map<int, std::tuple<int, int>> mapPoints;
	std::map<int, std::tuple<int, int>> it;
	for (int i = 0; i < sizeOfArray; i++)
	{
		pythag = pow(std::get<0>(points[i]), 2) + pow(std::get<1>(points[i]), 2);
		if (std::get<0>(mapPoints[pythag]) == NULL)
		{
			mapPoints[pythag] = { std::get<0>(points[i]) , std::get<1>(points[i]) };
			std::cout << std::get<0>(mapPoints[pythag]) << "," << std::get<1>(mapPoints[pythag]) << "\n";
		}
		else
		{
			mapPoints[pythag + 1] = { std::get<0>(points[i]) , std::get<1>(points[i]) };
			std::cout << std::get<0>(mapPoints[pythag + 1]) << "," << std::get<1>(mapPoints[pythag + 1]) << "\n";
		}
	}
	return mapPoints;
}
void kClosestMaps::printPoints(std::tuple<int, int, int> points[], int sizeOfArray)
{
	std::cout << "\nPrinting Points";
	for (int i = 0; i < sizeOfArray; i++)
	{
		std::cout << "\n(" << std::get<0>(points[i]) << "," << std::get<1>(points[i]) << ")\t->" << std::get<2>(points[i]);
	}
}


kClosestMaps::kClosestMaps()
{
}


kClosestMaps::~kClosestMaps()
{
}
