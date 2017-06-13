#pragma once
#include <iostream>
/*
DOUBLY LINKED LIST TEMPLATE
Made by Pablo Bernal Alarcon, June 2017
Use it as however yee wish to use it
YEEEEEEE!!!
*/
template <typename T>
class DoublyLL {

private:
	struct Node {
		Node * Previous;
		T data;
		Node * Next;

		Node(Node * _Previous , T _data, Node * _Next = nullptr) : Previous(_Previous), data(_data), Next(_Next) {}

	};

	Node * v_Head;
	Node * v_Tail;

	int v_Size;
	
public:
	//Constructor and destructor
	DoublyLL();
	~DoublyLL();

	// Operator overloading for indexing
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	// get the size of the list
	inline int f_GetSize() const { return v_Size; }

	// add items at the head of he list or at the tail
	void f_Push_Front(T _data);
	void f_Push_Back(T _data);
	void f_Insert_At(T _data, unsigned int index);

	// Wipe out the whole list or delete a specific item from it
	void f_Clear();
	void f_Remove_At(unsigned int index);

	// method done for testing purposes
	void f_PrintContents();

};

template <typename T>
DoublyLL<T>::DoublyLL() {
	// Make a new head and tail
	v_Head = nullptr;
	v_Tail = nullptr;
	v_Size = 0;
}

template <typename T>
DoublyLL<T>::~DoublyLL() {
	f_Clear();

}

template <typename T>
T& DoublyLL<T>::operator[](unsigned int index) {
	Node * temp = v_Head;

	for (unsigned short i = 0; i < index; ++i)
	{
		temp = temp->Next;
	}

	return temp->data;
}

template <typename T>
const T& DoublyLL<T>::operator[](unsigned int index) const {
	Node * temp = v_Head;

	for (unsigned short i = 0; i < index; ++i)
	{
		temp = temp->Next;
	}

	return temp->data;
}

template <typename T>
void DoublyLL<T>::f_Push_Front(T _data) {
	//make a new node
	Node * inserted = new Node(v_Tail, _data, v_Head);
	

	//check for 2 cases: Empty list, one or more Nodes.

	//Empty list
	if (v_Size == 0)
	{
		v_Head = v_Tail = inserted;
		++v_Size;
	}
	//One or more nodes 
	else 
	{
		inserted->Previous = nullptr;
		inserted->Next = v_Head;
		v_Head = inserted;
		++v_Size;
	}
	
	

}

template <typename T>
void DoublyLL<T>::f_Push_Back(T _data) {

	//make a new node
	Node* n = new Node(v_Tail, _data);

	//check for 2 cases: Empty list, one or more Nodes.

	if (v_Size != 0)
		v_Tail->Next = n;
	else
		v_Head = n;

	v_Tail = n;
	++v_Size;

}

template<typename T>
void DoublyLL<T>::f_Insert_At(T data,unsigned int index) {

	if (index > (f_GetSize() - 1)) return;

	if (index == 0)
		f_Push_Front(data);
	else if (index == (f_GetSize() - 1))
		f_Push_Back(data);
	else
	{
		

		Node * iter = v_Head;

		for (int i = 0; i < index; i++)
		{
			iter = iter->Next;
		}

		Node * toInstert = new Node(iter->Previous->Next, data, iter);
		iter->Previous->Next = toInstert;
		iter->Previous = toInstert;
	}

	v_Size++;
}

template<typename T>
void DoublyLL<T>::f_PrintContents() {

	Node * current = v_Head;
	for (unsigned short i = 0; i < v_Size; i++)
	{
		if (current == nullptr) continue;

		std::cout << current->data << ", ";
		current = current->Next;
	}

	std::cout << std::endl;
}

template<typename T>
void DoublyLL<T>::f_Clear() {

	Node * toDelete = v_Head;
	Node * last;
	while (toDelete)
	{
		last = toDelete->Next;
		delete toDelete;
		toDelete = last;

	}

	v_Head = nullptr;
	v_Tail = nullptr;
	v_Size = 0;
	
}

template <typename T>
void DoublyLL<T>::f_Remove_At(unsigned int index) {

	if (index > v_Size) return;

	Node * toDelete = v_Head;
	//delete First
	if (0 == index)
	{
		v_Head = v_Head->Next;
		delete toDelete;
		v_Head->Previous = nullptr;
		return;
	}
	//Delete Last
	else if (v_Size - 1 == index) 
	{
		toDelete = v_Tail;
		v_Tail = toDelete->Previous;
		delete toDelete;
		v_Tail->Next = nullptr;
		return;
	}


	//Any other
	for (int i = 0; i < index; i++)
	{
		toDelete = toDelete->Next;
	}

	toDelete->Previous->Next = toDelete->Next;
	delete toDelete;
}

