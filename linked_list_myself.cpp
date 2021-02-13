#include <iostream>

typedef struct _node
{
	int val; // value of node
	_node* next; // pointer of next node
	//int idx; // index of node;

} node;

class List
{
private:
	node* head;
	node* tail;
	int count = 2; // size of List

public:
	List() 
	{ 
	}

	~List() {}

	int size() const { return count; }

	int get_front() const
	{
		return head->val;
	}

	int get_back() const
	{
		return tail->val;
	}



	void add_front(int value)
	{
		node* new_head = new node;
		new_head->val = value;
		new_head->next = head;
		head = new_head;
		count++;
	}

	void add_back(int value)
	{
		node* new_back = new node;
		new_back->val = value;
		new_back->next = nullptr;
		tail = new_back;
		count++;
	}

	void add_node(int index, int value)
	{

	}

	void change_node(int index, int value)
	{

	}

	void remove_node(int index)
	{

	}

	void print_node(int index) const
	{

	}

	int get_value(int index) const
	{

	}

};

int main()
{
	List a;

	std::cout << a.size() << std::endl;

	a.add_front(1);
	a.add_back(2);

	std::cout << a.size() << std::endl;
	std::cout << a.get_front() << ", " << a.get_back() << std::endl;

	a.add_front(3);
	a.add_back(4);

	std::cout << a.size() << std::endl;
	std::cout << a.get_front() << ", " << a.get_back() << std::endl;

	a.add_front(7);
	a.add_back(5);

	std::cout << a.size() << std::endl;
	std::cout << a.get_front() << ", " << a.get_back() << std::endl;

	return 0;
}
