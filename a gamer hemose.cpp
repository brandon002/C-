#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
	int t;
	cin >> t;
	int n, H = 0;
	int A[10001];
	for(int i=0;i<t;i++){
		cin >> n >> H;
		
		int r =0;
		for(int j=0;j<n;j++){
			cin >> A[j];
		}
	//	int a = sizeof(A) / sizeof(A[0]);
		quickSort(A, 0, n-1);
		if(H<=A[n-1])cout<<"1"<<endl;
		else{
			r+=2*(H/(A[n-1]+A[n-2]));
			if(H%(A[n-1]+A[n-2])==0)r+=0;
			else if(H%(A[n-1]+A[n-2])<=A[n-1])r++;
			else r+=2;
			cout << r << endl;
		}
		
		
	}
}
