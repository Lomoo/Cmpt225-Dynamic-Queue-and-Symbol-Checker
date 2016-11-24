#include "queue.h"
#include <cstring> 
#include <iostream>

Queue::Queue() { //default constructor
	current_size = 0;
	front_p = NULL;
	rear_p = NULL;
}

Queue::Queue(const Queue& q) { //copy constructor
	if (q.front_p == NULL) {
		front_p = NULL;
		rear_p = NULL;
		current_size = 0;
	}
	else {
		node *p = q.front_p; //update new front
		front_p = NULL;
		rear_p = NULL;
		node *newNode;
		current_size = 0; //update size
		while (p!= NULL) { //while we can go through queue to copy
			if (current_size <= 0) { //if first node
				newNode = new node(p->data, NULL);
				front_p = newNode;
				rear_p = newNode;
				current_size++;
			}
			else {//else enqueue
				enqueue(p->data);
			}
				p = p->next; //update itterations
		}
	}
}
Queue::~Queue() { //destructor
	node *p = front_p;
	while (p != NULL) {
		node *temp = p;
		delete temp;
		p = p->next;
	}
	front_p = NULL;
	current_size = 0;

}

void Queue::enqueue(int item) {
	if (front_p == NULL) { // empty list
		node *firstNode;
		firstNode = new node(item, NULL);
		front_p = firstNode;
		rear_p = firstNode;
		current_size++;
	}
	else {
		node *newNode;
		newNode = new node(item, NULL);
		rear_p->next = newNode;
		rear_p = newNode;
		current_size++;	
	}

}

int Queue::dequeue() {
	if (front_p == NULL) {
		rear_p = NULL;
		return 0; //not sure what to return so will return 0 here
	}
	else {
	node *temp;
	temp = front_p;
	int rData = front_p->data;
	front_p = front_p->next;

	delete temp;
	current_size--;
	return rData;
	}
}

int Queue::front() {
	if (front_p == NULL) {
		return 0; //not sure what to return so will return 0 here
	}
	else {
		return front_p->data;
	}
}

bool Queue::empty() {
	if (front_p == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Queue::size() {
	node *p = front_p; //temp node
	int size_R = 0;
	while (p!=NULL) {
		size_R++;
		p = p->next;
	}
	
	return size_R;
}
int Queue::delay(int item) {
	node *temp;
	temp = front_p;
	int occurance = 0;
	while (temp != NULL) { //traverse queue
		if (temp->data == item) { //if equal to target 
			occurance++;
		}
		temp = temp->next;
	}
	if (front_p == NULL) { //empty list
		return 0;
	}
	else if (occurance == 0) { //if no occurance
		return 0;
	}
	else { //if occurance happens 
		int nodeData = 0;
		int current_size_temp = current_size;
		if (front_p->data == item) { //check to see if front
			node *temp2 = front_p;
			nodeData = front_p->data; //make a variable to hold data in current node
			front_p = front_p->next;
			delete temp2; //delete the node where we found our data
			current_size--; //since we are deleting a node update current size
			enqueue(nodeData); //because we are asked to have all the numbers at the end we can just enqueue
			
		}
		node *p = front_p->next;
		node *pLeft = front_p;
		for (int i=0; i <current_size_temp-1; i++) { //if not front itterate through the list, minus 1 from current size because we already checked front
			{//since we are constantly adding and removing from queue but the size never changes we just loop through how many nodes we have
				if (p->data == item) {
					node *temp3;
					nodeData = p->data;
					temp3 = p;
					p = p->next;
					pLeft->next = temp3->next;
					delete temp3;
					current_size--;
					enqueue(nodeData);
				}
				else { // advance node regardless
					p = p->next;
					pLeft = pLeft->next;
				}
			}
		}
		return occurance;
	}

}