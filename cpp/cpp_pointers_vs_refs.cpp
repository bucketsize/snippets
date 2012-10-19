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

// parameter: pointer to an array of type int[4]
// return: pointer to a pointer
int** get2dDArray_ptr(int (*x)[4]){
	x[2][3] += 2;
	return (int**)x;
}

// parameter: pointer to an array of type int[4]
// return: pointer to a pointer
int** get2dSArray_ptr(int (*x)[4]){
	x[2][3] += 3;
	return (int**)x;
}

// parameter: reference to an array of type int[3][4]
// return: reference to an array of type int[3][4]
int (&get2dSArray_ref(int (&x)[3][4]))[3][4]{
	x[2][3] -= 2;
	return x;
}

int main(){

	int (*a)[4]; 
	a = new int[3][4];
	a[2][3] = 21;
     
    int (&b)[3][4] = (int (&)[3][4])*a;
	
	int (*x)[4] =(int (*)[4]) get2dDArray_ptr(a);
	cout << "value 2,3: " << x[2][3] << endl;
	
	int (*y)[4] =(int (*)[4]) get2dSArray_ptr(a);
	cout << "value 2,3: " << x[2][3] << endl;
	
	int (&z)[3][4] = (int (&)[3][4])get2dSArray_ref(b);
	cout << "value 2,3: " << x[2][3] << endl;	
}
