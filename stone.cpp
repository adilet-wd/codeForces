//
// Created by User on 1/12/2024.
//
#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    int beg, end, pL, mL, t;
    int maxM = 0;
    vector<int> p;
    vector<int> m;

    cout << "Beg: ";
    cin >> beg;
    cout << "End: ";
    cin >> end;


    cout << "Pluses: ";
    cin >> pL;
    cout << "Nums: ";
    for (int i = 0; i < pL; ++i) {
        cin >> t;
        p.push_back(t);
    }

    cout << "Multiplies: ";
    cin >> mL;
    cout << "Nums: ";
    for (int i = 0; i < mL; ++i) {
        cin >> t;
        m.push_back(t);
        if ( t > maxM) {
            maxM = t;
        }
    }

    vector<int> pos(end + 1, 0);
//    for(int i = 0; i < end + 1; i++ ) {
//        pos.push_back(0);
//    }

    for (int i = end; i >= 0; i--) {
        if ( i * maxM >= end ) {
            pos[i] = 1;
        } else {
            for (int j = 0; j < pL; j++) {
                if ( pos[ i + p[j] ] == 0 ){
                    pos[i] = 1;
                    break;
                }
            }
            for (int k = 0; k < mL; k++) {
                if ( pos[ i * m[k] ] == 0 ){
                    pos[i] = 1;
                    break;
                }
            }
        }

    }

    for (int i = 0; i <= end; i++) {
        cout << "index: " << i << " " << "value: " << pos[i] << endl;
    }

}


