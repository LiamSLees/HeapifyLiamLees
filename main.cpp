#include <iostream>
using namespace std;

// Function to heapify the array and build the heap and makes {12, 11, 13, 5, 6, 7}
void heapify(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int root = 0;
        while (true) {
            int leftChild = 2 * root + 1;
            int rightChild = 2 * root + 2;
            int smallest = root;

            // checks if left child is smaller than root
            if (leftChild < n && arr[leftChild] < arr[smallest]) {
                smallest = leftChild;
            }

            // checks if right is smaller than root
            if (rightChild < n && arr[rightChild] < arr[smallest]) {
                smallest = rightChild;
            }

            // continues heap if smallest is not root
            if (smallest != root) {
                swap(arr[root], arr[smallest]);
                root = smallest;
            } else {
                break;
            }
        }
    }
}

//heapsort makes it
void heapSort(int arr[], int n) {

    heapify(arr, n); // call heapify to make the heap using the n and array

    //extract the minimum elements and push to back repeatedly then call heapify afterwards
    for (int i = n - 1; i > 0; i--) {

        swap(arr[0], arr[i]);

        heapify(arr, i);
    }

//reverse the array so its smallest to biggest as needed to be in ascending order (smallest to largest)

    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - 1 - i]);
    }
}


// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test array
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    // Call the heapSort function
    heapSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}
