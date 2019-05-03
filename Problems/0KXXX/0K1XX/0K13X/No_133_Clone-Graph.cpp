//Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
//
// 
//
//Example:
//
//Input:
//{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
//
//Explanation:
//Node 1's value is 1, and it has two neighbors: Node 2 and 4.
//Node 2's value is 2, and it has two neighbors: Node 1 and 3.
//Node 3's value is 3, and it has two neighbors: Node 2 and 4.
//Node 4's value is 4, and it has two neighbors: Node 1 and 3.
//
// 
//
//Note:
//
//    The number of nodes will be between 1 and 100.
//    The undirected graph is a simple graph, which means no repeated edges and no self-loops in the graph.
//    Since the graph is undirected, if node p has node q as neighbor, then node q must have node p as neighbor too.
//    You must return the copy of the given node as a reference to the cloned graph.
//
//

/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

//Runtime: 40 ms, faster than 24.71% of C++ online submissions for Clone Graph.
//Memory Usage : 16.5 MB, less than 69.20% of C++ online submissions for Clone Graph.

//BFS
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == NULL) { return NULL; }
		unordered_map<Node*, Node*> uAll;
		Node* head = new Node(node->val, {});
		uAll[node] = head;
		queue<Node*> qNodes;
		qNodes.push(node);
		while (!qNodes.empty()) {
			Node* cur = qNodes.front();
			qNodes.pop();
			for (int i = 0; i < cur->neighbors.size(); ++i) {
				Node* nb = cur->neighbors[i];
				if (uAll.find(nb) == uAll.end()) {
					uAll[nb] = new Node(nb->val, {});
					qNodes.push(nb);
				}
				uAll[cur]->neighbors.push_back(uAll[nb]);
			}
		}
		return head;
	}
};


//Runtime: 28 ms, faster than 99.52% of C++ online submissions for Clone Graph.
//Memory Usage : 16.9 MB, less than 61.60% of C++ online submissions for Clone Graph.

class Solution {
public:
	unordered_map<Node*, Node*> uAll;

	Node* reS(Node* node) {
		if (uAll.find(node) == uAll.end()) {
			Node* rtn = new Node(node->val, {});
			uAll[node] = rtn;
			for (int i = 0; i < node->neighbors.size(); ++i) {
				rtn->neighbors.push_back(reS(node->neighbors[i]));
			}
			return rtn;
		}
		else { return uAll[node]; }
	}

	Node* cloneGraph(Node* node) {
		return reS(node);
	}
};

//Runtime: 44 ms, faster than 19.61% of C++ online submissions for Clone Graph.
//Memory Usage : 17 MB, less than 59.20% of C++ online submissions for Clone Graph.

class Solution {
public:
	Node* reS(Node* node, unordered_map<int, Node*>& uAll) {
		if (uAll.find(node->val) == uAll.end()) {
			Node* rtn = new Node(node->val, {});
			uAll[rtn->val] = rtn;
			for (int i = 0; i < node->neighbors.size(); ++i) {
				rtn->neighbors.push_back(reS(node->neighbors[i], uAll));
			}
			return rtn;
		}
		else { return uAll[node->val]; }
	}

	Node* cloneGraph(Node* node) {
		unordered_map<int, Node*> uAll;
		return reS(node, uAll);
	}
};