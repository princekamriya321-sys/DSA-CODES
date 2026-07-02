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

            // opposite bit
            if(bit == 1){
            if(curr->child[1-bit] != nullptr){
              ans += pow(2,i);
              curr = curr->child[1-bit];
            } else {
                // ans += pow(2,i)*0; 
            curr = curr->child[bit];
            }
        } else { // bit == 0
    if(curr->child[1-bit] != nullptr){
                ans += pow(2,i);
                curr = curr->child[1-bit];
                } else {
                    // ans += pow(2,i)*0; 
                curr = curr->child[bit];
                }
        }
        }

        return ans;
    }
};

int maxXOR(vector<int> &nums)
{
    Trie trie;

    for(int x : nums)
        trie.insert(x);

    int ans = 0;

    for(int x : nums)
    {
        ans = max(ans, trie.search(x));
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << maxXOR(nums);

    return 0;
}