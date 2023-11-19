#include <bits/stdc++.h>
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


pair<int, int> selection_sort(vector<int> &arr, int size){
    int comparison_counter = 0;
    int swap_counter = 0;
    for (int i=0; i<size-1; i++){
        int min_index = i;
        for (int j=i+1; j<size; j++){
            //Comparison
            comparison_counter++;
            if (arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        if (i != min_index){
            //swapping
            swap_counter++;
            swap(arr[i], arr[min_index]);
            cout<<"# Array after "<<i+1<<"th iteration ->";
            printVector(arr);
            cout<<" ------------- Swapped Elements -> "<<arr[i]<<" , "<<arr[min_index]<<endl<<endl;
            
        }
        else{
            cout<<"# Array after "<<i+1<<"th iteration ->";
            printVector(arr);
            cout<<" ------------- No Swapping "<<endl<<endl;
        }
    }
    cout <<"Array is now sorted !!"<<endl<<endl;
    cout<<"Total Number of Comparisons: "<<comparison_counter<<" , ";
    cout<<"Total Number of Swaps: "<<swap_counter<<endl;
    return {swap_counter, comparison_counter};

}


pair<int, int> selection_sort_2(vector<int> &arr, int size) {
    int comparison_counter = 0;
    int swap_counter = 0;

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            // Comparison here
            comparison_counter++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            swap_counter++;
            swap(arr[i], arr[min_index]);
        }
    }
    return {swap_counter, comparison_counter};
}



int main() {
    vector<int> arr = generateRandomVector(7);
    cout<<"Your Vector ->";
    printVector(arr);
    cout<<endl;
    
    pair<int, int> o = selection_sort_2(arr, 10);
    cout<<o.first<<" , ";
    cout<<o.second;

    return 0;
}


