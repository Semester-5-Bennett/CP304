#include <iostream>
using namespace std;
 
// Function to calculate sum of elements of array
int getSum(int X[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += X[i];
    return sum;
}
 
void findSwapValues(int A[], int n, int B[], int m)
{
    // Calculation of sums from both arrays
    int sum1 = getSum(A, n);
    int sum2 = getSum(B, m);
 
    // Look for val1 and val2, such that
    // sumA - val1 + val2 = sumB - val2 + val1
    int newsum1, newsum2, val1, val2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            newsum1 = sum1 - A[i] + B[j];
            newsum2 = sum2 - B[j] + A[i];
            if (newsum1 == newsum2) {
                val1 = A[i];
                val2 = B[j];
            }
        }
    }
 
    cout << val1 << " " << val2;
}

int main()
{
    //test case 1
	int A[] = { 4, 1, 2, 1, 1, 2 };
    int B[] = { 3, 6, 3, 3 };

    // //test case 2
	// int A[] = { 5,7,4,6 };
    // int B[] = { 1,2,3,8 };
    
    // //test case 3
	// int A[] = { 4, 1, 2, 1, 1, 2 };
    // int B[] = { 1, 6, 3, 3 };    

	int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

	findSwapValues(A, n, B, m);
	return 0;
}
