#include <iostream>
#include <string>

using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i=n-1; i>=0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void sortowanie_przez_wstawianie(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void show(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << "[" << i+1 << "]: " << arr[i] << endl;
    }
    cout << endl;
}

int main() {

    int arr[] = {58, 2, 23, 50, 42, 18, 94, 1024, 422};
    int arr2[] = {58, 2, 23, 50, 42, 18, 94, 1024, 422};
    int arr3[] = {58, 2, 23, 50, 42, 18, 94, 1024, 422};
    int arr4[] = {58, 2, 23, 50, 42, 18, 94, 1024, 422};

    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, n);
    cout << "[BUBBLE]" << endl;
    show(arr, n);

    quicksort(arr2, 0, n-1);
    cout << "[QUICK]" << endl;
    show(arr2, n);

    heap_sort(arr3, n);
    cout << "[HEAP]" << endl;
    show(arr3, n);

    sortowanie_przez_wstawianie(arr4, n);
    cout << "[Wstawianie]" << endl;
    show(arr4, n);

    return 0;
}
