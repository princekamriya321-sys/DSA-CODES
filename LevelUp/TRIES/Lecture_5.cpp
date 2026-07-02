#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node* child[2];

    Node()
    {
        child[0] = nullptr;
        child[1] = nullptr;
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

    void insert(int num)
    {
        Node* curr = root;

        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if(curr->child[bit] == nullptr)
                curr->child[bit] = new Node();

            curr = curr->child[bit];
        }
    }

    int search(int num)
    {
        Node* curr = root;
        int ans = 0;

        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if(curr->child[1-bit] != nullptr)
            {
                ans |= (1 << i);
                curr = curr->child[1-bit];
            }
            else
            {
                curr = curr->child[bit];
            }
        }

        return ans;
    }
};

int maxXORSubarray(vector<int> &arr)
{
    Trie trie;

    trie.insert(0);          // Prefix XOR before starting

    int prefixXor = 0;
    int ans = 0;

    for(int x : arr)
    {
        prefixXor ^= x;

        ans = max(ans, trie.search(prefixXor));

        trie.insert(prefixXor);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxXORSubarray(arr);

    return 0;
}