// C++ program to find pairs with given sum such 
// that one element of pair exists in one BST and 
// other in other BST. 
#include<bits/stdc++.h> 
using namespace std; 

// A binary Tree node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new BST node 
// with key as given num 
struct Node* newNode(int num) 
{ 
	struct Node* temp = new Node; 
	temp->data = num; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to insert a given key to BST 
Node* insert(Node* root, int key) 
{ 
	if (root == NULL) 
		return newNode(key); 
	if (root->data > key) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 

// store storeInorder traversal in auxiliary array 
void storeInorder(Node *ptr, vector<int> &vect) 
{ 
	if (ptr==NULL) 
		return; 
	storeInorder(ptr->left, vect); 
	vect.push_back(ptr->data); 
	storeInorder(ptr->right, vect); 
} 

// Function to find pair for given sum in different bst 
// vect1[] --> stores storeInorder traversal of first bst 
// vect2[] --> stores storeInorder traversal of second bst 
void pairSumUtil(vector<int> &vect1, vector<int> &vect2, 
												int sum) 
{ 
	// Initialize two indexes to two different corners 
	// of two vectors. 
	int left = 0; 
	int right = vect2.size() - 1; 

	// find pair by moving two corners. 
	while (left < vect1.size() && right >= 0) 
	{ 
		// If we found a pair 
		if (vect1[left] + vect2[right] == sum) 
		{ 
			cout << "(" << vect1[left] << ", "
				<< vect2[right] << "), "; 
			left++; 
			right--; 
		} 

		// If sum is more, move to higher value in 
		// first vector. 
		else if (vect1[left] + vect2[right] < sum) 
			left++; 

		// If sum is less, move to lower value in 
		// second vector. 
		else
			right--; 
	} 
} 

// Prints all pairs with given "sum" such that one 
// element of pair is in tree with root1 and other 
// node is in tree with root2. 
void pairSum(Node *root1, Node *root2, int sum) 
{ 
	// Store inorder traversals of two BSTs in two 
	// vectors. 
	vector<int> vect1, vect2; 
	storeInorder(root1, vect1); 
	storeInorder(root2, vect2); 

	// Now the problem reduces to finding a pair 
	// with given sum such that one element is in 
	// vect1 and other is in vect2. 
	pairSumUtil(vect1, vect2, sum); 
} 

// Driver program to run the case 
int main() 
{ 
	// first BST 
	struct Node* root1 = NULL; 
	root1 = insert(root1, 8); 
	root1 = insert(root1, 10); 
	root1 = insert(root1, 3); 
	root1 = insert(root1, 6); 
	root1 = insert(root1, 1); 
	root1 = insert(root1, 5); 
	root1 = insert(root1, 7); 
	root1 = insert(root1, 14); 
	root1 = insert(root1, 13); 

	// second BST 
	struct Node* root2 = NULL; 
	root2 = insert(root2, 5); 
	root2 = insert(root2, 18); 
	root2 = insert(root2, 2); 
	root2 = insert(root2, 1); 
	root2 = insert(root2, 3); 
	root2 = insert(root2, 4); 

	int sum = 10; 
	pairSum(root1, root2, sum); 

	return 0; 
} 
