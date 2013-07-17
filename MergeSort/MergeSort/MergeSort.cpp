// MergeSort.cpp : Defines the entry point for the console application.
// TODO: write header file, test algorithm, try swapping temp with list using .swap

#include "stdafx.h"
#include "iostream"
#include "vector"

using namespace std;

void merge ( vector<int>& list, int start, int mid, int end ) {
	vector<int> temp;
	int left = start;
	int right = mid + 1;
	while ( left <= mid && right <= end ) {

	    //if the left element is smaller, add it to temp
		if ( list.at(left) < list.at(right) ) {
			temp.push_back( list.at(left) );
			++left;
		} else {
			//if the right element is smaller or equal, add it to temp
			temp.push_back( list.at(right) );
			++right;
		}
	}

	//add any remaining elements on the left
	while ( left <= mid ) {
		temp.push_back( list.at(left) );
		++left;
	}

	//add any remaining elements on the right
	while ( right <= end ) {
		temp.push_back( list.at(right) );
		++right;
	}
 
	//overwrite the original list with temp
	left = start;
	while ( left <= end ) {
		list[left] = temp.at(left);
		++left;
	}

	//relese memory used by temp
	vector<int>().swap(temp);
	return;
}

void mergeSort ( vector<int>& list, int start, int end ) {
	//list has length 1
	if ( start == end )
		return;

	int mid = ( end - start ) / 2;

	mergeSort( list, start, mid );
	mergeSort( list, mid + 1, end );

	merge( list, start, mid, end );

	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Hello world!" << endl;
	return 0;
}

