#include <iostream>
#include <assert.h>

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
		node* new_head = new node;
		node* new_tail = new node;

		head = new_head;
		tail = new_tail;

		head->next = tail;
		tail->next = nullptr;

		head->val = 0;
		tail->val = 0;

		//delete new_head;
		//delete new_tail;
	}

	~List() 
	{
	}

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
		node* new_front = new node;
		new_front->val = value;
		new_front->next = head;
		head = new_front;
		count++;
	}

	void add_back(int value)
	{
		node* new_back = new node;
		new_back->val = value;
		new_back->next = nullptr;
		tail->next = new_back;
		tail = new_back;
		count++;
	}

	void add_node(int index, int value)
	{
		if (index == 0)
		{
			this->add_front(value);
			return;
		}

		else if (index == 1)
		{
			node* new_node = new node;
			new_node->val = value;
			new_node->next = head->next;
			head->next = new_node;
			count++;
			return;
		}

		else {
			assert (index > 1);
			node* next_node = head->next;
			for (int i = 0; i < index-2; i++) {
				next_node = next_node->next;
			}
			node* new_node = new node;
			new_node->val = value;
			new_node->next = next_node->next;
			next_node->next = new_node;
			count++;
			return;
		}
	}

	void change_node(int index, int value)
	{
		if (index == 0)
		{
			node* new_front = new node;
			new_front->val = value;
			new_front->next = head->next;
			head = new_front;
			count++;
			return;
		}

		else if (index == 1)
		{
			node* new_node = new node;
			new_node->val = value;
			new_node->next = head->next->next;
			head->next = new_node;
			count++;
			return;
		}

		else {
			assert(index > 1);
			node* next_node = head->next;
			for (int i = 0; i < index - 2; i++) {
				next_node = next_node->next;
			}
			node* new_node = new node;
			new_node->val = value;
			new_node->next = next_node->next->next;
			next_node->next = new_node;
			count++;
			return;
		}
	}

	void pop_back()
	{
	}

	void pop_front()
	{
	}

	void pop_node(int index)
	{
	}

	void print_info() const
	{
		std::cout << "size of list: " << this->count << std::endl;
		std::cout << "value of head: " << head->val << std::endl;
		std::cout << "value of tail: " << tail->val << std::endl << std::endl;
		
	}

	int get_value(int index) const
	{

		assert(index >= 0 && index < count);

		if (index == 0)
		{
			return head->val;
		}

		else if (index == 1)
		{
			return head->next->val;
		}

		else
		{
			node* next_node = head->next;
			for (int i = 0; i < index - 1; i++) {
				next_node = next_node->next;
			}
			return next_node->val;
		}
	
	}

	void print_list() const
	{
		node* next_node = head->next;
		std::cout << head->val << std::endl;
		for (int i = 0; i < this->count - 1; i++) {
			std::cout << next_node->val << std::endl;
			next_node = next_node->next;
		}

		std::cout << std::endl;
	}

};

int main()
{
	List a;

	a.print_info();
	a.print_list();

	a.add_front(1);
	a.add_back(2);
	
	a.print_info();
	a.print_list();

	a.add_front(3);
	a.add_back(4);

	a.print_info();
	a.print_list();

	a.add_front(7);
	a.add_back(5);

	a.print_info();
	a.print_list();

	//auto a5 = a.get_value(5);
	//std::cout << a5 << std::endl;

	a.add_node(3, 4);
	a.print_list();

	a.add_node(1, 13);
	a.print_list();


	return 0;
}
