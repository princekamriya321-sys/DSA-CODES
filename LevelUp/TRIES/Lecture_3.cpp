#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node* child[26];
    int prefixCount;
    bool isEnd;

    Node()
    {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;

        prefixCount = 0;
        isEnd = false;
    }
};

class Trie
{
public:

    Node* root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node* curr = root;

        for(char ch : word)
        {
            int idx = ch - 'a';

            if(curr->child[idx] == NULL)
                curr->child[idx] = new Node();

            curr = curr->child[idx];

            curr->prefixCount++;
        }

        curr->isEnd = true;
    }

    int countPrefix(string word)
    {
        Node* curr = root;

        for(char ch : word)
        {
            int idx = ch - 'a';

            if(curr->child[idx] == NULL)
                return 0;

            curr = curr->child[idx];
        }

        return curr->prefixCount;
    }
};

int main()
{
    Trie trie;

    int n;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }

    int q;
    cin >> q;

    while(q--)
    {
        string s;
        cin >> s;

        cout << trie.countPrefix(s) << endl;
    }

    return 0;
}