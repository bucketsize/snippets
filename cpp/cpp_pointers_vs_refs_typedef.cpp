#include <cstdlib>
#include <iostream>

using namespace std;

// Note: to pass a array[2][3], by reference
// we need only specify the inner dimension
// and leave the outer enclosure addressed by a pointer
// hence we dont completely specify the dimension when
// using a pointer to pass an array.
// but using a reference to pass an array, need to 
// specify the complete dimension of all enclosures.
// Seen in examples below.

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
