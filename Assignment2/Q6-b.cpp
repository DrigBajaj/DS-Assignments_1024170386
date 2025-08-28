#include <iostream>
using namespace std;
int main(){
    cout << "Enter no.of rows: ";
    int row, col;
    cin >> row;
    cout << "Enter no. of cols: ";
    cin >> col;
    cout << "Matrix 1\nEnter no. of nonzero: ";
    int nonzero1;
    cin >> nonzero1;
    int row1[nonzero1], col1[nonzero1], value1[nonzero1];
    for(int i=0; i<nonzero1; i++){
        cout << "Enter row, col and value for element "<<i+1<<": ";
        cin >> row1[i] >> col1[i] >> value1[i];
    }

    cout << "Matrix 2\nEnter no. of nonzero: ";
    int nonzero2;
    cin >> nonzero2;
    int row2[nonzero2], col2[nonzero2], value2[nonzero2];
    for(int i=0; i<nonzero2; i++){
        cout << "Enter row, col and value for element "<<i+1<<": ";
        cin >> row2[i] >> col2[i] >> value2[i];
    }

    cout << "Row\tCol\tValue\n";

    for(int i=0; i<(row); i++){
        for(int l=0; l<col; l++){
            int val1 = 0, val2 = 0;
            for(int j=0; j<nonzero1; j++){
                if (row1[j] == i && col1[j] == l){
                    val1 = value1[j];
                    break;
                }
            }

            for(int k=0; k<nonzero2; k++){
                if (row2[k] == i && col2[k] == l){
                    val2 = value2[k];
                    break;
                }
            }

            int sum = val1+val2;
            if (sum != 0){
                cout << i << "\t" << l << "\t" << sum << endl; 
            } 

        }
        
    }


}