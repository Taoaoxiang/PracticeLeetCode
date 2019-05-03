//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.
//
// 
//
//Example 1:
//
//Input:
//{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
//
//Explanation:
//Node 1's value is 1, both of its next and random pointer points to Node 2.
//Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
//
// 
//
//Note:
//
//    You must return the copy of the given head as a reference to the cloned list.
//
//

//Runtime: 36 ms, faster than 99.88% of C++ online submissions for Copy List with Random Pointer.
//Memory Usage : 22.4 MB, less than 5.21% of C++ online submissions for Copy List with Random Pointer.

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) { return NULL; }
		Node* p = head;
		unordered_map<Node*, Node*> uAll;
		uAll[head] = new Node(head->val, NULL, NULL);
		while (p != NULL) {
			if (p->next != NULL) {
				if (uAll.find(p->next) == uAll.end()) {
					uAll[p->next] = new Node(p->next->val, NULL, NULL);
				}
				uAll[p]->next = uAll[p->next];
			}
			if (p->random != NULL) {
				if (uAll.find(p->random) == uAll.end()) {
					uAll[p->random] = new Node(p->random->val, NULL, NULL);
				}
				uAll[p]->random = uAll[p->random];
			}
			p = p->next;
		}
		return uAll[head];
	}
};