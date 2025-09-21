#include<iostream>
using namespace std;


void minmax(int array[], int start, int end)
{
    int min_index; 
    int max_index; 
    int i = start; 
    
    min_index = i;
    max_index = i;

    
    for(int j = i + 1; j < end; j++)
    {
        if(array[min_index] > array[j])
        {
            min_index = j;
        }
        if(array[max_index] < array[j])
        {
            max_index = j;
        }
    }
    cout << endl << "Minimum element is: " << array[min_index];
    cout << endl << "Maximum element is: " << array[max_index];
}

void min_max(int array[], int i, int j, int &fmax, int &fmin)
{
    if (i == j) {
        fmax = array[i];
        fmin = array[i];
    } 
    else if (i == j - 1) {
        if (array[i] < array[j]) {
            fmin = array[i];
            fmax = array[j];
        } else {
            fmin = array[j];
            fmax = array[i];
        }
    } 
    else {
        int mid = (i + j) / 2;
        int gmax, gmin, hmax, hmin;
        
        min_max(array, i, mid, gmax, gmin);
        min_max(array, mid + 1, j, hmax, hmin);

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
    minmax(array, 0, size);

    int max_element, min_element;
    min_max(array, 0, size - 1, max_element, min_element);
    cout << endl << "Minimum element using divide and conquer: " << min_element << endl;
    cout << "Maximum element using divide and conquer: " << max_element << endl;

    return 0;
}


    return 0;
}
