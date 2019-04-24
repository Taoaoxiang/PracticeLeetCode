//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//
//Input: [[1, 3], [2, 6], [8, 10], [15, 18]]
//	Output : [[1, 6], [8, 10], [15, 18]]
//	Explanation : Since intervals[1, 3] and [2, 6] overlaps, merge them into[1, 6].
//
//	Example 2 :
//
//	Input : [[1, 4], [4, 5]]
//	Output : [[1, 5]]
//	Explanation : Intervals[1, 4] and [4, 5] are considered overlapping.
//


//Runtime: 16 ms, faster than 70.15% of C++ online submissions for Merge Intervals.
//Memory Usage : 9.8 MB, less than 99.81% of C++ online submissions for Merge Intervals.

// Too bad, we have to sort it first.
// And I assume that (.start is not greater than .end), otherwise it won't make sense???
// Anyway, sort it, make the vector legit and do the operation. :)
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
	vector<Interval> merge(vector<Interval>& intervals) {
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