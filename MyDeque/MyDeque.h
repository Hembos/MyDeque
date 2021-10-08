#pragma once

#include <iostream>
#include <utility>

template <typename T>
class MyDeque
{
private:
	struct Node
	{
		Node* next = nullptr;
		Node* prev = nullptr;
		T data;
	};
	Node* head;
	Node* end;
	size_t size;

public:
	MyDeque();
	~MyDeque();

	//Copy constructor
	MyDeque(const MyDeque& other);

	//Copy assignment operator
	MyDeque& operator= (const MyDeque& other)
	{
		if (this == &other)
			return *this;

		if (size > 0)
		{
			clear();
		}

		size = other.size;

		if (other.head == nullptr)
			return *this;

		try
		{
			Node* tmp = other.head->next;
			Node* list = new Node;
			list->data = other.head->data;
			head = list;

			while (tmp != nullptr)
			{
				list->next = new Node;
				list->next->prev = list;
				list = list->next;
				list->data = tmp->data;
				tmp = tmp->next;
			}

			end = list;
		}
		catch (const std::bad_alloc& ex)
		{
			std::cerr << ex.what() << std::endl;
		}

		return *this;
	}

	//Move constructor
	MyDeque(MyDeque&& other);

	//Move assignment operator
	MyDeque& operator= (MyDeque&& other)
	{
		if (this != other)
		{
			clear();

			head = other.head;
			end = other.end;
			size = other.size;

			other.head = nullptr;
			other.end = nullptr;
			other.size = 0;
		}

		return *this;
	}

	//Add element to the beginning
	void push_front(const T& elem);
	void push_front(T&& elem);

	//Add element to the end
	void push_back(const T& elem);
	void push_back(T&& elem);

	//Get an item from the beginning and remove it from the queue
	const T& pop_front();

	//Get an item from the end and remove it from the queue
	const T& pop_back();

	//Get an item from the beginning
	const T& front();

	//Get an item from the end
	const T& back();

	//Return the size of the queue
	size_t getSize();

	//Clear queue
	void clear();

	//Print deque in console
	void print();
};

template<class T>
MyDeque<T>::MyDeque()
{
	size = 0;
	head = nullptr;
	end = nullptr;
}

template<class T>
MyDeque<T>::~MyDeque()
{
	if (end == nullptr)
		return;

	Node* prev = end->prev;

	while (end != head && prev != nullptr)
	{
		delete end;
		end = prev;
		prev = end->prev;
	}

	delete head;
}

template<typename T>
MyDeque<T>::MyDeque(const MyDeque& other)
{
	try
	{
		if (other.head == nullptr)
		{
			size = 0;
			head = nullptr;
			end = nullptr;
			return;
		}
			
		size = other.size;

		Node* tmp = other.head->next;
		Node* list = new Node;
		list->data = other.head->data;
		head = list;
		
		while (tmp != nullptr)
		{
			list->next = new Node;
			list->next->prev = list;
			list = list->next;
			list->data = tmp->data;
			tmp = tmp->next;
		}

		end = list;
	}
	catch (const std::bad_alloc& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

template<typename T>
MyDeque<T>::MyDeque(MyDeque&& other)
{
	head = other.head;
	end = other.end;
	size = other.size;

	other.head = nullptr;
	other.end = nullptr;
	other.size = 0;
}

template<class T>
void MyDeque<T>::push_front(const T& elem)
{
	try
	{
		if (head == nullptr)
			return;

		Node* newNode;

		newNode = new Node;
		newNode->data = std::move(elem);

		newNode->next = head;

		if (head != nullptr)
			head->prev = newNode;

		head = newNode;

		if (end == nullptr)
			end = head;

		size++;
	}
	catch (std::bad_alloc& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

template<typename T>
void MyDeque<T>::push_front(T&& elem)
{
	try
	{
		Node* newNode;

		newNode = new Node;
		newNode->data = std::move(elem);
		newNode->next = head;

		if (head != nullptr)
			head->prev = newNode;

		head = newNode;

		if (end == nullptr)
			end = head;

		size++;
	}
	catch (std::bad_alloc& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

template<typename T>
void MyDeque<T>::push_back(const T& elem)
{
	try
	{
		Node* newNode = new Node;

		newNode->data = std::move(elem);

		newNode->prev = end;

		if (end != nullptr)
			end->next = newNode;

		end = newNode;
		if (head == nullptr)
			head = end;

		size++;
	}
	catch (std::bad_alloc& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

template<typename T>
void MyDeque<T>::push_back(T&& elem)
{
	try
	{
		Node* newNode = new Node;

		newNode->data = std::move(elem);

		newNode->prev = end;

		if (end != nullptr)
			end->next = newNode;

		end = newNode;
		if (head == nullptr)
			head = end;

		size++;

	}
	catch (std::bad_alloc& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

template<typename T>
const T& MyDeque<T>::pop_front()
{
	if (head == nullptr)
		throw std::logic_error("Empty deque");

	T elem = head->data;

	Node* newHead = head->next;
	if (newHead != nullptr)
		newHead->prev = nullptr;

	delete head;
	
	if (newHead == nullptr)
		end = nullptr;

	head = newHead;

	size--;

	return elem;
}

template<typename T>
const T& MyDeque<T>::pop_back()
{
	if (end == nullptr)
		throw std::logic_error("Empty deque");

	T elem = end->data;

	Node* newEnd = end->prev;
	if (newEnd != nullptr)
		newEnd->next = nullptr;

	delete end;

	if (newEnd == nullptr)
		head = nullptr;

	end = newEnd;

	size--;

	return elem;
}

template<typename T>
const T& MyDeque<T>::front()
{
	if (head == nullptr)
		throw std::logic_error("Empty deque");
	return head->data;
}

template<typename T>
const T& MyDeque<T>::back()
{
	if (end == nullptr)
		throw std::logic_error("Empty deque");
	return end->data;
}

template<typename T>
size_t MyDeque<T>::getSize()
{
	return size;
}

template<typename T>
void MyDeque<T>::clear()
{
	if (end == nullptr)
		return;

	Node* prev = end->prev;
	delete end;

	while (prev != head && prev != nullptr)
	{
		end = prev;
		prev = end->prev;
		delete end;
	}

	delete head;
	size = 0;
	head = nullptr;
	end = nullptr;
}

template<typename T>
void MyDeque<T>::print()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		std::cout << tmp->data << std::endl;
		tmp = tmp->next;
	}
}
