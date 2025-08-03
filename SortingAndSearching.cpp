#include <iostream>
using namespace std;

// ---------------- Sorting Algorithms ----------------

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) left[i] = arr[l + i];
    for(int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------- Searching Algorithms ----------------

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ---------------- Utility Functions ----------------

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// ---------------- Main Program ----------------

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n], original[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        original[i] = arr[i];  // backup for search
    }

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n4. Quick Sort\n";
    int sortChoice;
    cin >> sortChoice;

    switch(sortChoice) {
        case 1: bubbleSort(arr, n); cout << "Sorted using Bubble Sort (O(n^2))\n"; break;
        case 2: insertionSort(arr, n); cout << "Sorted using Insertion Sort (O(n^2))\n"; break;
        case 3: mergeSort(arr, 0, n - 1); cout << "Sorted using Merge Sort (O(n log n))\n"; break;
        case 4: quickSort(arr, 0, n - 1); cout << "Sorted using Quick Sort (Avg O(n log n))\n"; break;
        default: cout << "Invalid choice\n"; return 1;
    }

    cout << "Sorted Array: ";
    printArray(arr, n);

    cout << "\nEnter element to search: ";
    int key;
    cin >> key;

    cout << "Choose Searching Algorithm:\n";
    cout << "1. Linear Search\n2. Binary Search\n";
    int searchChoice;
    cin >> searchChoice;

    int result = -1;
    if(searchChoice == 1) {
        result = linearSearch(original, n, key);  // unsorted
        cout << "Linear Search (O(n)) used.\n";
    } else if(searchChoice == 2) {
        result = binarySearch(arr, 0, n - 1, key);  // sorted
        cout << "Binary Search (O(log n)) used.\n";
    } else {
        cout << "Invalid search choice\n";
        return 1;
    }

    if(result != -1)
        cout << "Element found at index: " << result << "\n";
    else
        cout << "Element not found\n";

    return 0;
}

