#include <cstdlib>
#include <iostream>

using namespace std;

// Note: 
// array[2][3] by reference
//  specify inner enclosure (2d: cols: in row of cols)
//  pointer referencer the outer enclosure (2d: rows)
// array[2][3] using reference
//  specify the complete dimension of all enclosures.

// parameter: pointer to an array of type int[4]
// return: pointer to a pointer
int** get2dArray_ptr(int (*x)[4]){
    x[2][3] += 2;
    return (int**)x;
}

// parameter: reference to an array of type int[3][4]
// return: reference to an array of type int[3][4]
int (&get2dArray_ref(int (&x)[3][4]))[3][4]{
    x[2][3] -= 2;
    return x;
}

int main(){
    int (*a)[4]; 
    a = new int[3][4];
    a[2][3] = 21;

    int (&b)[3][4] = (int (&)[3][4])*a;

    int (*y)[4] =(int (*)[4]) get2dArray_ptr(a);
    cout << "value 2,3: " << y[2][3] << endl;

    int (&z)[3][4] = (int (&)[3][4])get2dArray_ref(b);
    cout << "value 2,3: " << z[2][3] << endl;	
}
