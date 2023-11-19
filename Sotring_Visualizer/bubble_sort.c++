#include <bits/stdc++.h>
#include<random>
using namespace std;

void printVector(vector<int> arr){
    for (auto x : arr) cout<<x<<" ";
}

vector<int> generateRandomVector(int size) {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> randomVector(size);
    for (int i = 0; i < size; ++i) {
        int randomNumber = rand() %100 + 1;
        randomVector[i] = randomNumber;
    }
    return randomVector;
}

pair<int, int> bubble_sort(vector<int> &arr, int size){
    int swap_counter = 0;
    int comparison_counter = 0;
    for (int i = size-1; i>=0; i--){
        bool is_sorted = true;
        for (int j = 0; j<i; j++){
            //Comparing here
            comparison_counter++;
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); // Swapping here
                swap_counter++;
                is_sorted = false;
                printVector(arr);
                cout<<" ------------- Swapped Elements -> "<<arr[j]<<" "<<arr[j+1]<<endl;
            }
        }
        if (is_sorted) {
            cout <<" Array is now sorted !!"<<endl;
            return {swap_counter, comparison_counter};
        }
        cout<<"\n# Array after "<<size - i<<"th iteration ->";
        for (auto x: arr) cout<<x<<" ";
        cout<<endl<<endl;
    }
}

pair<int, int> bubble_sort_2(vector<int> &arr, int size){
    int swap_counter = 0;
    int comparison_counter = 0;
    for (int i = size-1; i>=0; i--){
        bool is_sorted = true;
        for (int j = 0; j<i; j++){
            //Comparing here
            comparison_counter++;
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); // Swapping here
                swap_counter++;
                is_sorted = false;
            }
        }
        if (is_sorted) {
            return {swap_counter, comparison_counter};
        }
    }
}


int main() {
    vector<int> arr = generateRandomVector(10);
    cout<<"Your Vector -> ";
    printVector(arr);
    cout<<endl;
    pair<int, int> result = bubble_sort_2(arr,10);
    cout<<"Swaps - "<<result.first<<" , "<<"Comparisons - "<<result.second;
    return 0;
}