//
// Created by Michael Gobs on 9/10/2022.
//


#include <iostream>
using namespace std;

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int insert(int arr[],int ele)
{
    int N = sizeof(arr) / sizeof(arr[0]);
    arr[n+1] = ele;
    return sizeof(arr) / sizeof(arr[0]) ;
}

int delete_element(int arr[],int ele)
{
// Search ele in array
int i;
int n = sizeof(arr) / sizeof(arr[0]);
for (i = 0; i<n;
i++)
if (arr[i] == ele)
break;

// If ele found in array
if (i<n)
{
// reduce size of array and move all
// elements on space ahead
n = n - 1;
for (
int j = i;
j<n;
j++)
arr[j] = arr[j+1];
}
return n;
}
int highest_number(in arr[])
{
    int i;
    int n = sizeof(arr) / sizeof(arr[0]);
    // Initialize maximum element
    int max = arr[0];

    // Traverse array elements
    // from second and compare
    // every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}
// Driver's code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 }; // you can make the array dynamic
    int choice;
    int number;
    int del;
    int insert_num;
    bool flag = true;
    while (flag != false){
        cout << "*******************************\n";
        cout << " 1 - search.\n";
        cout << " 2 - Insert \n";
        cout << " 3 - Delete \n";
        cout << " 4 - Exit.\n";

        cout << " Enter your choice and press return: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Search\n";
                cout << "Enter number to Search \n";
                cin >> number;
                // Function call
                int result = search(arr, N, number);
                (result == -1)
                ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
                gameOn = false;
                break;
            case 2:
                cout << "Inserting\n";
                cout << "Enter number to Insert \n";
                cin >> insert_num;
                insert(arr,insert_num);
                cout << " Insert was done successfully \n";
                gameOn = false;
                break;
            case 3:
                cout << "Delete \n";
                cout << "Enter number to Delete \n";
                cin >> del;
                delete_element(arr,del);
                cout << " Delete was done successfully \n";
                gameOn = false;
                break;
            case 4:
                cout << "End of Program.\n";
                gameOn = false;
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
