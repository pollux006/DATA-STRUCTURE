// your code here!
#include "potd.h"
#include <math.h> 

int* potd::raise(int* arr) {
	int len = 1;
	for (int i = 0; arr[i] > 0; i++) {
		len++;
	}
	int* out = new int[len];

	for (int i = 0; i<len; i++){
		if (i < len - 2) {
			out[i] = pow(arr[i],arr[i+1]);
		}
		else {
			out[i] = arr[i];
		}
	}
	
	return out;
}