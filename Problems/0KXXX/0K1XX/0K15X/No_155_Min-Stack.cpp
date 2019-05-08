// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//    push(x) -- Push element x onto stack.
//    pop() -- Removes the element on top of the stack.
//    top() -- Get the top element.
//    getMin() -- Retrieve the minimum element in the stack.
//
//Example:
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.


//Runtime: 28 ms, faster than 99.38% of C++ online submissions for Min Stack.
//Memory Usage : 17.2 MB, less than 9.14% of C++ online submissions for Min Stack.

class MinStack {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		p = new ListNode(x);
		min = x < min ? x : min;
		p->next = cur;
		cur = p;
	}

	void pop() {
		cur = cur->next;
		if (cur != NULL) {
			min = cur->val;
			p = cur;
			while (p != NULL) {
				min = min < p->val ? min : p->val;
				p = p->next;
			}
		}
		else { min = INT_MAX; }
	}

	int top() { return cur->val; }

	int getMin() { return min; }

private:
	ListNode* cur = NULL;
	ListNode* p = NULL;
	int min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//Runtime: 40 ms, faster than 41.69% of C++ online submissions for Min Stack.
//Memory Usage : 17 MB, less than 43.28% of C++ online submissions for Min Stack.

// Double stack solution
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		s.push(x);
		if (sMin.empty() || x <= sMin.top()) { sMin.push(x); }
	}

	void pop() {
		if (s.top() == sMin.top()) { sMin.pop(); }
		s.pop();
	}

	int top() { return s.top(); }

	int getMin() { return sMin.top(); }

private:
	stack<int> s, sMin;
};


//Runtime: 240 ms, faster than 5.05% of C++ online submissions for Min Stack.
//Memory Usage: 17.2 MB, less than 9.41% of C++ online submissions for Min Stack.

// This one is sloooooow
class MinStack {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		p = new ListNode(x);
		p->next = cur;
		cur = p;
	}

	void pop() { cur = cur->next; }

	int top() { return cur->val; }

	int getMin() {
		p = cur;
		int m = INT_MAX;
		while (p != NULL) {
			m = min(m, p->val);
			p = p->next;
		}
		return m;
	}

private:
	ListNode* cur = NULL;
	ListNode* p = NULL;
};