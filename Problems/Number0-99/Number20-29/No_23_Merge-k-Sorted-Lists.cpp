//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
//
//Example:
//
//Input:
//[
//	1->4->5,
//	1->3->4,
//	2->6
//]
//Output : 1->1->2->3->4->4->5->6
//
//

// Method 1 and Method 2 have the same performance
// Memory saving, but not runtime fast :)
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<ListNode*>::iterator it_Remove = lists.begin();
		while (it_Remove < lists.end()) {
			if (*it_Remove == NULL) { lists.erase(it_Remove); }
			else { ++it_Remove; }
		}
		if (lists.size() == 0) { return NULL; }
		else if (lists.size() == 1) { return lists[0]; }

		vector<ListNode*> allSorted;
		vector<ListNode*>::iterator it_min = lists.begin();
		while (lists.size() != 0) {
			it_min = lists.begin();
			for (vector<ListNode*>::iterator it = lists.begin();it < lists.end();++it) {
				if ((*it)->val < (*it_min)->val) { it_min = it; }
			}
			allSorted.push_back(*it_min);
			// Method 1 Begin
			//if (allSorted.size() != 1) {
			//	vector<ListNode*>::iterator it_last = allSorted.end() - 1;
			//	(*(it_last - 1))->next = *it_last;
			//}
			// Method 1 End
			if ((*it_min)->next == NULL) { lists.erase(it_min); }
			else { *it_min = (*it_min)->next; }
		}
		// Method 2 Begin
		for (int i = 0;i != allSorted.size();++i) {
			if (i + 1 == allSorted.size()) { allSorted[i]->next = NULL; }
			else { allSorted[i]->next = allSorted[i + 1]; }
		}
		// Method 2 End
		return allSorted[0];
	}
};