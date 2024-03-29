// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
    int ans = 0;

bool isSubSeq(string &s,string t){

	int n = s.size();
	int m = t.size();

	int i = 0;
	int j = 0;

	for(int i = 0; i < n and j < m; i++){
		if(s[i] == t[j]) j++;
	}

	if(j == m) return true;// if we can make the size equal to the 2nd string then it is possible otherwise not 
	else return false;
}
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();

	map<string,int> m;// for storing the duplicate entries we can have duplicate entries here 

	for(int i = 0; i < n; i++){
		m[words[i]]++;
	}

	for(auto it : m){
		if(isSubSeq(s,it.first)) ans += it.second;
	}

	return ans;
    }
};