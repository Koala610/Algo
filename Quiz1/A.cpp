#include <iostream>
using namespace std;

struct Node {
	string word;
	Node* next;

	Node() {}

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here


Node* cyclicShift(Node* head, int k) {
	int cnt = 0;
	int n = 0;
	int n1 = 0;
	Node* cur = head;
	Node* last;
	
	while(cur != NULL){
		cur = cur -> next;
		n++;
	}
	for(int i = 0; i< k;i++){
		cur = head;
		n1 = 0;
		for(int i = 0;i<=n; i++){
			if(i == n - 1){
				cur -> next  = new Node(head -> word);
			}
			++n1;
			cur = cur -> next;

		}
		head = head ->next;

		

	}
	//cur = head;
	/*for(int i = 0;i<n; i++) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;*/
	return head;



}

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
	print(head);
}