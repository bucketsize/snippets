#include <cstdlib>
#include <iostream>

using namespace std;

// Note: using typedef
// array[2][3] by reference
//  specify inner enclosure (2d: cols: in row of cols)
//  pointer referencer the outer enclosure (2d: rows)
// array[2][3] using reference
//  specify the complete dimension of all enclosures.

typedef int (*pIntArray)[4];
typedef int (&rIntArray)[3][4];

// parameter: pointer to an array of type int[4]
// return: pointer to a pointer
pIntArray get2dArray_ptr(pIntArray x){
    x[2][3] += 2;
    return x;
}

// parameter: reference to an array of type int[3][4]
// return: reference to an array of type int[3][4]
rIntArray get2dArray_ref(rIntArray x){
    x[2][3] -= 2;
    return x;
}

int main(){
    pIntArray a = (pIntArray) new int[3][4];
    a[2][3] = 21;

    rIntArray b = (rIntArray)*a;

    pIntArray y = (pIntArray) get2dArray_ptr(a);
    cout << "value 2,3: " << y[2][3] << endl;

    rIntArray z = (rIntArray) get2dArray_ref(b);
    cout << "value 2,3: " << z[2][3] << endl;	
}
