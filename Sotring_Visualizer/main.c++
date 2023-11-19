#include <bits/stdc++.h>
#include <random>
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

// ---------------------------------------------------------------------------------------------------------------------------------------

void bubble_sort(vector<int> &arr, int size){
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
            cout <<"Array is now sorted !!"<<endl<<endl;
            cout<<"Total Number of Comparisons: "<<comparison_counter<<" , ";
            cout<<"Total Number of Swaps: "<<swap_counter<<endl;
            return ;
        }
        cout<<"\n# Array after "<<size - i<<"th iteration -> ";
        printVector(arr);
        cout<<endl<<endl;
    }
}

void selection_sort(vector<int> &arr, int size){
    int comparison_counter = 0;
    int swap_counter = 0;
    for (int i=0; i<size-1; i++){
        int min_index = i;
        for (int j=i+1; j<size; j++){
            //Comparison here
            comparison_counter++;
            if (arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        if (i != min_index){
            //swapping here
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
    return ;
}

void insertion_sort(vector<int> &arr, int size){
    int comparison_counter = 0;
    int swap_counter = 0;
    for(int i=1; i<size;i++){
        int temp_counter = 0;
        for (int j = i; j>0; j--){
            //Comparison here
            comparison_counter++;
            if (arr[j-1] > arr[j]){
                //swapping here
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
    return ;
}

void Sort_Analyzer_Menu(){
    cout<<"\n\n#### SORT ANALYZER MENU ####\n\n";
    cout<<"Select any one option\n\n";
    cout<<"1. Bubble Sort"<<endl;
    cout<<"2. Selection Sort"<<endl;
    cout<<"3. Insertion Sort"<<endl;
    cout<<"4. Return To Main Menu"<<endl<<endl;
    int ch, size;
    cout<<"Enter your choice: ";
    cin>>ch;
    cout<<endl;
    switch (ch)
    {
        case 1: {
            cout<<"Enter the required size of array: ";
            cin>>size;
            cout<<endl;
            vector<int> arr = generateRandomVector(size);
            cout<<"Your Array: ";
            printVector(arr);
            cout<<endl<<endl;
            cout<<"Logic Behind Bubble Sort -> Pushes the maximum element to last, by adjacent swapping in each iteration"<<endl<<endl;            
            cout<<"Sorting the array using BUBBLE SORT ->"<<endl<<endl;
            bubble_sort(arr,size);
            Sort_Analyzer_Menu();
        }break;

        case 2: {
            cout<<"Enter the required size of array: ";
            cin>>size;
            cout<<endl;
            vector<int> arr = generateRandomVector(size);
            cout<<"Your Array: ";
            printVector(arr);
            cout<<endl<<endl;
            cout<<"Logic Behind Selection Sort -> Select the minimum element, and push it towards front"<<endl<<endl;            
            cout<<"Sorting the array using SELECTION SORT ->"<<endl<<endl;
            selection_sort(arr,size);
            Sort_Analyzer_Menu();
        }break;
        
        case 3: {
            cout<<"Enter the required size of array: ";
            cin>>size;
            cout<<endl;
            vector<int> arr = generateRandomVector(size);
            cout<<"Your Array: ";
            printVector(arr);
            cout<<endl<<endl;
            cout<<"Logic Behind Insertion Sort -> Pick an element and swap it with left adjacent element untill it is larger then the left adjacent element"<<endl<<endl;            
            cout<<"Sorting the array using INSERTION SORT ->"<<endl<<endl;
            insertion_sort(arr,size);
            Sort_Analyzer_Menu();

        }break;

        case 4: {
            return;

        }break;

        default:{
            cout<<"Invalid Input !!"<<endl;
            Sort_Analyzer_Menu();
        }break;
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------------

pair<int, int> bubble_sort_2(vector<int> arr, int size){
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

pair<int, int> insertion_sort_2(vector<int> arr, int size){
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

pair<int, int> selection_sort_2(vector<int> arr, int size) {
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


void Sort_Comparer_Menu(){
    cout<<"\n\n#### SORT COMPARER MENU ####\n\n";
    cout<<"Select any two sorting algorithm"<<endl;
    cout<<"A -> Bubble Sort"<<endl;
    cout<<"B -> Insertion Sort"<<endl;
    cout<<"C -> Selection Sort"<<endl;
    cout<<"X -> Return To Main Menu"<<endl<<endl;
    cout<<"Enter your choices with spaces: ";
    char first, second;
    cin>>first>>second;
    cout<<endl;
    switch(first){
        case 'A': {
            if (second == 'B'){
                int size ;
                cout<<"Enter the required size of array: ";
                cin>>size;
                cout<<endl;
                vector<int> arr = generateRandomVector(size);
                cout<<"Your Vector -> ";
                printVector(arr);
                cout<<endl<<endl;
                cout<<"Comparing Bubble Sort & Insertion Sort on the above Array!!"<<endl<<endl;                
                pair<int, int> bubble_ans = bubble_sort_2(arr, size);
                pair<int, int> insertion_ans = insertion_sort_2(arr, size);
                cout<<"For Bubble Sort ->"<<endl;
                cout<<"No. of Swaps - "<<bubble_ans.first<<" , "<<"No. of Comparisons - "<<bubble_ans.second<<endl;
                cout<<"Comparisons / Swaps Ratio - "<<(bubble_ans.first * 1.0) / (bubble_ans.second * 1.0)<<endl;
                cout<<endl;
                cout<<"For Insertion Sort ->"<<endl;
                cout<<"No. of Swaps - "<<insertion_ans.first<<" , "<<"No. of Comparisons - "<<insertion_ans.second<<endl;
                cout<<"Comparisons / Swaps Ratio - "<<(insertion_ans.first * 1.0) / (insertion_ans.second * 1.0 )<<endl;
                cout<<endl;
                cout<<endl;
                if (((bubble_ans.first * 1.0) / (bubble_ans.second * 1.0)) < ((insertion_ans.first * 1.0) / (insertion_ans.second * 1.0 ))){
                    cout<<"So According to Comparisons / Swaps Ratio - Bubble Sort is efficient for this array!!!"<<endl;
                }
                else{
                    cout<<"So According to Comparisons / Swaps Ratio - Insertion Sort is efficient for this array!!!"<<endl;
                }
                Sort_Comparer_Menu();
            }
            if (second == 'C'){
                int size ;
                cout<<"Enter the required size of array: ";
                cin>>size;
                cout<<endl;
                vector<int> arr = generateRandomVector(size);
                cout<<"Your Vector -> ";
                printVector(arr);
                cout<<endl<<endl;
                cout<<"Comparing Bubble Sort & Selection Sort on the above Array!!"<<endl<<endl;                
                pair<int, int> bubble_ans = bubble_sort_2(arr, size);
                pair<int, int> selection_ans = selection_sort_2(arr, size);
                cout<<"For Bubble Sort ->"<<endl;
                cout<<"No. of Swaps - "<<bubble_ans.first<<" , "<<"No. of Comparisons - "<<bubble_ans.second<<endl;
                cout<<"Comparisons / Swaps Ratio - "<<(bubble_ans.first * 1.0) / (bubble_ans.second * 1.0)<<endl;
                cout<<endl;
                cout<<"For Selection Sort ->"<<endl;
                cout<<"No. of Swaps - "<<selection_ans.first<<" , "<<"No. of Comparisons - "<<selection_ans.second<<endl;
                cout<<"Comparisons / Swaps Ratio - "<<(selection_ans.first * 1.0) / (selection_ans.second * 1.0 )<<endl;
                cout<<endl;
                cout<<endl;
                if (((bubble_ans.first * 1.0) / (bubble_ans.second * 1.0)) < ((selection_ans.first * 1.0) / (selection_ans.second * 1.0 ))){
                    cout<<"So According to Comparisons / Swaps Ratio - Bubble Sort is efficient for this array!!!"<<endl;
                }
                else{
                    cout<<"So According to Comparisons / Swaps Ratio - Selection Sort is efficient for this array!!!"<<endl;
                }
                Sort_Comparer_Menu();
            }
            else{
                cout<<"Invalid Input !!"<<endl<<endl;
                Sort_Comparer_Menu();          
            }
        }break;

        case 'B': {
            if (second == 'A'){
                int size ;
                cout<<"Enter the required size of array: ";
                cin>>size;
                cout<<endl;
                vector<int> arr = generateRandomVector(size);
                cout<<"Your Vector -> ";
                printVector(arr);
                cout<<endl<<endl;
                cout<<"Comparing Insertion Sort & Bubble Sort on the above Array!!"<<endl<<endl;                
                pair<int, int> bubble_ans = bubble_sort_2(arr, size);
                pair<int, int> insertion_ans = insertion_sort_2(arr, size);
                cout<<"For Insertion Sort ->"<<endl;
                cout<<"No. of Swaps - "<<insertion_ans.first<<" , "<<"No. of Comparisons - "<<insertion_ans.second<<endl;
                cout<<"Comparisons / Swaps Ratio - "<<(insertion_ans.first * 1.0) / (insertion_ans.second * 1.0)<<endl;
                cout<<endl;
                cout<<"For Bubble Sort ->"<<endl;
                cout<<"No. of Swaps - "<<bubble_ans.first<<" , "<<"No. of Comparisons - "<<bubble_ans.second<<endl;
                cout<<"Comparisons / Swaps Ratio - "<<(bubble_ans.first * 1.0) / (bubble_ans.second * 1.0 )<<endl;
                cout<<endl;
                cout<<endl;
                if (((bubble_ans.first * 1.0) / (bubble_ans.second * 1.0)) < ((insertion_ans.first * 1.0) / (insertion_ans.second * 1.0 ))){
                    cout<<"So According to Comparisons / Swaps Ratio - Bubble Sort is efficient for this array!!!"<<endl;
                }
                else{
                    cout<<"So According to Comparisons / Swaps Ratio - Insertion Sort is efficient for this array!!!"<<endl;
                }
                Sort_Comparer_Menu();
            }
            if (second == 'C'){
                

            }
            else{

            }
        }break;

        case 'C': {
            if (second == 'A'){

            }
            if (second == 'B'){

            }
            else{

            }
        }break;

        case 'X': {
            if (second == 'X'){
                return;
            }
        }break;

        default : {
            cout<<"Invalid Input !!"<<endl;
            Sort_Comparer_Menu();
        }break;
    }
}

void Main_Menu(){
    cout<<"\n\n#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#- SORTING VISUALIZER #-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n\n";
    cout<<"1. Analyze Sorting Method"<<endl;
    cout<<"2. Compare Sorting Methods"<<endl;
    cout<<"3. Exit"<<endl;
    int ch;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch (ch)
    {
        case 1: {
            Sort_Analyzer_Menu();
            Main_Menu();
        }break;

        case 2: {
            Sort_Comparer_Menu();
            Main_Menu();

        }break;

        case 3: {
            cout<<"Thanks !!"<<endl;

        }break;

        default: {
            cout<<"Invalid Input !!"<<endl;
            Main_Menu();
        }break;
    }
}

main(){
    Main_Menu();
}