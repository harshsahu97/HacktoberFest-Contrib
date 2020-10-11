// C++ program to find the maximum number of 
// Edge-Disjoint Spanning tree possible 

#include <bits/stdc++.h> 
using namespace std; 

// Function to calculate max number of 
// Edge-Disjoint Spanning tree possible 
float edgeDisjoint(int n) 
{ 
	float result = 0; 

	result = floor(n / 2); 

	return result; 
} 

// Driver code 
int main() 
{ 
	int n = 4; 

	cout << edgeDisjoint(n); 

	return 0; 
} 
