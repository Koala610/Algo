#include <iostream>
#include <algorithm>

using namespace std;

char st[100000];
int h;

void push(int x) {
	st[h] = x;
	h++;
}

void pop() {
	h--;
}

int top() {
	return st[h-1];
}

bool empty() {
	return h == 0;
}

bool isOpening(char c) {
	return c == '(' || c == '{' || c == '[';
}

char paired(char c) {
	if (c == ')') return '(';
	if (c == ']') return '[';
	return '{';
}

int main() {
	bool isTrue = true;

	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (isOpening(s[i])) {
			push(s[i]);
		} else {
			if (top() == paired(s[i])) {
				pop();
			} else {
				isTrue = false;
			}
		}
	}
	if (!empty()){
		isTrue = false;
	}
	if(isTrue == true){
		cout << "yes";
	}else{
		cout << "no";
	}


	return 0;
}