// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	if (str.length() == 0 || str[0] == 'N')
		return NULL;
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	Node *root = new Node(stoi(ip[0]));

	queue<Node*> queue;
	queue.push(root);

	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		Node* currNode = queue.front();
		queue.pop();

		string currVal = ip[i];

		if (currVal != "N") {

			currNode->left = new Node(stoi(currVal));

			queue.push(currNode->left);
		}

		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];
		if (currVal != "N") {

			currNode->right = new Node(stoi(currVal));

			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

 // } Driver Code Ends





/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains
a duplicate subtree of size 2 or more else returns false*/
unordered_map<string,int> m;
void make_string(Node *root)
{
    if(root==NULL)
        return;
    string s="";
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *ptr=q.front();
        q.pop();
        s=s+to_string(ptr->data);
        if(ptr->left!=NULL)
            q.push(ptr->left);
        if(ptr->right!=NULL)
            q.push(ptr->right);
    }
    m[s]++;
}

bool dupSub(Node *root)
{
    if(root==NULL)
        return true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *ptr=q.front();
        q.pop();
        if(ptr->left!=NULL&&ptr->right!=NULL)
            make_string(ptr);
        if(ptr->left!=NULL)
            q.push(ptr->left);
        if(ptr->right!=NULL)
            q.push(ptr->right);
    }
    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->first << "      " << i->second
             << endl;
    return true;
}


// { Driver Code Starts.
int main()
{

	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		//Solution ob;
		cout << dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends
