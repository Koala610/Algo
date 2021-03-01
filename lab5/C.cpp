#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;cin>>n;
	string s1,s2;
    cin>>s1;cin>>s2;
    string s3 = s1+s1;
    int count = 0;
    bool det = false;
    for(int i = s1.size(); i>=0;i--){
        if(s3.substr(i,s2.size()) == s2){
            det = true;
            break;
        }else{
            count++;
        }      
    }
    if(det == false ){
        cout << -1;
    }else{
        cout << count;
    }

  


}