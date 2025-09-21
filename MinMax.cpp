#include<iostream>
using namespace std;

// Function to find minimum and maximum element in an array using linear search
void minmax(int array[], int start, int end)
{
    int min_index; // Index of the minimum element
    int max_index; // Index of the maximum element
    int i = start; // Start index for traversal

    // Initialize min_index and max_index with the starting index
    min_index = i;
    max_index = i;

    // Loop through the array from start+1 to end-1
    for(int j = i + 1; j < end; j++)
    {
        // Update min_index if the current element is smaller than the element at min_index
        if(array[min_index] > array[j])
        {
            min_index = j;
        }
        // Update max_index if the current element is greater than the element at max_index
        if(array[max_index] < array[j])
        {
            max_index = j;
        }
    }
    // Print the minimum and maximum elements
    cout << endl << "Minimum element is: " << array[min_index];
    cout << endl << "Maximum element is: " << array[max_index];
}

// Function to find minimum and maximum element in an array using divide and conquer
void min_max(int array[], int i, int j, int &fmax, int &fmin)
{
    // Base case: If there is only one element in the array
    if (i == j) {
        fmax = array[i];
        fmin = array[i];
    } 
    // Base case: If there are only two elements in the array
    else if (i == j - 1) {
        // Compare the two elements and assign them to fmin and fmax
        if (array[i] < array[j]) {
            fmin = array[i];
            fmax = array[j];
        } else {
            fmin = array[j];
            fmax = array[i];
        }
    } 
    // Recursive case: If there are more than two elements in the array
    else {
        // Calculate the mid index
        int mid = (i + j) / 2;
        int gmax, gmin, hmax, hmin;
        
        // Recursively find min and max in the left half of the array
        min_max(array, i, mid, gmax, gmin);
        // Recursively find min and max in the right half of the array
        min_max(array, mid + 1, j, hmax, hmin);
     
        // Update fmax and fmin with the maximum and minimum of the left and right halves
        fmax = max(gmax, hmax);
        fmin = min(gmin, hmin);
    }
}

int main()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int array[size];
    cout << endl << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << endl;
    // Find minimum and maximum element using linear search
    minmax(array, 0, size);
    
    // Variables to store minimum and maximum elements using divide and conquer
    int max_element, min_element;
    // Find minimum and maximum element using divide and conquer
    min_max(array, 0, size - 1, max_element, min_element);

    // Print minimum and maximum elements found using divide and conquer
    cout << endl << "Minimum element using divide and conquer: " << min_element << endl;
    cout << "Maximum element using divide and conquer: " << max_element << endl;

    return 0;
}

/*int array[] array of integers, size of array not defined at compile time */

/*#include <iostream>
#include <vector>

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(const std::vector<int>& arr, int low, int high) {
    MinMax result;
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    int mid = (low + high) / 2;
    MinMax left = findMinMax(arr, low, mid);
    MinMax right = findMinMax(arr, mid + 1, high);

    result.min = std::min(left.min, right.min);
    result.max = std::max(left.max, right.max);

    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    MinMax result = findMinMax(arr, 0, n - 1);

    std::cout << "Minimum element: " << result.min << std::endl;
    std::cout << "Maximum element: " << result.max << std::endl;

    return 0;
}
*/