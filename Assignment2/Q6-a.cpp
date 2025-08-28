#include <iostream>
using namespace std;
int main(){
    cout << "Number of rows: ";
    int row, col, nonzero;
    cin >> row;
    cout << "Number of cols: ";
    cin >> col;
    cout << "Number of non-zero: ";
    cin >> nonzero;
    int r[nonzero], c[nonzero], v[nonzero];
    for(int i=0; i<nonzero; i++){
        cout << "Enter row, col and value for element "<<i+1<<": ";
        cin >> r[i] >> c[i] >>v[i];
    }
    cout << "r c v\n-----\n";
    for(int i=0; i<nonzero; i++){
        cout << r[i]<<" "<<c[i]<<" "<<v[i]<<endl;
    }

    cout <<"Transpose: \n";
    int new_row[nonzero], new_col[nonzero], value[nonzero];
    for(int i=0; i<nonzero; i++){
       new_row[i] = c[i];
       new_col[i] = r[i]; 
       value[i] = v[i];
    }

    for(int i=0; i<nonzero; i++){
        for(int j=i+1; j<nonzero; j++){
            if (new_row[i] > new_row[j] || new_row[i] == new_row[j] && new_col[i] > new_col[j]){
                swap(new_row[i], new_row[j]);
                swap(new_col[i], new_col[j]);
                swap(value[i], value[j]);
            }
        }
    }

    cout << "r c v\n------\n";
    for(int i=0; i<nonzero; i++){
        cout << new_row[i]<<" "<<new_col[i]<<" "<<value[i]<<endl;
    }

}