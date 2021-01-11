// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int numDecodings(string s);
int finds(string s);


int main()
{	
	string s = "111111111111111111111111111111111111111111111";
	string a = "201234";
	cout << a.substr(0,2) + "\n";
	cout << numDecodings(s);
	
}




//class Solution {
//public:
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		vector<ListNode*> LN;
//		ListNode* head1 = head;
//		LN.insert(end(LN), head1);
//		while (head1->next != NULL) {
//			head1 = head1->next;
//			LN.insert(end(LN), head1);
//		}
//
//		if (n == 1) {
//			head = LN[n];
//		}
//		else {
//			ListNode* before = LN[n - 2];
//			before->next = LN[n];
//		}
//
//		return head;
//	}
//};
//
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//
//};
//
////Merge k sorted lists
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.size() == 0) {
//			return NULL;
//		}
//		ListNode* result = new ListNode();
//		bool flag = true;
//
//		
//
//		while (flag) {
//			flag = false;
//			int min = 10000;
//			int temp = 0;
//			for (int i = 0; i < lists.size(); i++) {
//				if (lists[i] != nullptr && lists[i]->val < min) {
//					min = lists[i]->val;
//					temp = i;
//				}
//			}
//			result->next = lists[temp];
//			lists[temp] = lists[temp]->next;
//
//			for (int i = 0; i < lists.size(); i++) {
//				if (lists[i] != nullptr) {
//					flag = true;
//				}
//			}
//		}
//
//		return result->next;
//	}
//};
//
//
//
////Reverse Nodes in k-Group
//class Solution {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode *s, *p = (ListNode*)malloc(sizeof(ListNode));
//		int len = k;
//		p->next = head;
//		head = p;
//		s = p;
//
//		while (k-- && s != NULL)
//			s = s->next;
//
//		while (s != NULL) {
//			reverse(p, s);
//			k = len;
//			while (k-- && s != NULL)s = s->next;
//		}
//		return head->next;
//	}
//
//	private:
//		void reverse(ListNode * &p, ListNode* &s) {
//			ListNode* tmp, *tail = p->next; 
//			ListNode* flag = s->next;
//			ListNode* l = p->next;
//			p->next = NULL;
//			while (l != flag) {
//				tmp = p->next;
//				p->next = l;
//				l = l->next;
//				p->next->next = tmp;
//			}
//			tail->next = l;
//			p = tail;
//			s = tail;
//		}
//};
//
//
////Substring with Concatenation of All Words
////注意这里一定要将 s.size() 先转为整型数，再进行解法。
////一定要形成这样的习惯，一旦 size() 后面要减去数字时，
////先转为 int 型，因为 size() 的返回值是无符号型，一旦
////减去一个比自己大的数字，则会出错。
//class Solution {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		if (s.empty() || words.empty()) return {};
//
//		vector<int> res;
//		int n = words.size(), len = words[0].size();
//		unordered_map<string, int> wordCnt;
//		for (auto &word : words) ++wordCnt[word];
//		for (int i = 0; i <= (int)s.size() - n * len; ++i) {
//			unordered_map<string, int> strCnt;
//			int j = 0;
//			for (j = 0; j < n; j++) {
//				string t = s.substr(i + j * len, len);
//				if (!wordCnt.count(t)) break;
//				++strCnt[t];
//				if (strCnt[t] > wordCnt[t]) break;
//			}
//
//			if(j == n) res.push_back(i);
//		}
//		return res;
//	}
//};
//
//
////32. Longest Valid Parentheses
//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		int len = s.length();
//		int *dp = new int[len];
//
//		int a[len];
//
//		for (int i = 0; i < len; i++) {
//			if (s.at[i] == ')') {
//				if (s.at(i - 1) == '(') {
//					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//				}
//				else if (i - dp[i-1] > 0 && s.at(i-dp[i-1]) == '(') {
//					dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
//
//				}
//			}
//		}
//
//		return *(max_element(dp, dp + len));
//	}
//};
//
////34. Find First and Last Position of Element in Sorted Array
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		vector<int> targetRange = { -1,-1 };
//
//		int leftIndex = find(nums, target, true);
//
//		if (leftIndex == size(nums) || nums[leftIndex] != target) {
//			return targetRange;
//		}
//		targetRange[0] = leftIndex;
//		targetRange[1] = find(nums, target, false) - 1;
//
//		return targetRange;
//	}
//
//    int find(vector<int>& nums, int target, bool left) {
//		int lo = 0;
//		int hi = size(nums);
//
//		while (lo < hi) {
//			int mid = (lo + hi) / 2;
//			if (nums[mid] > target || left && target == nums[mid]) 
//				hi = mid;
//			else 
//				lo = mid + 1;
//		}
//
//		return lo;
//		
//	}
//};
//
//
////37. Sudoku Solver
//class Solution {
//public:
//	void solveSudoku(vector<vector<char>>& board) {
//		helper(board, 0, 0);
//	}
//
//	bool helper(vector<vector<char>>& board, int i, int j) {
//		if (i == 9) return true;
//		if (j >= 9) return helper(board, i + 1, 0);
//		if (board[i][j] != '.') return helper(board, i, j + 1);
//
//		for (char c = '1'; c < '9'; c++) {
//			if (!isValid(board, i, j, c)) continue;
//			board[i][j] = c;
//			if (helper(board, i, j + 1)) return true;
//			board[i][j] = '.';
//		}
//		return false;
//	}
//
//	bool isValid(vector<vector<char>> & board, int i, int j, char val) {
//		for (int x = 0;x < 9; ++x) {
//			if (board[x][j] == val) return false;
//		}
//		for (int y = 0; y < 9; y++) {
//			if (board[i][y] == val) return false;
//		}
//
//		int row = i - i % 3, col = j - j % 3;
//		for (int x = 0; x < 3; ++x) {
//			for (int y = 0; y < 3; y++) {
//				if (board[x + row][y + col] == val) return false;
//			}
//		}
//		return true;
//	}
//};
//
////38. Count and Say
//class Solution {
//public:
//	string countAndSay(int n) {
//		if (n == 1) return "1";
//		if (n == 2) return "11";
//		string res = "";
//		string str = countAndSay(n - 1);
//
//		for (int i = 0; i < str.length(); i++) {
//			char ch = str.at(i);
//			int j = i + 1;
//			int count = 1;
//			while (j < str.length() && str.at(j) == ch) {
//				count++;
//				j++;
//			}
//
//			res += to_string(count) + ch;
//			i += count - 1;
//
//		}
//		return res;
//	}
//
//};
//
////39. Combination Sum
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		sort(candidates.begin(), candidates.end());
//		vector<vector<int>> res;
//		vector<int> path;
//		_combinationSum(candidates, target, 0, path, res);
//		return res;
//	}
//
//private:
//	void _combinationSum(vector<int> & candidates, int target, int index, vector<int> & path, vector<vector<int>> & res) {
//		if (target == 0) {
//			res.push_back(path);
//			return;
//		}
//		if (!path.empty() and target < *(path.rbegin())) return;
//		for (unsigned int i = index; i < candidates.size(); i++) {
//			path.push_back(candidates[i]);
//			_combinationSum(candidates, target - candidates[i], i, path, res);
//			path.pop_back();
//		}
//	}
//};
//
//
////#######10.29###########
////40 Combination Sum II
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		sort(candidates.begin(), candidates.end());
//		vector<vector<int>> res;
//		vector<int> path;
//		_combinationSum(candidates, target, 0, path, res);
//		return res;
//	}
//
//private:
//	void _combinationSum(vector<int> & candidates, int target, int index, vector<int> & path, vector<vector<int>> & res) {
//		if (target == 0) {
//			res.push_back(path);
//			return;
//		}
//		if (!path.empty() and target < *(path.rbegin())) return;
//		for (unsigned int i = index; i < candidates.size(); i++) {
//			if (i > index && candidates[i] == candidates[i - 1])  continue;
//			path.push_back(candidates[i]);
//			_combinationSum(candidates, target - candidates[i], i+1, path, res);
//			path.pop_back();
//		}
//	}
//};
//
//// 41 First Missing Positive
//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//		int n = nums.size();
//		for (int i = 0; i < nums.size(); i++) {
//			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
//				swap(nums[i], nums[nums[i] - 1]);
//			}
//		}
//
//		for (int i = 0; i < n; i++) {
//			if (nums[i] != i + 1) return i + 1;
//		}
//		return n + 1;
//	}
//};
//
//
////42 Trapping Rain Water
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int res = 0, mx = 0, n = height.size();
//		vector<int> dp(n, 0);
//		for (int i = 0; i < n; i++) {
//			dp[i] = mx;
//			mx = max(mx, height[i]);
//		}
//		mx = 0;
//		for (int i = n - 1; i >= 0; i--) {
//			dp[i] = min(dp[i], mx);
//			mx = max(mx, height[i]);
//			if (dp[i] > height[i]) res += dp[i] - height[i];
//		}
//		return res;
//	}
//};
//
//
////[LeetCode] 43. Multiply Strings
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		string res = "";
//		int m = num1.size(), n = num2.size();
//		vector<int> vals(m + n);
//		for (int i = m - 1; i >= 0; i--) {
//			for (int j = n - 1; j >= 0; j--) {
//				int mul = (num1[i] - '0') *(num2[j] - '0');
//				int p1 = i + j, p2 = i + j + 1, sum = mul + vals[p2];
//				vals[p1] += sum / 10;
//				vals[p2] = sum % 10;
//			}
//		}
//
//		for (int val : vals) {
//			if (!res.empty() || val != 0) res.push_back(val + '0');
//		}
//		return res.empty() ? "0" : res;
//	}
//};
//
////44. Wildcard Matching
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
//		while (i < m) {
//			if (j < n && (s[i] == p[j] || p[j] == '?')) {
//				i++;
//				j++;
//			}
//			else if (j < n && p[j] == '*') {
//				iStar = i;
//				jStar = j++;
//			}
//			else if (iStar >= 0) {
//				i = iStar++;
//				j = jStar + 1;
//			}
//			else return false;
//		}
//
//		while (j < n && p[j] == '*') ++j;
//		return j == n;
//	}
//};
//
////46.Permutations
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int>& num) {
//		vector<vector<int>> res;
//		vector<int> out;
//		vector<int> visited(num.size(), 0);
//		permutationsDFS(num, 0. visited, out, res);
//		return res;
//	}
//
//	void permutationsDFS(vector<int> & num, int level, vector<int> & visited, vector<int> & out, vector<vector<int>>
// res) {
//		if (level == num.size()) {
//			res.push_back(out);
//			return;
//		}
//
//		for (int i = 0; i < num.size(); i++) {
//			if (visited[i] == 1) continue;
//			visited[i] = 1;
//			out.push_back(num[i]);
//			permutationsDFS(num, level + 1, visited, out, res);
//			out.pop_back();
//			visited[i] = 0;
//		}
//	}
//};
//
////47.Permutations II
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int>& num) {
//		vector<vector<int>> res;
//		vector<int> out;
//		vector<int> visited(num.size(), 0);
//		sort(num.begin(), num.end());
//		permutationsDFS(num, 0, visited, out, res);
//		return res;
//	}
//
//	void permutationsDFS(vector<int> & num, int level, vector<int> & visited, vector<int> & out, vector<vector<int>> &
//		res) {
//		if (level == num.size()) {
//			res.push_back(out);
//			return;
//		}
//
//		for (int i = 0; i < num.size(); i++) {
//			if (visited[i] == 1) continue;
//			if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0) continue;
//			visited[i] = 1;
//			out.push_back(num[i]);
//			permutationsDFS(num, level + 1, visited, out, res);
//			out.pop_back();
//			visited[i] = 0;
//		}
//	}
//};
//
////48.Rotaet Image
//class Solution {
//public:
//	void rotate(vector<vector<int>>& matrix) {
//		int n = matrix.size();
//		for (int i = 0; i < n / 2; i++) {
//			for (int j = i; j < n - 1 - i; j++) {
//				int tmp = matrix[i][j];
//				matrix[i][j] = matrix[n - 1 - j][i];
//				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
//				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
//				matrix[j][n - 1 - i] = tmp;
//			}
//		}
//	}
//};
//
////49.Anagram
//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		vector<vector<string>> res;
//		unordered_map<string, int> m;
//		for (string str : strs) {
//			string t = str;
//			sort(t.begin(), t.end());
//			if (!m.count(t)) {
//				m[t] = res.size();
//				res.push_back({});
//			}
//			res[m[t]].push_back(str);
//		}
//		return res;
//	}
//};
//
////50.myPow
//class Solution {
//public:
//	double myPow(double x, int n) {
//		if (n == 0) return 1;
//		double half = myPow(x, n / 2);
//		if (n % 2 == 0) return half * half;
//		if (n > 0) return half * half*x;
//		return half * half / x;
//	}
//};
//
////51.N-Queen
//class Solution {
//public:
//	vector<vector<string>> solveNQueens(int n) {
//		vector<vector<string>> res;
//		vector<string> queens(n, string(n, '.'));
//		helper(0, queens, res);
//		return res;
//	}
//
//	void helper(int curRow, vector<string>& queens, vector<vector<string>> &res) {
//		int n = queens.size();
//		if (curRow == n) {
//			res.push_back(queens);
//			return;
//		}
//		for (int i = 0; i < n; i++) {
//			if (isValid(queens, curRow, i)) {
//				queens[curRow][i] = 'Q';
//				helper(curRow + 1, queens, res);
//				queens[curRow][i] = '.';
//			}
//		}
//	}
//
//	bool isValid(vector<string> & queens, int row, int col) {
//		for (int i = 0; i < row; i++) {
//			if (queens[i][col] == 'Q') return false;
//		}
//		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0;i--, j--) {
//			if (queens[i][j] == 'Q') return false;
//		}
//
//		for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); i--, j++) {
//			if (queens[i][j] == 'Q') return false;
//		}
//
//		return true;
//	}
//};
//
////52.N-Queen II
//class Solution {
//public:
//	int totalNQueens(int n) {
//		int res = 0; 
//		vector<int> pos(n, -1);
//		helper(pos, 0, res);
//		return res;
//	}
//
//	void helper(vector<int> & pos, int row, int & res) {
//		int n = pos.size();
//		if (row == n) { res++; return; }
//		for (int col = 0; col < n; col++) {
//			if (isValid(pos, row, col)) {
//				pos[row] = col;
//				helper(pos, row + 1, res);
//				pos[row] = -1;
//			}
//		}
//	}
//
//	bool isValid(vector<int> & pos, int row, int col) {
//		for (int i = 0; i < row; i++) {
//			if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
//				return false;
//			}
//		}
//		return true;
//	}
//};
//
////################  11.3
////53. Maximum Subarray
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		if (nums.empty()) return 0;
//		return helper(nums,0, (int)nums.size() - 1);
//	}
//
//	int helper(vector<int> & nums, int left, int right) {
//		if (left >= right) return nums[left];
//		int mid = left + (right - left) / 2;
//		int lmax = helper(nums, left, mid - 1);
//		int rmax = helper(nums, mid + 1, right);
//		int mmax = nums[mid], t = mmax;
//		for (int i = mid - 1; i >= left; --i) {
//			t += nums[i];
//			mmax = max(mmax, t);
//		}
//		t = mmax;
//		for (int i = mid + 1; i <= right; ++i) {
//			t += nums[i];
//			mmax = max(mmax, t);
//		}
//		return max(mmax, max(lmax, rmax));
//	}
//};
//
//// 54. Spiral Matrix
//class Solution {
//public:
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		if (matrix.empty() || matrix[0].empty()) return {};
//		int m = matrix.size(), n = matrix[0].size();
//		vector<int> res;
//		int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
//		int p = m, q = n;
//		for (int i = 0; i < c; i++, p -= 2, q -= 2) {
//			for(int col = i; col < i + q; ++col)
//				res.push_back(matrix[i][col]);
//			for (int row = i + 1; row < i + p; row++) {
//				res.push_back(matrix[row][i + q - 1]);
//			}
//			if (p == 1 || q == 1) break;
//			for (int col = i + q - 2; col >= i; col--) {
//				res.push_back(matrix[i + p - 1][col]);
//			}
//			for (int row = i + p - 2; row > i; row--) {
//				res.push_back(matrix[row][i]);
//			}
//		}
//		return res;
//	}
//
//};
//
////55.Jump Game
//class Solution {
//public:
//	bool canJump(vector<int>& nums) {
//		vector<int> dp(nums.size(), 0);
//		for (int i = 1; i < nums.size(); i++) {
//			dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
//			if (dp[i] < 0) return false;
//		}
//		return true;
//	}
//	
//};
//
////56.Merge Intervals
//class Solution {
//public:
//	vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		if (intervals.empty()) return{};
//		sort(intervals.begin(), intervals.end(), compare);
//		vector<vector<int>> res{ intervals[0] };
//		for (int i = 1; i < intervals.size(); i++) {
//			if (res.back()[1] < intervals[i][0]) {
//				res.push_back(intervals[i]);
//			}
//			else {
//				res.back()[1] = max(res.back()[1], intervals[i][1]);
//			}
//		}
//		return res;
//	}
//
//	bool compare(vector<int> a, vector<int> b) {
//		return a[0] < b[0];
//	}
//};
//
////57.Insert Interval
//class Solution {
//public:
//	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//		vector<vector<int>> res;
//		int n = intervals.size(), cur = 0;
//		while (cur < n && intervals[cur][1] < newInterval[0]) {
//			res.push_back(intervals[cur++]);
//		}
//		while (cur < n && intervals[cur][0] <= newInterval[1]) {
//			newInterval[0] = min(newInterval[0], intervals[cur][0]);
//			newInterval[1] = max(newInterval[1], intervals[cur][1]);
//			cur++;
//		}
//		res.push_back(newInterval);
//		while (cur < n) {
//			res.push_back(intervals[cur++]);
//		}
//		return res;
//	}
//};
//
////58.Length of Last Word
//class Solution {
//public:
//	int lengthOfLastWord(string s) {
//		int left = 0, right = (int)s.size() - 1, res = 0;
//		while(s[left] == ' ') ++left;
//		while (s[right] == ' ') --right;
//		for (int i = left; i <= right; i++) {
//			if (s[i] == ' ') res = 0;
//			else ++res;
//		}
//		return res;
//	}
//};
//
////59.Spiral Matrix II
//class Solution {
//public:
//	vector<vector<int>> generateMatrix(int n) {
//		vector<vector<int>> res(n, vector<int>(n));
//		int val = 1, p = n;
//		for (int i = 0; i < n / 2; i++, p -= 2) {
//			for (int col = i; col < i + p; col++) {
//				res[i][col] = val++;
//			}
//			for (int row = i + 1; row < i + p; ++row) {
//				res[row][i + p - 1] = val++;
//			}
//			for (int col = i + p - 2; col >= i; col--) {
//				res[i + p - 1][col] = val++;
//			}
//			for (int row = i + p - 2; row > i; row--) {
//				res[row][i] = val++;
//			}
//			
//			
//		}
//
//		return res;
//	}
//};
//
////60 Permutation Sequence
//class Solution {
//public:
//	string getPermutation(int n, int k) {
//		string res;
//		string num = "123456789";
//		vector<int> f(n, 1);
//		for (int i = 1; i < n; i++) f[i] = f[i - 1] * i;
//		--k;
//		for (int i = n; i >= 1; --i) {
//			int j = k / f[i - 1];
//			k %= f[i - 1];
//			res.push_back(num[j]);
//			num.erase(j, 1);
//		}
//		return res;
//	}
//};
//
////61.Rotate List
//class Solution {
//public:
//	ListNode* rotateRight(ListNode* head, int k) {
//		if (!head) return NULL;
//		int n = 0;
//		ListNode * cur = head;
//		while (cur) {
//			n++;
//			cur = cur->next;
//		}
//		k %= n;
//		ListNode *fast = head, *slow = head;
//		for (int i = 0; i < k; i++) {
//			if (fast) fast = fast->next;
//		}
//		if (!fast) return head;
//		while (fast->next) {
//			fast = fast->next;
//			slow = slow->next;
//		}
//		fast->next = head;
//		fast = slow->next;
//		slow->next = NULL;
//		return fast;
//	}
//};
//
////62.Unique paths
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		vector<int> dp(n, 1);
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				dp[j] += dp[j - 1];
//			}
//		}
//		return dp[n - 1];
//	}
//};
//
////62.Unique paths II
//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return;
//		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//		vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
//		dp[0][1] = 1;
//		for (int i = 0; i <= m; i++) {
//			for (int j = 0; j <= n; j++) {
//				if (obstacleGrid[i - 1][j - 1]) { continue; }
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//			}
//		}
//		return dp[m][n];
// 	}
//};
//
////63.Minimun path sum
//class Solution {
//public:
//	int minPathSum(vector<vector<int>>& grid) {
//		if (grid.empty() || grid[0].empty()) {
//			return 0;
//		}
//		int m = grid.size(), n = grid[0].size();
//		vector<vector<int>> dp(m, vector<int>(n, 0));
//		dp[0][0] = grid[0][0];
//		for (int i = 1; i < m; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
//		for (int j = 1; j < n; j++) dp[0][j] = grid[0][j] + dp[0][j - 1];
//		for (int i = 1; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
//			}
//		}
//		return dp[m - 1][n - 1];
//	}
//};
//
////[LeetCode] Valid Number 验证数字
//class Solution {
//public:
//	bool isNumber(string s) {
//		int len = s.size();
//		int left = 0, right = len - 1;
//		bool eExisted = false;
//		bool dotExisted = false;
//		bool digitExisted = false;
//		while (s[left] == ' ') left++;
//		while (s[right] == ' ') right--;
//		if (left >= right && (s[left] < '0' || s[left] > '9')) {
//			return false;
//		}
//		if (s[left] == '.') dotExisted = true;
//		else if (s[left] >= '0' && s[left] <= '9') digitExisted = true;
//		else if (s[left] != '+' && s[left] != '-') return false;
//
//		for (int i = left + 1; i <= right - 1; i++) {
//			if (s[i] >= '0' && s[i] <= '9') digitExisted = true;
//			else if (s[i] == 'e' || s[i] == 'E') {
//				if (!eExisted && s[i - 1] != 'e' && s[i - 1] != 'E' && digitExisted) eExisted = true;
//				else return false;
//			}
//			else if (s[i] == '+' || s[i] == '-') {
//				if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;
//			}
//			else if (s[i] == '.'){
//				if (!dotExisted && !eExisted) dotExisted = true;
//				else return false;
//			}
//			else return false;
//		}
//
//		if (s[right] >= '0' && s[right] <= '9') return true;
//		else if (s[right] == '.' && !dotExisted && !eExisted && digitExisted) return true;
//		else return false;
//	}
//};
//
////66. Plus One
//class Solution {
//public:
//	vector<int> plusOne(vector<int>& digits) {
//		int len = digits.size();
//		int sum = digits[len - 1] + 1;
//		if (sum < 10)
//			digits[len - 1] = sum;
//		else {
//			digits[len - 1] = 0;
//			for (int i = len - 2; i >= 0; i--) {
//				if (digits[i] == 9)
//					digits[i] = 0;
//				else {
//					digits[i] += 1;
//					break;
//				}
//			}
//			if (digits[0] == 0)
//				digits.insert(digits.begin(), 1);
//		}
//
//		return digits;
//	}
//};
//
////67. Add binary
//class Solution {
//public:
//	string addBinary(string a, string b) {
//		string s = "";
//		reverse(a.begin(), a.end());
//		reverse(b.begin(), b.end());
//		int len = a.length() < b.length() ? a.length() : b.length();
//		string long_s = a.length() > b.length() ? a : b;
//		int flag = 0;
//		for (int i = 0; i < len; i++) {
//			if (a[i] ^ b[i] == 1) {
//				if (flag == 1) s += '0';
//				else {s += '1'; flag = '0';}
//			}
//			else {
//				if (a[i] == '0') {
//					if (flag == 1) { s += '1'; flag = 0; }
//					else s += '0';
//				}
//				else {
//					flag = 1;
//					if (flag == 1) s += '1';
//					else s += '0';
//				}
//			}
//		}
//		int j = len;
//		for (; j < long_s.length(); j++) {
//			if (flag == 1) {
//				if (long_s[j] == '0') { s += '1'; flag = 0; }
//				else s += '0';
//			}
//			else break;
//		}
//		if (j < long_s.length()) s += long_s.substr(j, long_s.length);
//		if (flag == 1) s += '1';
//		reverse(s.begin(), s.end());
//		return s;
//	}
//};
//
////70, Climbing stairs
//class Solution {
//public:
//	int climbStairs(int n) {
//		if (n == 1) return 1;
//		int nums_ALL_2 = n / 2;
//		int res = 0;
//		for (int i = 0; i <= nums_ALL_2; i++) {
//			int nums_1 = n - 2 * i;
//			res += combination(nums_1+i, i);
//		}
//		return res;
//	}
//
//	long long  combination(int n, int m) {
//		if (m > n / 2) m = n - m;
//		long long res = 1;
//		for (int i = 0; i < m; i++) {
//			res = res * (n - i) / (i + 1);
//		}
//		return res;
//	}
//};
//
////71 Simplify Path
//class Solution {
//public:
//	string simplifyPath(string path) {
//		vector<string> v;
//		int i = 0;
//		while (i < path.size()) {
//			while (i < path.size() && path[i] == '/') i++;
//			if (i == path.size()) break;
//			int start = i;
//			while (path[i] != '/' && i < path.size()) i++;
//			int end = i - 1;
//			string s = path.substr(start, end - start + 1);
//			if (s == "..") {
//				if (!v.empty()) v.pop_back;
//			}
//			else if (s != ".") {
//				v.push_back(s);
//			}
//		}
//
//		if (v.empty()) return "/";
//		string res;
//		for (int i = 0; i < v.size(); i++) {
//			res += '/' + v[i];
//		}
//		return res;
//	}
//};
//
////73 Set Matrix Zeros
//class Solution {
//public:
//	void setZeroes(vector<vector<int>>& matrix) {
//		vector<int> row_0;
//		vector<int> col_0;
//		int row_num = matrix.size();
//		int col_num = matrix[0].size();
//		for (int i = 0; i < row_num; i++) {
//			for (int j = 0; j < col_num; j++) {
//				if (matrix[i][j] == 0) { row_0.push_back(i); col_0.push_back(j); }
//			}
//		}
//		for (int i = 0; i < row_0.size(); i++) {
//			for (int j = 0; j < col_num; j++) matrix[row_0[i]][j] = 0;
//		}
//		for (int i = 0; i < col_0.size(); i++) {
//			for (int j = 0; j < row_num; j++) matrix[j][col_0[i]] = 0;
//		}
//	}
//};
//
////74 Search a 2D Matrix
//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		if (matrix.empty() || matrix[0].empty()) return false;
//		int left = 0, right = matrix.size();
//		while (left < right) {
//			int mid = (left + right) / 2;
//			if (matrix[mid][0] == target) return true;
//			if (matrix[mid][0] < target) left = mid + 1;
//			else right = mid;
//		}
//		int tmp = (right > 0) ? (right - 1) : right;
//		left = 0;
//		right = matrix[tmp].size();
//		while (left < right) {
//			int mid = (left + right) / 2;
//			if (matrix[tmp][mid] == target) return true;
//			if (matrix[tmp][mid] < target) left = mid + 1;
//			else right = mid;
//		}
//		return false;
//	}
//};
//
////75 set colors
//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int red = 0, blue = nums.size() - 1;
//		for (int i = 0; i < blue; i++) {
//			if (nums[i] == 0) {
//				swap(nums[i], nums[red++]);
//			}
//			else if (nums[i] == 2) {
//				swap(nums[i], nums[blue--]);
//			}
//		}
//
//
//	}
//};
//
////77 Combinations
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		vector<vector<int>> res;
//		vector<int> out;
//		helper(n, k, 1, out, res);
//		return res;
//	}
//
//	void helper(int n, int k, int level, vector<int> & out, vector<vector<int>>& res) {
//		if (out.size() == k) { res.push_back(out); return; }
//		for (int i = level; i <= n; i++) {
//			out.push_back(i);
//			helper(n, k, i + 1, out, res);
//			out.pop_back();
//		}
//	}
//};
////78 subsets
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> res;
//		vector<int> empty;
//		res.push_back(empty);
//		int size = nums.size();
//		for (int i = 1; i <= size; i++) {
//			vector<int> out;
//			helper(size, i, 1, out, res, nums);
//		}
// 
//		return res;
//	}
//
//	void helper(int n, int k, int level, vector<int> & out, vector<vector<int>>& res, vector<int>& nums) {
//		if (out.size() == k) { res.push_back(out); return; }
//		for (int i = level; i <= n; i++) {
//			out.push_back(nums[i]);
//			helper(n, k, i + 1, out, res, nums);
//			out.pop_back();
//		}
//	}
//};
//
////79 word search
//class Solution {
//public:
//	bool exist(vector<vector<char>>& board, string word) {
//		if (board.empty() || board[0].empty()) return false;
//		int m = board.size(), n = board[0].size();
//		vector<vector<bool>> visited(m, vector<bool>(n));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (search(board, word, 0, i, j, visited)) return true;
//			}
//		}
//		return false;
//	}
//
//	bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
//		if (idx == word.size()) return true;
//		int m = board.size(), n = board[0].size();
//		if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
//		visited[i][j] = true;
//		bool res = search(board, word, idx + 1, i + 1, j, visited)
//			|| search(board, word, idx + 1, i - 1, j, visited)
//			|| search(board, word, idx + 1, i, j + 1, visited)
//			|| search(board, word, idx + 1, i, j - 1, visited);
//		visited[i][j] = false;
//		return res;
//	}
//};
//
//// 80 Remove Duplicates from Sorted array II
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		int i = 0, size = nums.size();
//		int count = 1;
//		int num = nums[0];
//		vector<int>::iterator it = nums.begin();
//		it++;
//		for (; it != nums.end();) {
//			if (count < 2) {
//				if (*it == num) count++;
//				else { num = *it; count = 1; }	
//				it++;
//			}
//			else {
//				if (*it == num) it = nums.erase(it);
//				else { 
//					num = *it;
//					count = 1; 
//					it++;
//				}
//				
//			}
//		}
//		return nums.size();
//	}
//};
//
////82. Remove Duplicates from Sorted List II
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		if (head == NULL || head->next == NULL || head ->next ->next == NULL) return head;
//		ListNode *slow, *fast;
//		slow = head;
//		fast = head->next->next;
//		bool flag = false;
//		bool flag1 = false;
//		while (fast != NULL) {
//			if (slow->next->val == fast->val) flag = flag1 = true; 
//			else {
//				slow = slow->next;
//				fast = fast->next;
//			}
//			while (flag && fast ->next != NULL) {
//				if (slow->next->val == fast->next->val) fast = fast->next;
//				else {
//					flag = false;
//				}
//			}
//			if (flag1) {
//				slow->next = fast->next;
//				if (fast->next == NULL) fast = fast->next;
//				else fast = fast->next->next;
//			}
//		}
//		return head;
//	}
//};
//
////83. Remove Duplicates from Sorted List 
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
//		ListNode *slow, *fast;
//		slow = head;
//		fast = head->next;
//		bool flag = false;
//		bool flag1 = false;
//		while (fast != NULL) {
//			if (slow->val == fast->val) flag = flag1 = true;
//			else {
//				slow = slow->next;
//				fast = fast->next;
//			}
//			while (flag && fast != NULL) {
//				if (slow->val == fast->val) fast = fast->next;
//				else {
//					flag = false;
//				}
//			}
//			if (flag1) {
//				slow->next = fast;
//			}
//		}
//		return head;
//	}
//};
//
////86. Partition List
//class Solution {
//public:
//	ListNode* partition(ListNode* head, int x) {
//		ListNode * dummy = new ListNode(-1);
//		dummy->next = head;
//		ListNode *pre = dummy, *cur = head;
//		while (pre->next &&  pre -> next -> val < x) pre = pre->next;
//		cur = pre;
//		while (cur->next) {
//			if (cur->next->val < x) {
//				ListNode *tmp = cur->next;
//				cur->next = tmp->next;
//				tmp->next = pre->next;
//				pre->next = tmp;
//				pre = pre->next;
//			}
//			else {
//				cur = cur->next;
//			}
//		}
//		return dummy->next;
//	}
//};
//
////88. Merge Sorted Array
//class Solution {
//public:
//	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//		vector<int> res;
//		int i = 0, j = 0;
//		while (i < m && j < n) {
//			if (nums1[i] < nums2[j]) {
//				res.push_back(nums1[i]);
//				i++;
//			}
//			else{
//				res.push_back(nums2[j]);
//				j++;
//			}
//		}
//		vector<int> nums = i == m - 1 ? nums2 : nums1;
//		int pos = i == m - 1 ? j : i;
//		int limits = i == m - 1 ? n : m;
//		pos++;
//		while (pos < limits) {
//			res.push_back(nums[pos]);
//			pos++;
//		}
//		nums1 = res;
//	}
//};
//
////89. Gray Code：
//class Solution {
//public:
//	vector<int> grayCode(int n) {
//		vector<int> res;
//		for (int i = 0; i < pow(2, n); i++) {
//			res.push_back((i >> 1) ^ i);
//		}
//		return res;
//	}
//};
//
////90. Subsets II
////solution 1
//class Solution {
//public:
//	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//		if (nums.empty()) return {};
//		vector<vector<int>> res;
//		int size = nums.size();
//		sort(nums.begin(), nums.end);
//		for (int i = 0; i <= size; i++) {
//			vector<int> out;
//			combination(res, out, nums, i, 0);
//		}
//	}
//
//	void combination(vector<vector<int>> &res, vector<int> &out, vector<int> nums, int k, int j) {
//		if (out.size() == k && !is_in_Vector(res, out)) { res.push_back(out); return; }
//
//		for (int i = j; i < nums.size(); i++) {
//			out.push_back(nums[i]);
//			combination(res, out, nums, k, j + 1);
//			out.pop_back();
//		}
//	}
//
//	bool is_in_Vector(vector<vector<int>> a, vector<int> element) {
//		vector<vector<int>> ::iterator it = find(a.begin(), a.end(), element);
//		return it != a.end();
//	}
//};
////solution 2:
//class Solution {
//public:
//	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//		if (nums.empty()) return {};
//		vector<vector<int>> res(1);
//		sort(nums.begin(), nums.end());
//		int size = 1, last = nums[0];
//		for (int i = 0; i < nums.size(); i++) {
//			if (last != nums[i]) {
//				last = nums[i];
//				size = res.size();
//			}
//			int newSize = res.size();
//			for (int j = newSize - size; j < newSize; j++) {
//				res.push_back(res[j]);
//				res.back().push_back(nums[i]);
//			}
//		}
//		return res;
//	}
//};
//
//

//91. Decode Ways
class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0' || s.empty()) return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < s.size(); i++) {
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
			if (i > 1 && s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6') {
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
	}
};


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//92. Reverse Linked List II
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		for (int i = 0; i < m - 1; i++) pre = pre->next;
		ListNode * cur = pre->next;
		for (int i = m; i < n;i++) {
			ListNode *t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};

//93.Restore IP Addresses 复原IP地址
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		restore(s, "", 4, res);
		return res;
	}

	void restore(string s, string out, int k, vector<string>& res) {
		if (k == 0) {
			if (s.empty()) res.push_back(out);
		}
		else {
			for (int i = 1; i <= 3; i++) {
				if (s.size() >= i && isValid(s.substr(0, i))) {
					if (k == 1) restore(s.substr(i), out + s.substr(0,i), k-1, res);
					else restore(s.substr(i), out + s.substr(0,i) + ".", k - 1, res);
				}
			}
		}
	}

	bool isValid(string s) {
		if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
		int sti = stoi(s);
		return sti >= 0 && sti <= 255;
	}
};


//94. Binary Tree Inorder Traversal

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		Traversal(root, res);
		return res;
	}

	void Traversal(TreeNode* root, vector<int>& res) {
		if (root != NULL) {
			Traversal(root->left, res);
			res.push_back(root->val);
			Traversal(root->right, res);
		}

	}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode* p = root;
		stack<TreeNode*> s;
		while (p || !s.empty) {
			while (p) {
				s.push_back(p);
				p = p->left;
			}
			p = s.top(); s.pop();
			res.push_back(p->val);
			p = p->right;
		}
		return res;
	}
};


//95. Unique Binary Search Trees II
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return{};
		return helper(1, n);
		
	}

	vector<TreeNode*> helper(int start, int end) {
		if (start > end) return { NULL };
		vector<TreeNode*> res;
		for (int i = start; i <= end; i++) {
			auto left = helper(start, i - 1), right = helper(i + 1, end);
			
			for (auto a : left) {
				for (auto b : right) {
					TreeNode* p = new TreeNode(i);
					p->left = a;
					p->right = b;
					res.push_back(p);
				}
			}
		}
		return res;
			
		
	}
};

//96. Unique Binary Search Trees
//Carteland num
class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};

//98. Validate Binary Search Tree
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}

	bool isValidBST(TreeNode * root, long min, long max) {
		if (!root) return true;
		if (root->val <= min || root->val >= max) return false;
		return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
	}
};

//100. Same Tree
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return helper(p, q);
	}

	bool helper(TreeNode* p,TreeNode* q) {
		if ((p && !q) || (!p && q)) return false;
		if (!p && !q) return true;
		if ((p->val == q->val) && helper(p->left,q->left) && helper(p->right, q->right)) return true;
		else return false;
	}
};
//101. Symmetric Tree
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);
		while (！q1.empty() && ！q2.empty()) {
			TreeNode* node1 = q1.front(); q1.pop();
			TreeNode* node2 = q2.front(); q2.pop();
			if (!node1 && !node2) continue;
			if ((!node1 && node2) || (node1 && !node2))return false;
			if (node1->val != node2->val) return false;
			q1.push(node1->left);
			q1.push(node1->right);
			q2.push(node2->right);
			q2.push(node2->left);
		}
		return true;
	}
};

//102. Binary Tree Level Order Traversal
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return {};
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* flag = new TreeNode(INT16_MIN);
		q.push(flag);
		while (!q.empty()) {
			TreeNode* node = q.front(); q.pop();
			vector<int> out;
			while (node->val != INT16_MIN) {
				out.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
				node = q.front(); q.pop();
			}
			res.push_back(out);
			if(!q.empty()) q.push(flag);
		}
		return res;
	}
};

//103. Binary Tree Zigzag Level Order Traversal
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return {};
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* flag = new TreeNode(INT16_MIN);
		int cnt = 0;
		q.push(flag);
		while (!q.empty()) {
			TreeNode* node = q.front(); q.pop();
			vector<int> out;
			while (node->val != INT16_MIN) {
				out.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
				node = q.front(); q.pop();
			}
			if (cnt % 2 == 1) reverse(out.begin(), out.end());
			res.push_back(out);
			cnt++;
			if (!q.empty()) q.push(flag);
		}
		return res;
	}
};

//104. Maximum Depth of Binary Tree
class Solution {
public:
	int maxDepth(TreeNode* root) {
		return helper(root);
	}

	int helper(TreeNode * root) {
		if (!root) return 0;
		int depth = max(helper(root->left), helper(root->right));
		return depth + 1;
	}
};

//105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
		if (pLeft > pRight || iLeft > iRight) return NULL;
		int i = 0;
		for (i = iLeft; i <= iRight; i++) {
			if (preorder[pLeft] == inorder[i]) break;
		}
		TreeNode* cur = new TreeNode(preorder[pLeft]);
		cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
		cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
		return cur;
	}
};

//106. Construct Binary Tree from Inorder and Postorder Traversal
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight) {
		if (iLeft > iRight || pLeft > pRight) return NULL;
		int i = 0;
		for (i = iLeft; i < inorder.size(); i++) {
			if (inorder[i] == postorder[pRight]) break;
		}
		TreeNode* cur = new TreeNode(postorder[pRight]);
		cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft-1);
		cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
		return cur;
	}
};

//107. Binary Tree Level Order Traversal II
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> out;
			for (int i = q.size(); i >0 ; i--) {
				TreeNode* node = q.front(); q.pop();
				out.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			res.push_back(out);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

//108 Convert Sorted Array to Binary Search Tree
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}

	TreeNode* helper(vector<int> &nums, int left,int right) {
		if (left > right) return NULL;
		int mid = left + (right - left) / 2;
		TreeNode * cur = new TreeNode(nums[mid]);
		cur->left = helper(nums, left, mid - 1);
		cur->right = helper(nums, mid + 1, right);
		return cur;
	}
};

//109. Convert Sorted List to Binary Search Tree
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return new TreeNode(head->val);
		ListNode* slow = head, *fast = head, *last = head;
		while (fast->next && fast->next->next) {
			last = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		last->next = NULL;
		TreeNode* cur = new TreeNode(slow->val);
		if (head != slow) cur->left = sortedListToBST(head);
		cur->right = sortedListToBST(fast);
		return cur;
	}
};

//110. Balanced Binary Tree
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int left = helper(root->left);
		int right = helper(root->right);
		if (abs(left - right) > 1) return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int helper(TreeNode* root) {
		if (!root) return 0;
		int left = helper(root->left);
		int right = helper(root->right);
		int mx = max(left, right);
		return ++mx;
	}
};

//111. Minimum Depth of Binary Tree
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return 1 + minDepth(root->right);
		if (!root->right) return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};

//112. Path Sum
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> out;
		helper(root, res, out, 0, sum);
	}

	void helper(TreeNode* root, vector<vector<int>>& res, vector<int>& out, int sum, int target) {
		if (!root) return;
		sum += root->val;
		out.push_back(root->val);
		if (!root->left && !root->right) {
			if (sum == target) {
				res.push_back(out);
			}
		}
		helper(root->left, res, out, sum, target);
		helper(root->right, res, out, sum, target);
		out.pop_back();
	}
};


//114. Flatten Binary Tree to Linked List
class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root) return;
		if (root->left) flatten(root->left);
		if (root->right) flatten(root->right);
		TreeNode *tmp = root->right;
		root->right = root->left;
		root->left = NULL;
		while (root->right) root = root->right;
		root->right = tmp;
	}
};

//116. Populating Next Right Pointers in Each Node

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
	Node* connect(Node* root) {
		queue<Node*> q;
		q.push(root);
		while (q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				Node* n = q.front(); q.pop();
				if (i < size -1	) n->next = q.front();
				if (n->left) q.push(n->left);
				if (n->right) q.push(n->right);
			}
		}
		return  root;
	}
};

//118. Pascal's Triangle


//119. Pascal's Triangle II
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1);
		res[0] = 1;
		for (int i = 1; i <= rowIndex; i++) {
			for (int j = i; j >= 1; --j) {
				res[j] += res[j - 1];
			}
		}
		return res;
	} 
};

//120. Triangle
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int size = triangle.size();
		vector<int> res(size);
		res[0] = triangle[0][0];
		for (int i = 1; i < size; i++) {
			for (int j = i; j >= 0; --j) {
				if (j == 0 || j == i) {
					res[j] = res[j] + triangle[i][j];
				}
				else {
					res[j] = triangle[i][j] + min(res[j - 1], res[j]);
				}

			}
		}
		sort(res.begin(), res.end());
		return	res[size - 1];

	}

	
};

//121. Best Time to Buy and Sell Stock
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0, buy = INT16_MAX;
		for (int price : prices) {
			buy = min(buy, price);
			res = max(res, price - buy);
		}
		return res;
	}
};

//122. Best Time to Buy and Sell Stock II
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0, size = prices.size();
		for (int i = 0; i < size-1; i++) {
			if (prices[i] < prices[i + 1])
				res += prices[i + 1] - prices[i];
		}
		return res;
	}
};

//125. Valid Palindrome
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		vector<char> a;
		vector<char> b;
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) {
				a.push_back(s[i]);
				b.push_back(s[i]);
			}
				
		}

		reverse(a.begin, a.end);
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
};

//129. Sum Root to Leaf Numbers
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		int sum = 0;
		string now = to_string(root->val);
		helper(root->left, sum, now);
		helper(root->right, sum, now);
		return sum;
	}

	void helper(TreeNode* root, int & sum, string now) {
		if (!root->left && !root->right) {
			now += to_string(root->val);
			sum += atoi(now.c_str());
			return;
		}
		now += to_string(root->val);
		helper(root->left, sum, now);
		helper(root->right, sum, now);
	}
};

//130. Surrounded Regions
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (i == 0 || j == 0 || i == board.size() || j == board[i].size())
					solveDFS(board, i, j);
			}
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '$') board[i][j] = 'O';
			}
		}
	}

	void solveDFS(vector<vector<char>>& board, int i, int j) {
		if (board[i][j] == 'O') {
			board[i][j] = '$';
			if (i > 0 && board[i - 1][j] == 'O') solveDFS(board, i - 1, j);
			if (j < board[i].size() && board[i][j + 1] == 'O') solveDFS(board, i, j + 1);
			if (i < board.size() && board[i + 1][j] == 'O') solveDFS(board, i + 1, j);
			if (j > 0 && board[i][j - 1] == 'O') solveDFS(board, i, j - 1);
		}
	}
};

//132. Palindrome Partitioning II
class Solution {
public:
	int minCut(string s) {
		if (s.empty()) return 0;
		int n = s.size();
		vector<vector<bool>> p(n, vector<bool>(n));
		vector<int> dp(n);
		for (int i = 0; i < n; ++i) {
			dp[i] = i;
			for (int j = 0; j <= i; ++j) {
				if (s[j] == s[i] && (i - j < 2 || p[j + 1][i - 1])) {
					p[j][i] = true;
					dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
				}
			}
		}
		return dp[n - 1];
	}
};

//133. Clone Graph
class Solution {
public:
	Node* cloneGraph(Node* node) {
		unordered_map<Node*, Node*> m;
		return helper(node, m);
	}

	Node* helper(Node* node, unordered_map<Node*, Node*> m) {
		if (!node) return NULL;
		if (m.count(node)) return m[node];
		Node* clone = new Node(node->val);
		m[node] = clone;
		for (Node* neighbor : node->neighbors) {
			clone->neighbors.push_back(helper(neighbor, m));
		}
		return clone;
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) return NULL;
		unordered_map<Node*, Node*> m;
		queue<Node*> q({ node });
		Node* clone = new Node(node->val);
		m[node] = clone;
		while (!q.empty()) {
			Node* t = q.front(); q.pop();
			for (Node* neighbor : t->neighbors) {
				if (!m.count(neighbor)) {
					m[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}
				m[t]->neighbors.push_back(m[neighbor]);
			}
		}
		return clone;
	}
};

//134. Gas Station
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		if (n == 1) {
			if (gas[0] >= cost[0]) return 0;
			else return -1;
		}
		for (int i = 0; i < n; ++i) {
			int remain = gas[i];
			int j = 1;
			for (; j <= n; ++j) {
				if ((remain - cost[(i + j - 1) % n]) >= 0) {
					remain = remain - cost[(i + j - 1) % n] + gas[(i + j) % n];
				}
				else
					break;
			}
			if (j - 1 == n) return i;
		}
		return -1;
	}
};
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0, sum = 0, start = 0;
		for (int i = 0; i < gas.size(); i++) {
			total += gas[i] - cost[i];
			sum += gas[i] - cost[i];
			if (sum < 0) {
				sum = 0;
				start = i + 1;
			}
		}
		return (total < 0) ? -1 : start;
	}

};

//136. Single Number
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto num : nums) res ^= num;
		return res;
	}
};

//137. Single Number II
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			if (m.count(nums[i]))
				m[nums[i]]++;
			else
				m[nums[i]] = 1;
		}
		for (const auto& one : m) {
			if (one.second == 1) {
				return one.first;
			}
		}
	}
};

//138. Copy List with Random Pointer

class Solution {
public:
	Node* copyRandomList(Node* head) {
		unordered_map<Node*, Node*> m;
		return helper(head, m);

	}

	Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
		if (!node) return NULL;
		if (m.count(node)) return m[node];
		Node* clone = new Node(node->val, NULL, NULL);
		m[node] = clone;
		clone->next = helper(node->next, m);
		clone->random = helper(node->random, m);
		return clone;
	}
};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) return NULL;
		Node* res = new Node(head->val, NULL, NULL);
		Node* cur = head->next, *node = res;
		unordered_map<Node*, Node*> m;
		m[head] = node;
		while (cur) {
			Node* clone = new Node(cur->val, NULL,NULL);
			node->next = clone;
			m[cur] = clone;
			node = node->next;
			cur = cur->next;
		}
		node = res;
		cur = head;
		while (cur) {
			node->random = m[cur->random];
			node = node->next;
			cur = cur->next;
		}
		return res;
	}

};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) return NULL;
		Node* cur = head;
		while (cur) {
			Node* t = new Node(cur->val, NULL, NULL);
			t->next = cur->next;
			cur->next = t;
			cur = t->next;
		}
		cur = head;
		while (cur) {
			if (cur->random) cur->next->random = cur->random->next;
			cur = cur->next->next;
		}
		cur = head;
		Node * res = head->next;
		while (cur) {
			Node * t = cur->next;
			cur->next = t->next;
			if (t->next) t->next = t->next->next;
			cur = cur->next;
		}
		return res;
	}
};

//139. Word Break
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<int> memo(s.size(), -1);
		return helper(s, 0, wordSet);
	}

	bool helper(string s, int start, unordered_set<string> & wordSet, vector<int> & memo) {
		if (start >= s.size()) return true;
		if (memo[start] != -1) return memo[start];
		int n = s.size();
		for (int i = start+1; i <= n; i++) {
			if (wordSet.count(s.substr(start, i - start)) && helper(s, i, wordSet))
				return memo[start] = 1;
		}
		return memo[start] = 0;
	}
};
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordereds_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size()+1);
		dp[0] = true;
		for (int i = 0; i < dp.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[j] && wordSet.count(s.substr(j, i - j))) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
};

//139. Word Break II
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		unordered_map<string, vector<string>> memo;
		return helper(s, wordSet, memo);
	}

	vector<string> helper(string s, unordered_set<string> & wordSet, unordered_map<string, vector<string>> memo) {
		if (memo.count(s)) return memo[s];
		if (s.empty()) return { "" };
		vector<string> res;
		int n = s.size();
		for (int i = 0; i <= n; i++) {
			if (wordSet.count(s.substr(0, i))) {
				vector<string> rem = helper(s.substr(i), wordSet, memo);
				for (string str : rem) {
					res.push_back(s.substr(0, i) + (str.empty() ? "" : " ") + str);
				}
			}
				
		}
		return memo[s] = res;
	}
};

//142. Linked List Cycle II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head) return NULL;
		unordered_map<ListNode*, int> m;
		while (head) {
			if (!m.count(head))
				m[head] = 1;
			else
				return head;
			head = head->next;
		}
		return NULL;
	}
};
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (!head) return NULL;
		ListNode* slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) break;
		}
		if (!fast || !fast->next) return NULL;
		slow = head;
		while (slow != fast) {
			slow = slow->next;

		}
	}
};

//143. Reorder List
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;
		vector<ListNode*> store;
		ListNode* node = head, *temp = new ListNode();
		while (node) {
			store.push_back(node);
			node = node->next;
		}
		int begin = 0, end = store.size();
		while (begin < end) {
			temp->next = store[begin];
			store[begin]->next = store[end];
			temp = store[end];
			begin++; end--;
		}
	}

	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;
		ListNode* fast = head, *slow = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* half = slow ->next, *temp1 = NULL, *temp2;
		ListNode* last = half;
		slow->next = NULL;
		while (last) {
			temp2 = last->next;
			last->next = temp1;
			temp1 = last;
			last = temp2;
		}	
		while (temp1 && head) {
			ListNode * next = head->next;
			head->next = temp1;
			temp1 = temp1->next;
			head->next->next = next;
			head = next;
		}
	}

};

//144. Binary Tree Preorder Traversal
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {

		vector<int> res;
		stack<TreeNode*> s;
		while (root || !s.empty()) {
			while (root) {
				res.push_back(root->val);
				root = root->left;
				s.push(root);
			}
			root = s.top(); s.pop();
			root = root->right;
		}
		return res;
	}
	
};


//145. Binary Tree Postorder Traversal
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				res.insert(res.begin(),p->val);
				p = p->right;
			}
			p = s.top();s.pop();
			p = p->left;
		}
		return res;
	}
};

//147. Insertion Sort List
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while (head) {
			ListNode* t = head->next;
			cur = dummy;
			while (cur->next && cur->next->val <= head->val) {
				cur = cur->next;
			}
			head->next = cur->next;
			cur->next = head;
			head = t;
		}
		return dummy->next;
	}
};

//148. Sort List
//QS
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* cur = head->next;
		ListNode* small = new ListNode(0), *large = new ListNode(0);
		ListNode* sp = small, *lp = large;
		while (cur) {
			if (cur->val <= head->val) {
				sp->next = cur;
				sp = cur;
			}
			else {
				lp->next = cur;
				lp = cur;
			}
			cur = cur->next;
		}
		sp->next = NULL;
		lp->next = NULL;
		small = sortList(small->next);
		large = sortList(large->next);
		cur = small;
		if (cur) {
			while (cur->next) cur = cur->next;
			cur->next = head;
			head->next = large;
			return small;
		}
		else {
			head->next = large;
			return head;
		}
	}
};
//MS
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* half = slow->next;
		slow->next = NULL;
		return merge(sortList(head), sortList(half));
	}
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1) cur->next = l1;
		if (l2) cur->next = l2;
		return dummy->next;
	}
};

//150. Evaluate Reverse Polish Notation
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<string> stack;
		unordered_set<string> operators({"+", "-", "*", "/"});
		for (int i = 0; i < tokens.size(); i++) {
			string s = tokens[i];
			if (operators.count(s)) {
				int fm = atoi(stack.top().c_str()); stack.pop();
				int sm = atoi(stack.top().c_str()); stack.pop();
				int res;
				if (s == "+") stack.push(to_string(sm + fm));
				if (s == "-") stack.push(to_string(sm - fm));
				if (s == "*") stack.push(to_string(sm * fm));
				if (s == "/") stack.push(to_string(sm / fm));
			}
			else {
				stack.push(s);
			}
		}
		return atoi(stack.top().c_str());
	}
};

//151. Reverse Words in a String
class Solution {
public:
	string reverseWords(string s) {
		s += " ";
		vector<string> resVec;
		string res;
		string word = "";
		int i = 0;
		while (s[i] == ' ') i++;
		while (i < s.size()) {
			if (s[i] == ' ') {
				resVec.insert(resVec.begin(), word);
				word = "";
				while (s[i] == ' ') i++;
			}
			else {
				word += s[i];
				i++;
			}
		}
		res += resVec[0];
		for (int i = 1; i < resVec.size(); i++)
			res += " " + resVec[i];
		return res;
	}

	string reverseWords(string s) {
		int storeIndex = 0, n = s.size();
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; i++) {
			if (s[i] != ' ') {
				if (storeIndex != 0) s[storeIndex++] = ' ';
				int j = i;
				while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
				reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
				i = j;
			}	
		}
		s.resize(storeIndex);
	}
};

//152. Maximum Product Subarray
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0], n = nums.size();
		vector<int> f(n, 0), g(n, 0);
		f[0] = nums[0];
		g[0] = nums[0];
		for (int i = 1; i < n; i++) {
			f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			res = max(res, f[i]);
		}
		return res;
	}
};

//153. Find Minimum in Rotated Sorted Array
class Solution {
public:
	int findMin(vector<int>& nums) {
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < res) res = nums[i];
		}
		return res;
	}
	
	int findMin(vector<int> & nums) {
		int left = 0, right = nums.size()-1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[right]) left = mid + 1;
			else right = mid;
		}
		return nums[right];
	}
};

//154. Find Minimum in Rotated Sorted Array II
class Solution {
public:
	int findMin(vector<int> & nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[right]) left = mid + 1;
			else if(nums[mid] < nums[right]) right = mid;
			else right--;
		}
		return nums[right];
	}
};

//215. Kth Largest Element in an Array
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {	
		int pivot = nums.back();
		vector<int> small, large;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] <= pivot)
				small.push_back(nums[i]);
			else
				large.push_back(nums[i]);
		}
		if (large.size() == k - 1)
			return pivot;
		else {
			if (large.size() >= k)
				return findKthLargest(large, k);
			else
				return findKthLargest(small, k - large.size() - 1);
		}
	}


};