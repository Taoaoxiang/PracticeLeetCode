//Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//
//Input: intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
//	Output : [[1, 5], [6, 9]]
//
//	Example 2 :
//
//	Input : intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval = [4, 8]
//	Output : [[1, 2], [3, 10], [12, 16]]
//	Explanation : Because the new interval[4, 8] overlaps with[3, 5], [6, 7], [8, 10].
//
//


//Runtime: 16 ms, faster than 87.25% of C++ online submissions for Insert Interval.
//Memory Usage : 10 MB, less than 100.00% of C++ online submissions for Insert Interval.

// Well, just one more line than the last solution. :P
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		if (intervals.size() <= 1) { return intervals; }
		sort(intervals.begin(), intervals.end(), [](Interval&a, Interval&b) {return a.start < b.start;});
		vector<Interval> rtn;
		int i = 1;
		Interval tmpI(intervals[0].start, intervals[0].end);
		while (i < intervals.size()) {
			if (tmpI.start < intervals[i].start) {
				if (tmpI.end < intervals[i].start) {
					rtn.push_back(tmpI);
					tmpI.start = intervals[i].start;
					tmpI.end = intervals[i].end;
				}
				else { if (tmpI.end < intervals[i].end) { tmpI.end = intervals[i].end; } }
			}
			else {
				if (tmpI.end < intervals[i].end) {
					tmpI.start = intervals[i].start;
					tmpI.end = intervals[i].end;
				}
				else { tmpI.start = intervals[i].start; }
			}
			++i;
		}
		rtn.push_back(tmpI);
		return rtn;
	}
};