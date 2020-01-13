/*
Day 11: 2 D Arrays
Given a 6X6 2D Array A
define an hourglass in A like
a  b  c
   d
e  f  g

There are 16 hour glasses in A, hour glass sum is the sum of an hourglass values

Constraints
- -9 <= A[i][j] <= 9
- 0 <= i,j <= 5

Output: Print the largest (maximum) hourglass sum found in A
*/

#include <bits/stdc++.h>

using namespace std;

int check_for_i_sum(vector<vector<int>>&arr, int mRows, int mCols)
{
    int irow = 0, icol = 0, isum = 0, isummax = INT_MIN;
    if (mRows < 3) return -1;
    if (mCols < 3) return -1;

    // calculate sum of hour glass
    for (irow = 0; irow < (mRows - 2); irow++)
    {
      for (icol = 0; icol < (mCols - 2); icol++)
      {
     
        int pass = 0; isum = 0;
        for (int i = irow; i < (irow + 3); i++)
        {
            pass++;
            for (int j = icol; j < (icol + 3); j++)
            {
              if (2 == pass)
              {
                //if ((j != icol) || (j != (icol + 2)))
                //    isum += arr[i][j];
                isum += arr[i][j+1];
                break;
              } 
              else
              {
                isum += arr[i][j];
              }
            }
        }
        //cout << "irow:" << irow << "icol:" << icol << " sum: " << isum << endl;
        if (isum > isummax) isummax = isum;
      }
    }

   
    return isummax;
}

int main()
{
    vector<vector<int>> arr(6);
    int matrixRows = 6;
    int matrixCols = 6;
    int maxSum = 0;

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

/*
Iterate over the array

*/
  maxSum = check_for_i_sum(arr, matrixRows, matrixCols);

  cout << maxSum << endl;
  
    return 0;
}

