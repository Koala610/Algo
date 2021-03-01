#include <iostream>

using namespace std;

int curLen = 0;
void sift_down(char arr[], int pos){
	int max;
	int cur = pos-1;
	int l = 2 * cur + 1;
	int r = 2 * cur + 2;
	if(r < curLen && arr[r] > arr[l])max = r;
	else max = l;
	if(max < curLen && arr[max] >arr[cur]){
		swap(arr[max],arr[cur]);
		sift_down(arr,max+1);
		}
}

void build_heap(char arr[],int l) {
	int start = (l / 2) -1;
	for(int i = start;i >= 0; i--){
		sift_down(arr,i+1);
	}
}

void pyramid(char arr[]){
	build_heap(arr,curLen);
	while(curLen != 0){
		swap(arr[curLen-1],arr[0]);
		curLen--;
		sift_down(arr,1);
	}

}



int main(){
	char vowel[] = {'a','A','e','E','i','I','o','O','u','U'};
	int n; cin >> n;
	string s; cin >> s;

	int c = n;
	int v = 0;
	
	int vLen = sizeof(vowel)/sizeof(vowel[0]);
	for(int i = 0 ;i< n;i++){
		for(int j = 0 ;j< 10;j++){
			if(s[i] == vowel[j]){
				v++;
				break;
			}

		}

	}
	c = n -v;
	char vow[v];
	char con[c];
	int det = 0;
	int count1,count2 = 0;
	for(int i = 0 ;i< n;i++){
		
		for(int j = 0 ;j< vLen;j++){
			
			if(s[i] == vowel[j]){
				vow[count1] = s[i];
				count1++;
				det = 1;
				break;
			}
		}
		if(det == 0){
			con[count2] = s[i];
			count2++;
		}
		det = 0;

	}

	curLen = v;
	pyramid(vow);
	curLen = c;
	pyramid(con);
	string res = "";
	for(int i = 0;i<v;i++){
		cout << vow[i];
	}
	for(int i = 0; i< c;i++){
		cout <<  con[i];
	}
}