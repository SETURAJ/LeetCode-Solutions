// https://leetcode.com/problems/count-vowels-permutation

class Solution {
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} }, // start
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
public:
    int countVowelPermutation(int n) {
        return solve(n, 's');                         // start with s
    }
    int solve(int rem, char prev) {
        if(rem == 0) return 1;                        // no need to pick further. We have formed 1 string of length = n.
        int ans = 0;
        for(auto c : mappings.at(prev))               // try each vowel allowed after prev character
            ans = (ans + solve(rem - 1, c)) % MOD;  
        return ans;
    }
};