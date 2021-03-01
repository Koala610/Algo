#include <iostream>
#include <math.h>

using namespace std;
int curLen = 0;
int det = 0;
void sift_down(int arr[], int pos){
	int max;
	int cur = pos - 1;
	int l = 2 * cur + 1;
	int r = 2 * cur + 2;
	if(r < curLen && arr[r] > arr[l])max = r;
	else max = l;
	if(max < curLen && arr[max] >arr[cur]){
		swap(arr[max],arr[cur]);
		sift_down(arr,max+1);
	}else{
		if(det == 0){
			if(pos-1 == curLen){
				cout << 0 << " ";
			}else{
				cout << pos  << " ";
			}
		}
			
	}
}

void sift_up(int arr[], int pos){
	if(pos > 1 && arr[int(pos/2)-1] < arr[pos-1]) {
        swap(arr[int(pos/2)-1], arr[pos-1]);
        /*int tmp = arr[int(pos/2)-1];
        arr[int(pos/2)-1] = arr[pos-1];
        arr[pos-1] = tmp;*/

        sift_up(arr,int(pos/2));
    }else{
    	if(det == 0){
    		cout << pos << endl;
    	}
    	
    }
    
}
	
	/*int endVal = 0;
	while ((pos > 1 && arr[pos-1] < arr[2*pos-1]) || (pos > 1 && arr[pos-1] < arr[2*pos])) {
		if(arr[2*pos-1] >= arr[2*pos]){
			swap(arr[2*pos-1], arr[pos-1]);
			endVal =2*pos-1;
		}else{
			swap(arr[2*pos], arr[pos-1]);
			endVal =2*pos;
		}
		//int val = arr[2*pos-1]>arr[2*pos] ? arr[2*pos-1] : arr[2*pos];
		int index = arr[2*pos-1]>arr[2*pos] ? 2*pos-1 : 2*pos;
		cout << pos << endl;
		swap(arr[index],arr[pos-1]);
		pos  = index+1;
    }
    cout << pos << endl;*/

int extract_max(int arr[]){
	int tmp = arr[0];
	swap(arr[0],arr[curLen-1]);
	curLen = curLen - 1;
	sift_down(arr,1);
	return tmp;

}

void insert(int arr[], int ins){
	curLen = curLen + 1;
	arr[curLen-1] = ins;
	sift_up(arr,curLen);
}

void deleteElem(int arr[], int index){
	det = 1;
	int cur = index - 1;
	int tmp = arr[cur];
	arr[cur] = arr[curLen-1];
	curLen = curLen - 1;
	sift_down(arr,index);
	sift_up(arr,index);
	

	cout <<  tmp << endl;
	det = 0;

}

int main(){
	int l; cin >> l;
	int n; cin >> n;
	int arr[l];
	
	int count = 0;
	int inp; 
	for(int i = 0; i< n;++i){
		cin >> inp;
		if(inp == 1){
			if(curLen == 0){
				cout << -1 << endl;
			}else{

				cout << extract_max(arr) << endl;
			}
			
		}
		else if(inp == 2){
			int tmp; cin >> tmp;
			if(curLen == l){
				cout << -1 << endl;

			}else{
				insert(arr,tmp);

				
			}


		}else if(inp == 3){
			int del; cin >> del;
			if(del > 0 && del <= curLen){
				deleteElem(arr,del);
			}else{
				cout << -1 << endl;
			}
		}


	}

	while(count < curLen){
		cout << arr[count] << " ";
		count++;
	}

	

}