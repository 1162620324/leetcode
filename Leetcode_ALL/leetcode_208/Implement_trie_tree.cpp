#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100010;
int h[N];

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", &h[i]);

    while(m --)
    {
        int order, k;
        cin >> order >> k;
        if( order == 1)
            sort(h, h + k);
        else
            sort(h, h + k, greater<int>());
    }

    for (int i = 0; i < n; i ++) printf("%d ", h[i]);

    return 0;
}


// class Trie {
// private:
//     vector<Trie*> children;
//     bool isEnd;

//     Trie* searchPrefix(string prefix){
//         Trie* node = this;
//         for(char ch: prefix){
//             ch -= 'a';
//             if(node->children[ch] == NULL){
//                 return NULL;
//             }
//             node = node -> children[ch];
//         }
//         return node;
//     }
// public:

//     /** Initialize your data structure here. */
//     Trie() : children(26), isEnd(false){}   
    
    
//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         Trie* node = this;
//         for(char ch: word){
//             ch -= 'a';
//             if(node -> children[ch] == NULL){
//                 node -> children[ch] = new Trie();
//             }
//             node = node -> children[ch];
//         }
//         node -> isEnd = true;
//     }
    
//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         Trie* node = searchPrefix(word);
//         return node != NULL && node -> isEnd == true ;
//     }
    
//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string prefix) {
//         return this->searchPrefix(prefix) != NULL;
//     }
// };