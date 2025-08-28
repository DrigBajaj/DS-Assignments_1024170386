#include <iostream>
using namespace std;
int main(){
    cout << "Matrix size?: ";
    int n;
    cin >> n;
    int main[n];
    int low[n-1], high[n-1];
    cout << "For main diagnol "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Element "<<i+1<<": ";
        cin >> main[i];
    }

    cout << "For lower part "<<endl;
    for(int i=0; i<n-1; i++){
        cout << "Element "<<i+1<<": ";
        cin  >> low[i];
    }

    cout << "For upper part "<<endl;
    for(int i=0; i<n-1; i++){
        cout << "Element "<<i+1<<": ";
        cin  >> high[i];
    }

    for(int i=0; i<n; i++){ //[0][0],[0][1],[1][0],[1][1],[1][2],[2][1],[2][2],[2][3],[3][2],[3][3]
        for(int j=0; j<n; j++){
            if (i == j){
                cout << main[j];
            } else if(j == i+1){
                cout << high[i];
            } else if(j == i-1){
                cout << low[j];
            }
            else {
                cout << 0;
            }

            cout << " ";
        }

        cout << endl;
    }

}