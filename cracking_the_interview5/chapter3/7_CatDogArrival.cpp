#include<cstdio>

using namespace std;

struct Node {
	Node *prev;
	Node *next;
	bool val;
	int count;
	Node(bool val, int cnt){
		this->val = val;
		this->count = cnt;
		prev=next=NULL;
	}
};

struct AnimalQueue {
	Node* head ;
	Node* tail ;
	Node* dog ;
	Node* cat ;

	AnimalQueue(){
		head = tail = dog = cat = NULL;
	}
	void insert(Node* node){
		if(head != NULL){
			tail->next = node;
			node->prev = tail;
			tail = node;
		} else {
			head = tail = node;
		}

		if(dog == NULL && node->val == 0){
			dog = node;
		} else if(cat == NULL && node->val ==1){
			cat = node;
		}
	}

	void push(bool val, int count){
		insert(new Node(val, count));
	}

	Node* nextNode(Node* node, int val){
		if(node == NULL) return NULL;
		while(node->next){
			if(node->next->val == val) return node->next;
			node = node->next;
		}
		return NULL;
	}

	Node* dequeueAny(){
		if(head == NULL){
			printf("Queue is Empty\n");
			return NULL;
		}
		Node* node = head;

		if(node->val == 0)
			dog = nextNode(dog, node->val);
		else 
			cat = nextNode(cat, node->val);

		if(head->next == NULL){
			head = tail = dog = cat = NULL;
		} else {
			head = head->next;
			head->prev->next = NULL;
			head->prev = NULL;
		}
		return node;
	}

	Node* dequeueDog(){
		if(dog == NULL){
			printf("No Dog Available\n");
			return NULL;
		}

		if(head == dog) return dequeueAny();
		Node* node = dog;
		Node* nextDog = nextNode(dog, 0);
		dog->prev->next = dog->next;
		if(dog->next) dog->next->prev = dog->prev;
		dog->next = dog->prev = NULL;
		dog = nextDog;
		return node;
	}

	Node* dequeueCat(){
		if(cat == NULL){
			printf("No Cat Available\n");
			return NULL;
		}
		if(head == cat) return dequeueAny();
		Node* node = cat;
		Node* nextCat = nextNode(cat, 1);
		cat->prev->next = cat->next;
		if(cat->next) cat->next->prev = cat->prev;
		cat->next = cat->prev = NULL;
		cat = nextCat;
		return node;
	}

	bool empty(){
		return head==NULL;
	}
};

int main(){
	int op, val=0;
 	bool flag = true;
 	AnimalQueue q = AnimalQueue();
	while(flag){
		scanf("%d",&op);
		switch(op){
			case 0 : // push dog
				q.push(0, val++);
				break;
			case 1 : //push 
				q.push(1, val++);
				break;
			case 2 :{
				Node* animal = q.dequeueAny();
				if(animal)
					printf("%s-%d\n", animal->val==0?"dog":"cat", animal->count);
				break;
			}
			case 3 : {
				Node* dog = q.dequeueDog();
				if(dog)
					printf("dog-%d\n", dog->count);
				break;
			}

			case 4 : {
				Node* cat = q.dequeueCat();
				if(cat)
					printf("cat-%d\n", cat->count);
				break;
			}
			case 5 :
				while(!q.empty()){
					Node* animal = q.dequeueAny();
					printf("%s-%d\n", animal->val==0?"dog":"cat", animal->count);
				}
				flag = false;
				break;
		}
	}
}