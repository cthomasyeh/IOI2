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
   	
   	myfile.close();
   	myout.close();   	
}