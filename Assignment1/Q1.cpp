#include <iostream>
using namespace std;

int *arr;
int element = 0;

int choice() {
    cout << "\n---MENU---\n1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
    int ch;
    cout << "What do you want to do (enter number): ";
    cin >> ch;
    return ch;
}

void createArray() {
    int i;
    cout << "How many elements of array do you want?: ";
    cin >> element;
    arr = (int*)malloc(element*sizeof(int));
    for(i=0;i<element;i++){
        cout << "Enter number "<<i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Array created";
    cout << "\n";
}

void display(){
    int i;
    if (arr == NULL || element == 0){
        cout << "Please create an array first!";
    } else {
        for(i=0; i<element; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}

void insert(){
    int i, new_val, index;
    if (arr == NULL || element == 0){
        cout << "Please create an array first!";
    } else {
        cout << "Value to be inserted: ";
        cin >> new_val;
        while (1){
            cout << "\nEnter index: ";
            cin >> index;
            if (index <= 0 || index >= element) {
                cout << "Out of bound index. Enter a valid index!";
            } else {
                break;
            }
        }
        element++;
        arr = (int*)realloc(arr, element*sizeof(int)); 
        for(i=element-1; i>index; i--){               
            arr[i] = arr[i-1];
        }
        arr[index] = new_val;

    }
}

void del(){
    int i, index;
    if (arr == NULL || element == 0){
        cout << "Please create an array first!";
    } else {
        while (1){
            cout << "\nEnter index value to be deleted: ";
            cin >> index;
            if (index <= 0 || index >= element) {
                cout << "Out of bound index. Enter a valid index!";
            } else {
                break;
            }
       }
        element--;
        arr = (int*)realloc(arr, element*sizeof(int)); 
        for(i=index; i<element; i++){               
            arr[i] = arr[i+1];
        }

    }
}

void search(){
    int s, i;
    if (arr == NULL || element == 0){
        cout << "Please create an array first!";
    } else {
        bool found = false;
        cout << "Element to be searched: ";
        cin >> s;
        for (i=0; i<element; i++){
            if (arr[i] == s){
            cout << "Found at index "<<i;
            found = true;
            break;
            }
        }

        if (!found) {
            cout << "Value not found in array!";
        }

    }
}

int main() {
    int c;
    int *arr, element=0, i, new_val, index, s;
    while(1) {
        c = choice();
        if (c == 1){
            createArray();
        }

        if (c == 2) {
            display();
        }

        if (c == 3){
            insert();
        }

        if (c == 4){
           del(); 
        }

        if (c == 5){
            search();
        } 

        if (c == 6) {
            cout << "\nTHANK YOU!";
            return 0;
        }
    }
}