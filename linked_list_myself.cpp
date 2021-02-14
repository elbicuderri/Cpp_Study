#include <iostream>
#include <assert.h>

typedef struct _node
{
	int val; // value of node
	struct _node* next; // pointer of next node

} node;

class List
{
private:
	node* head;
	node* tail;
	int count = 0; // size of List

public:
	List()
		: head{nullptr}
		, tail{nullptr}
	{

	}

	~List()
	{
		int size = this->count;

		for (int i = 0; i < size; i++) {
			this->pop_back();
		}

		this->print_info();
		std::cout << "bye bye~~" << std::endl;
	}

	int size() const { return count; }

	int get_front() const
	{
		if (count == 0)
		{
			std::cout << "List has no element!\n";
			return -999;
		}

		return head->val;
	}

	int get_back() const
	{
		if (count == 0)
		{
			std::cout << "List has no element!\n";
			return -999;
		}

		return tail->val;
	}

	void add_front(int value)
	{
		if (head == nullptr && tail == nullptr)
		{
			node* new_node = new node;
			new_node->val = value;
			new_node->next = nullptr;
			head = new_node;
			tail = new_node;
			count = 1;
			return;
		}

		node* new_node = new node;
		new_node->val = value;
		new_node->next = head;
		head = new_node;
		count++;
	}

	void add_back(int value)
	{
		if (head == nullptr && tail == nullptr)
		{
			node* new_node = new node;
			new_node->val = value;
			new_node->next = nullptr;
			head = new_node;
			tail = new_node;
			count = 1;
			return;
		}

		node* new_node = new node;
		new_node->val = value;
		new_node->next = nullptr;
		tail->next = new_node;
		tail = new_node;
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

		else
		{
			assert(index > 1);
			node* next_node = head->next;
			for (int i = 0; i < index - 2; i++) {
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
			node* new_node = new node;
			new_node->val = value;
			new_node->next = head->next;
			head = new_node;
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
		if (this->count == 0) return;

		else if (this->count == 1)
		{
			//delete tail;
			delete head;
			count--;
			tail = nullptr;
			head = nullptr;
			return;
		}

		else
		{

			int size_of_this = this->count;
			node* before_tail = head;
			for (int i = 0; i < size_of_this - 2; i++)
			{
				before_tail = before_tail->next;
			}
			delete tail;
			tail = before_tail;
			count--;
		}
	}

	void pop_front()
	{
		if (this->count == 0) return;

		else if (this->count == 1)
		{
			//delete tail;
			delete head;
			count--;
			tail = nullptr;
			head = nullptr;
			return;
		}

		else
		{
			node* next_head = head->next;
			delete head;
			head = next_head;
			count--;
		}
	}

	void pop_node(int index)
	{
		if (index == 0)
		{
			this->pop_front();
			return;
		}

		else if (index == 1)
		{
			node* target = head->next;
			node* before_target = head;
			node* next_target = head->next->next;

			before_target->next = next_target;
			delete target;
			target = nullptr;
			count--;
			return;

		}

		else if (index > 1 && index < this->count - 1)
		{
			node* target = head->next;
			node* before_target = head;
			node* next_target = head->next->next;

			for (int i = 0; i < index - 1; i++) {
				target = target->next;
				before_target = before_target->next;
				next_target = next_target->next;
			}
			before_target->next = next_target;
			delete target;
			target = nullptr;
			count--;
			return;
		}

		else
		{
			this->pop_back();
		}

	}

	void print_info() const
	{
		std::cout << "size of list: " << this->count << std::endl;
		if (head == nullptr || tail == nullptr)
		{
			std::cout << std::endl;
			return;
		}
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
		if (head == nullptr || tail == nullptr)
		{
			return;
		}
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

	a.print_info();
	a.print_list();

	a.add_node(1, 13);

	a.print_info();
	a.print_list();

	a.pop_back();

	a.print_info();
	a.print_list();

	a.pop_front();

	a.print_info();
	a.print_list();

	a.pop_node(4);

	a.print_info();
	a.print_list();

	a.pop_node(4); 

	a.print_info();
	a.print_list();

	return 0;
}
