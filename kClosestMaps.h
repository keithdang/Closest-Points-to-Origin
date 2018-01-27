#pragma once
#include <vector>
#include <tuple>
#include <map>
class kClosestMaps
{
public:
	void executeFunction();
	std::map<int, std::tuple<int, int>> findDistances(std::tuple<int, int> points[], int sizeOfArray);
	void printPoints(std::tuple<int, int, int> points[], int sizeOfArray);
	void testHeap(int distances[]);
	void mapIterator(std::map<int, std::tuple<int, int>> points);
	kClosestMaps();
	~kClosestMaps();
};

