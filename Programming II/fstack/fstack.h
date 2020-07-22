class fstack
{
private:
	int *parray;
	int size; // size of the array
	int tos;  // index of the top of the stack
public:
	fstack(int);
	~fstack();
	bool empty() const;
	bool full() const;
	void push(int);
	int top() const;
	void pop();
};