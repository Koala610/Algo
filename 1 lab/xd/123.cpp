#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a1 = 0.3;
	double a2 = 0.29;
	double a3 = 0.32;
	double a4 = 0.33;
	double a5 = 0.27;
	double avg = (a1+a2+a3+a4+a5)/5;
	double arr[5] = {0.3,0.29,0.32,0.33,0.27};
	double E;
	double dlt;
	for(int i = 0; i<5;i++){
		dlt = sqrt(avg*avg - arr[i]*arr[i]);
	}
	cout << dlt / avg;
}

