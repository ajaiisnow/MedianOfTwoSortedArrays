#include <iostream>
#include <limits>
#include <vector>

using namespace std;
const int NEGATIVE_INFINITY = numeric_limits<int>::min();
const int POSITIVE_INFINITY = numeric_limits<int>::max();

double MeidanOfTwoSortedArrays( vector<int>&arr1, vector<int>arr2)
{
	int len1 = arr1.size();
	int len2 = arr2.size();
	if (len1 > len2)
	{
		return MeidanOfTwoSortedArrays(arr2, arr1);
	}
	int start = 0;
	int end = len1;
	double average = 0;
	while (start <= end)
	{
		int part_arr1 = (start + end) / 2;
		int part_arr2 = (len1 + len2 + 1) / 2 - part_arr1;

		int max_left_arr1 = (part_arr1 == 0) ? NEGATIVE_INFINITY : arr1[part_arr1-1];
		int min_right_arr1 = (part_arr1 == len1) ? POSITIVE_INFINITY : arr1[part_arr1];
		
		int max_left_arr2 = (part_arr2 == 0) ? NEGATIVE_INFINITY : arr2[part_arr2-1];
		int min_right_arr2 = (part_arr2 == len2) ? POSITIVE_INFINITY : arr2[part_arr2];

		if (max_left_arr1 <= min_right_arr2 && max_left_arr2 <= min_right_arr1)
		{
			// found the median position
			//Check if the total array length is eve or odd and there are 2 cases based on this
			if ((len1 + len2) % 2 == 0)
			{
				average = (max(max_left_arr1, max_left_arr2)+ min(min_right_arr1, min_right_arr2)) / 2.0;
				break;
			}
			else
			{
				average = max(max_left_arr1, max_left_arr2);
				break;
			}
		}
		else if(max_left_arr1 > min_right_arr2)
		{
			/* In general case maximum on left of partition in arr1 and arr2 is less than minimum on right of partition
			   arr1 and arr2 */
			
			// if the maximum on left of array1 is greater than minimum on right of array2
			// then we have to move partition to the left of the current partition
			
			end = part_arr1-1;
		}
		else
		{
			/*if the maximum on right of left of partiion on arr2 is greater than minimum on right of partition in arr1
				=> in this case we have to move parition to the right of current partition
			*/

			start = part_arr1+1;
		}
	}
	return average;
}

int main()
{
	vector<int> arr1{ 1,2 };
	vector<int> arr2{ 3,4 };
	double median = MeidanOfTwoSortedArrays(arr1, arr2);
	cout << "Median of 2 sorted arrays is: " << median << endl;
	return 0;
}