//
// Created by michael on 9/12/2022.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/** linear search
 * normal iterations
 * asymptotic runtime O(n)
 * **/

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
/** binary search
 * middle split search
 * returns the index where the element or -1
 * asymptotic runtime O(log(n))
 * **/

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}


/** bubble sort
 * swap based sort
 * asymptotic runtime O(n**2)
 * **/

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

/** quick sort
 * Partition the array using partition function
 * Quick sort algorithm (recursive algorithm limited to stack memory)
 * asymptotic runtime  O(nlog(n))
 * **/
int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    if (start >= end)
        return;

    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}


/** tree **/
void tree()
{
    /** class for root **/
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;

            left = NULL;
            right = NULL;
        }
    };
    /*create root*/
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

}

/** linked-list
 * Structure of Linked Lists
 * **/

void linkedList(){
    struct information {
        int data;
        information* next;
    };

    int size = 20;

    // Pointer To Pointer Array
    information** head;

    // Array of pointers to info struct
    // of size
    head = new information*[size];

    // Initialize pointer array to NULL
    for (int i = 0; i < size; ++i) {
        *(head + i) = NULL;
    }

    // Traverse the pointer array
    for (int i = 0; i < size; ++i) {

        // To track last node of the list
        information* prev = NULL;

        // Randomly taking 4 nodes in each
        // linked list
        int s = 4;

        while (s--) {

            // Create a new node
            information* n = new information;

            // Input the random data
            n->data = i * s;
            n->next = NULL;

            // If the node is first
            if (*(head + i) == NULL) {
                *(head + i) = n;
            }
            else {
                prev->next = n;
            }
            prev = n;
        }
    }

    // Print the array of linked list
    for (int i = 0; i < size; ++i) {
        information* temp = *(head + i);

        // Linked list number
        cout << i << "-->\t";

        // Print the Linked List
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << '\n';
    }
}

/** utils
 * printArray prints array elements
 * **/

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver's code
int main(void)
{
    /**  you can make the arrays dynamic **/

    int arr[] = { 21,34,57,78, 3, 4, 10, 40 ,5,7,8, };
    int arr1[] = { 21,34,57,78,2, 3, 4, 10, 40 ,45,12,34,56,89,};

    int choice, n, n1;
    int number, result , result_bin;
    int search_num;
    bool flag = true;
    while (flag != false){
        cout << "*******************************\n";
        cout << " 1 - Linear Search.\n";
        cout << " 2 - Binary Search \n";
        cout << " 3 - Bubble Sort \n";
        cout << " 4 - Quick Sort \n";
        cout << " 5 - LinkedList \n";
        cout << " 6 - Binary Tree Data Structure \n";
        cout << " 7 - End The Program  !!!!\n";

        cout << " Enter your choice and press return: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Do a Linear Search of a number of your choice.\n";
                cout << "Enter number to Search \n";
                cin >> number;
                // Function call
                 result = search(arr, n, number);
                (result == -1)
                ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
                flag = false;
                break;
            case 2:
                cout << "Do a Binary Search of a number of your choice.\n";
                cout << "Enter number to Search \n";
                cin >> search_num;
                result_bin = binarySearch(arr, 0,n-1, search_num);
                (result == -1)
                ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result_bin;
                flag = false;
                break;
            case 3:
                cout << "Bubble sort The array \n";
                 n = sizeof(arr) / sizeof(arr[0]);
                bubbleSort(arr,n);
                printArray(arr,n);
                cout << " Sorted successfully \n";
                flag  = false;
                break;
            case 4:
                cout << "Quick sort The array \n";
                 n1 = sizeof(arr1) / sizeof(arr1[0]);
                quickSort(arr1,0,n-1);
                printArray(arr1,n1);
                cout << " Sorted successfully \n";
                flag  = false;
                break;
            case 5:
                cout << "linked list.\n";
                linkedList();
                flag  = false;
                break;
            case 6:
                cout << "Tree Algorithm.\n";
                tree();
                cout << "Binary Tree has been created successfully !!";
                flag  = false;
                break;
            case 7:
                cout << "End of Program.\n";
                flag  = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
    }

    return 0;
}