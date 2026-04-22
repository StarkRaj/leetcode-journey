#include <string>
#include<vector>
#include<unordered_map>
using namespace std;

struct trie {
    unordered_map<char, trie*> ch;
    bool isEnd = false;
};

class Solution {
public:
    trie* root = new trie();
    trie* insert(trie* node, char letter) {
        if (node->ch.find(letter) != node->ch.end())
            return node->ch[letter];
        node->ch[letter] = new trie();
        node = node->ch[letter];
        return node;
    }

    bool dfs(trie* node, string &word, int count, int i) {
        if (count < 0)
            return false;
        if (i == word.size()) {
            return node->isEnd;
        }
        if (node->ch.find(word[i]) != node->ch.end())
            if (dfs(node->ch[word[i]], word, count, i + 1))
                return true;
        if (count > 0) {
            for (auto j : node->ch) {
                if (dfs(j.second, word, count - 1, i + 1))
                    return true;
            }
        }
        return false;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        for (string word : dictionary) {
            trie* start = root;
            for (char c : word) {
                start = insert(start, c);
            }
            start->isEnd = true;
        }
        vector<string> ans;
        for (string query : queries) {
            bool isFound = dfs(root, query, 2, 0);
            if (isFound)
                ans.push_back(query);
        }
        return ans;
    }
};

//int main()
//{
//    Solution s = Solution();
//    //vector<string> queries = { "tsl","sri","yyy","rbc","dda","qus","hyb","ilu","ahd" };
//    //vector<string> dictionary = { "uyj","bug","dba","xbe","blu","wuo","tsf","tga" };
//    //vector<string> queries = { "word","note","ants","wood" };
//    //vector<string> dictionary = { "wood","joke","moat" };
//    vector<string> queries = { "prfturjd","iarapqqk","aokbrtmx","yafmjorj","larakqqk","nliynmpm","isikkcws","laraeqqk" };
//    vector<string> dictionary = { "apahhijt","larapqqk","isukkcws","siqqoacj","nloynmpm" };
//
//    vector<string> ans = s.twoEditWords(queries, dictionary);
//    return 0;
//}