#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node* child[26];
    bool isEnd;

    Node()
    {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;

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
            {
                curr->child[idx] = new Node();
            }

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word)
    {
        Node* curr = root;

        for(char ch : word)
        {
            int idx = ch - 'a';

            if(curr->child[idx] == NULL)
                return false;

            curr = curr->child[idx];
        }

        return curr->isEnd;
    }
};

int main()
{
    Trie trie;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
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

        if(trie.search(s))
            cout << "Present\n";
        else
            cout << "Not Present\n";
    }

    return 0;
}