// algo - Takes an element and placce it in its correct order (i.e Pick an element and swap it with left adjacent element untill it is larger then the left adjacent element)

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

pair<int, int> insertion_sort(vector<int> &arr, int size){
    int comparison_counter = 0;
    int swap_counter = 0;
    for(int i=1; i<size;i++){
        int temp_counter = 0;
        for (int j = i; j>0; j--){
            //Comparison
            comparison_counter++;
            if (arr[j-1] > arr[j]){
                //swap
                temp_counter++;
                swap_counter++;
                swap(arr[j],arr[j-1]);
                printVector(arr);
                cout<<" ------------- Swapped Elements -> "<<arr[j]<<" "<<arr[j-1]<<endl;
            }
            
            else{
                break;
            }
        }
        if (temp_counter ==0) cout<<"No Swapping !!!, current element is at correct position"<<endl;
        cout<<"\n# Array after "<<i<<"th iteration ->";
        printVector(arr);
        cout<<endl<<endl;
    }
    cout <<"Array is now sorted !!"<<endl<<endl;
    cout<<"Total Number of Comparisons: "<<comparison_counter<<" , ";
    cout<<"Total Number of Swaps: "<<swap_counter<<endl;
    return {swap_counter, comparison_counter};
}


pair<int, int> insertion_sort_2(vector<int> &arr, int size){
    int comparison_counter = 0;
    int swap_counter = 0;
    for(int i=1; i<size;i++){
        int temp_counter = 0;
        for (int j = i; j>0; j--){
            //Comparison
            comparison_counter++;
            if (arr[j-1] > arr[j]){
                //swap
                temp_counter++;
                swap_counter++;
                swap(arr[j],arr[j-1]);
            }
            
            else{
                break;
            }
        }
    }
    return {swap_counter, comparison_counter};
}

int main() {
    vector<int> arr = generateRandomVector(5);
    printVector(arr);
    cout<<endl;
    pair<int, int> result = insertion_sort_2(arr,5);
    cout<<"Swaps - "<<result.first<<" , "<<"Comparison - "<<result.second<<endl;
    return 0;
}