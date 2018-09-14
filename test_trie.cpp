#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct trieNode{
	bool end;
	trieNode *point[26];
};
trieNode* newnode(void)
{
	trieNode *node ;
	node = (trieNode*)malloc(sizeof(trieNode));
	node->end = false;
	for ( int i = 0 ; i < 26 ; i++)
	{
		node->point[i] = NULL;
	}
	return node;
}
void insert(string s , trieNode *root)
{
	for ( int i = 0 ; i < s.length() ; i++)
	{
		if ( root->point[s[i]-'a'] == NULL)
		{
			trieNode *node = newnode();
			root->point[s[i]-'a'] = node;
		}
		root = root->point[s[i]-'a'];
	}
	root->end = true;
}
bool search (string s,trieNode *root)
{
	for ( int i = 0 ; i < s.length() ; i++)
	{
		if ( root->point[s[i]-'a'] == NULL)
		{
			return false;
		}
		root = root->point[s[i]-'a'];
	}
	if ( root != NULL && root->end == true)
	{
		return true;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	trieNode *root;
	root = newnode();
	while(n--)
	{
		string s;
		cin>>s;
		insert(s,root);
	}
	int n1;
	cin>>n1;
	while(n1--)
	{
		string s;
		cin>>s;
		cout<<search(s,root)<<endl;
	}
	return 0;
}
