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
    int res, r, c, val;
    cout << "Row\tCol\tValue\n";

    int resRow[nonzero1 * nonzero2], resCol[nonzero1 * nonzero2], resVal[nonzero1 * nonzero2];
    int rescount = 0;
    
    for(int i=0; i<nonzero1; i++){
        val = 0;
        for(int j=0; j<nonzero2; j++){
            if (col1[i] == row2[j]){
                r = row1[i];
                c = col2[j];
                val = value1[i]*value2[j];

                bool found = false;
                for(int k=0; k<rescount; k++){
                    if(resRow[k] == r && resCol[k] == c){
                        resVal[k] += val;
                        found = true;
                        break;
                    }
                }

                if (!found){
                    resRow[rescount] = r;
                    resCol[rescount] = c;
                    resVal[rescount] = val;
                    rescount++;
                }
            }

        }
    }

    for(int k=0; k<rescount; k++){
        if (resVal != 0){
            cout << resRow[k] << "\t" << resCol[k] << "\t" << resVal[k] << endl;
        }
    }
}