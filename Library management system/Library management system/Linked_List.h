#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Linked_list
{
private:
	struct node
	{
		T data;
		node* next;
	};
	node* first, * last;
	int size;
public:
	class listIterator
	{
	private:
		friend class Linked_list;
		node* current;

	public:
		node& getCurrent()
		{
			return *current;
		}
		listIterator()
		{
			current = NULL;

		}
		listIterator(node* u)
		{
			current = u;
		}
		void operator ++ (int)
		{
			current = current->next;
		}
		listIterator& operator =(node* Node)
		{
			this->current = Node;
			return *this;
		}
		bool operator !=(const listIterator& it)
		{
			return this->current != it.current;
		}
		bool operator == (const listIterator& itr)
		{
			return (current == itr.current);
		}
	};
	void display()
	{
		if (size == 0)
		{
			cout << "There is no elements in the list yet\n";
		}
		else
		{
			node* tempNode = first;
			while (tempNode != NULL)
			{
				cout << tempNode->data << " ";
				tempNode = tempNode->next;
			}
		}
	}
	bool isEmpty()
	{
		if (size > 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	int listSize()
	{
		return size;
	}
	void push_front(T element)
	{
		node* firstNode = new node;
		firstNode->data = element;
		if (size == 0)
		{
			first = last = firstNode;
			firstNode->next = NULL;
		}
		else
		{
			firstNode->next = first;
			first = firstNode;
		}
		size++;
	}
	void push_back(T element)
	{
		node* lastNode = new node;
		lastNode->data = element;
		if (size == 0)
		{
			first = last = lastNode;
			lastNode->next = NULL;
		}
		else
		{
			last->next = lastNode;
			lastNode->next = NULL;
			last = lastNode;
		}
		size++;
	}
	void insert(int position, T element)
	{
		node* insertionNode = new node;
		insertionNode->data = element;
		if (position <= 0 || position > size)
		{
			cout << "Can't insert in " << position << " ( out of range )\n";
		}
		else
		{
			if (position == 1)
			{
				push_front(element);
			}
			else if (position == size)
			{
				push_back(element);
			}
			else
			{
				node* positionNode = first;

				for (int i = 1; i < position - 1; i++)
				{
					positionNode = positionNode->next;
				}
				insertionNode->next = positionNode->next;
				positionNode->next = insertionNode;
				size++;
			}
		}
	}
	void erase(int position)
	{
		if (position == 0)
		{
			cout << "The linked list start from 1\n";
		}
		else if (first == NULL)
		{
			cout << "The list is empty \n";
		}
		else
		{
			if (position == 1)
			{
				node* deletingNode = new node;
				deletingNode = first;
				first = first->next;
				delete deletingNode;
			}
			else
			{
				node* tempNode_1 = first, * tempNode_2 = NULL;

				for (int i = 0; i < position - 1; i++)
				{
					tempNode_2 = tempNode_1;
					tempNode_1 = tempNode_1->next;
				}
				tempNode_2->next = tempNode_1->next;
				delete tempNode_1;
			}
		}
	}
	listIterator begin()
	{
		return listIterator(first);
	}
	listIterator End()
	{
		return listIterator(nullptr);
	}
	Linked_list()
	{
		first = last = NULL;
		size = 0;
	}
	~Linked_list()
	{
		node* currentPosition = first;
		while (currentPosition != NULL)
		{
			node* nextPosition = currentPosition->next;
			delete currentPosition;
			currentPosition = nextPosition;

		}
		first = NULL;
	}
};

