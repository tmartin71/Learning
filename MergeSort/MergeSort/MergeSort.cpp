// MergeSort.cpp : Defines the entry point for the console application.
// TODO: write header file, write a unit test
// works!

#include "stdafx.h"
#include "iostream"
#include "vector"

using namespace std;

void merge ( vector<int>& list, int start, int end ) {
	
	int mid = ( start + end ) / 2;
	vector<int> temp;

	int left = start;
	int right = mid + 1;

	while ( left <= mid && right <= end ) {

	    //if the left element is smaller, add it to temp
		if ( list.at(left) < list.at(right) ) {
			temp.push_back( list.at(left) );
			left++;
		} else {
			//if the right element is smaller or equal, add it to temp
			temp.push_back( list.at(right) );
			right++;
		}
	}

	//add any remaining elements on the left
	while ( left <= mid ) {
		temp.push_back( list.at(left) );
		left++;
	}

	//add any remaining elements on the right
	while ( right <= end ) {
		temp.push_back( list.at(right) );
		right++;
	}
 
	//overwrite the original list with temp
	int index = 0;
	left = start;
	while ( left <= end ) {
		list[left] = temp.at( index++ );
		left++;
	}
}

void mergeSort ( vector<int>& list, int start, int end ) {

	if ( start == end )
		return;

	int mid = ( start + end ) / 2;

	mergeSort( list, start, mid );
	mergeSort( list, mid + 1, end );

	merge( list, start, end );

}


void printVector ( vector<int> list ) 
{
	for (vector<int>::iterator it = list.begin(); it != list.end(); ++it) {
	    cout << *it << endl;
	}
	cout << '\n';
}


int _tmain(int argc, _TCHAR* argv[])
{
	int length = 10;
	vector<int> list;
	for (int i = 0; i < 10; ++i) {
		list.push_back( rand() % (length + 1) );  //to ensure a duplicate
	}
	mergeSort( list, 0, length-1 );

	printVector(list);

	return 0;
}

