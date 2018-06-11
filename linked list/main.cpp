

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class linkList
{
	Node* head;
	Node* tail;

public:
	linkList(){ head = nullptr; tail = nullptr; };
	~linkList();
	void createNode(int a);
	void display();
	void append(int a);
	void insert(int pos, int a);
	bool del(int pos);
	void reverse();

};

linkList::~linkList()
{
	Node* temp = head;
	Node* remove = temp;
	while (temp != nullptr){
		temp = temp->next;
		//cout << remove <<" delete value=" << remove->data<< endl;
		delete remove;
		remove = temp;
	}

}

void linkList::createNode(int a)
{
	Node* temp = new Node;
	temp->data = a;
	temp->next = nullptr;

	if (head == nullptr){
		head = temp;
		tail = temp;
		temp = nullptr;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
}

void linkList::display()
{
	Node *temp;
	temp = head;
	while (temp != nullptr){
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}

void linkList::append(int a)
{
	Node* temp = new Node;
	temp->data = a;
	temp->next = nullptr;

	tail->next = temp;
	tail = temp;
}


//insert value a into pos position, position start from 0. if pos>total number, append a to the end 
void linkList::insert(int a, int pos = 0)
{
	if (head == nullptr){
		createNode(a);
		return;
	}
	Node *temp = new Node;
	temp->data = a;
	temp->next = nullptr;

	Node *cur = head;
	Node *post = nullptr;

	if (pos > 0){
		for (int i = 0; i < pos - 1; i++){
			cur = cur->next;
			if (cur == tail){
				tail = temp;
				break;
			}
		}
		post = cur->next;
		cur->next = temp;
		temp->next = post;
	}
	else{
		temp->next = head;
		head = temp;
	}

}


//delete node in pos position, position start from 0. if pos>total number, delete the last one
bool linkList::del(int pos)
{
	if (head != nullptr){
		Node* temp = head;
		Node* prev = nullptr;
		int i = 0;
		if (pos == 0){
			head = temp->next;
			delete temp;
			return true;
		}
		while (i < pos){
			if (temp == tail) break;
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = temp->next;
		delete temp;
		return true;
	}
	else
		return false;
}

void linkList::reverse()
{
	Node* cur = head;
	Node* prev = nullptr;
	Node* post = cur->next;
	tail = head;
	while (post != nullptr){
		cur->next = prev;
		prev = cur;
		cur = post;
		post = post->next;
	}
	head = cur;
	cur->next = prev;

}


int main()
{
	int i = 0;
	while (i < 10){
		cout << i << "\t";
		i++;
	}
	cout << endl;
	cout << "-------------------------------------------------------------------------------------"<<endl;


	linkList list1;
	list1.createNode(2);
	list1.append(3);
	list1.append(4);
	list1.append(5);
	list1.insert(2, 2);
	list1.insert(10, 10);
	//list1.display();
	list1.insert(0);
	//list1.display();
	list1.insert(1, 1);
	list1.display();

	char res = list1.del(4)?'T':'F';
	cout <<"delete position 4  "<< res << endl;
	list1.display();
	list1.reverse();
	list1.display();
	list1.reverse();
	list1.display();



	char c;
	cin >> c;
	return 0;

}