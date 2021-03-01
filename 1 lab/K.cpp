#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long n;
	cin >> n;
	bool isPrime = true;
	for(long long i =2;i<=sqrt(n);i++){
		if(n%i==0){
			isPrime = false;
		}
	}
	if(isPrime == true){
		cout << "prime";
	}else{
		cout << "composite";
	}
}