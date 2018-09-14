#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
	TrieNode *characters[26];
	bool end;
};
TrieNode* new_node (void)
{
	TrieNode* node;
	node = (TrieNode*)malloc(sizeof(TrieNode));
	for ( int i = 0 ; i < 26 ; i++)
	{
		node->characters[i] = NULL;
	}
	node->end = false;
	return node;
}
bool search ( string s , TrieNode* root)
{
	TrieNode* temp = root;
	for ( int i = 0 ; i < s.length() ; i++)
	{
		if (temp->characters[s[i]-'a'] == NULL)
		{
			return false;
		}		
		temp = temp->characters[s[i]-'a'];
	}
	if ( temp != NULL && temp->end )
	{
		return true;
	}
}
void insert (string s , TrieNode* root)
{
	TrieNode* temp = root;
	for ( int i = 0 ; i < s.length() ; i++)
	{
		int index = s[i]-'a';
		if ( temp->characters[index] == NULL)
		{
			temp->characters[index] = new_node();// create node;
		}
		temp = temp->characters[index];
	}
	temp->end = true;
}
int main()
{
	int t;
	cin>>t;
	TrieNode* root;
	root = new_node();
	while(t--)
	{
		string s;
		cin>>s;
		insert(s,root);
	}
	int i;
	cin>>i;
	while (i--)
	{
		string s;
		cin>>s;
		cout<<search(s,root)<<endl;
	}
	return 0;
}
