/*
ID: tyeh1
LANG: C++
PROB: beads
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node {
	char data;
	Node * prev;
	Node * next;
};

class CharList
{
public:
	CharList() {  head= NULL; len = 0; }
   	void  insert(char t) 
   	{
   		Node * newNode = new(Node);   		
   		newNode->data = t;
   		if (head == NULL) { // first node
   			head = newNode;
   			newNode->next = head;
   			newNode->prev = head;
   		}
   		else {
   			newNode->next = head;
   			newNode->prev = head->prev;
   			newNode->next->prev = newNode;
   			newNode->prev->next = newNode;
   			head = newNode;
   		}	
      	len++;
   	}

	void remove()
	{
		Node * oldhead;
		oldhead = head;
		oldhead->prev->next = oldhead->next;
		oldhead->next->prev = oldhead->prev;
		head = oldhead->next;		
		delete (oldhead);
		len--;
	}

	int addPrev(Node * node, char value) { 
		if (node == head) return 1;
		if ( (node->data == 'w') || (node->data == value) ) return (1 + addPrev(node->prev, value));
		else return 0; 
		
	}
	
	int addNext(Node * node, char value) {
		if (node == tail) return 1;
		if ( (node->data == 'w') || (node->data == value) ) return (1 + addNext(node->next, value));
		else return 0;
	}
   	
   	void cut() {
   		tail = head->prev;
   	}
   
   	void moveby1() {
   		head = head->next;
   	}	
   	
	void display()
	{
     	Node * ptr;
     	ptr = head;
     	do {
     		cout << ptr->data << " " ;
     		ptr = ptr->next;
     	} while (ptr != head);
     	
     	cout << "\n";
   	}
   	Node * head;
   	Node * tail;
   	int len;
private:   
};

int main()
{
   	CharList *s = new CharList();
   	Node * bnode, * enode; 
	string line;
	ifstream myfile("beads.in");
	ofstream myout("beads.out");
	int n=0;
	getline(myfile, line);
	stringstream ss(line);
	ss >> n;
	getline(myfile, line);
	for (int i=n-1; i>=0; i--) s->insert(line[i]);
   	s->display();
   	int largest = 0;
   	for (int i=0; i<s->len; i++) {
   		int answer = 0;
   		s->cut();
   		bnode = s->head;
   		enode = s->tail;
   		while ((bnode->data == 'w') && (answer <= s->len)) {answer++; bnode = bnode->next;}
   		while ((enode->data == 'w') && (answer <= s->len)) {answer++; enode = enode->prev;} 
   		if (answer >= s->len) { largest = s->len; break;}
   		answer = answer + s->addNext(bnode, bnode->data) + s->addPrev(enode, enode->data);
   		if (answer > largest) largest = answer;
   		cout << answer << endl;
   		s->moveby1();
   	}
   	if (largest > s->len) largest = s->len;
   	myout << largest << endl;
   	myfile.close();
   	myout.close();   	
}