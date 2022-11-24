#include<bits/stdc++.h>
using namespace std;

string encrypt(string s) {
	float n = s.length();
	int row = ceil(n/5),col = 5;
	char arr[row][col];
	for(int i = 0;i < row; ++i) {
		for(int j = 0;j < col; ++j) {
			if((i*col + j) >= s.length()) {
				//1 is the bogus character  
				arr[i][j] = '1' ;
			}
			else
				arr[i][j] = s[i*col + j];
		}
	}
	vector<int>order;  
	//For example order of columns could be 1 0 2 3 4
	cout<<"Enter the order of repositioning columns: ";
	int x;
	for(int i = 0;i < col; ++i) {
		cin>>x;
		order.push_back(x);
	}
	string encString = "";
	for(int i = 0;i < col; ++i) {
		for(int j = 0;j < row; ++j) {
			encString += arr[j][order[i]];
		}	
	}
	return encString;
}

int main() {
	
	string s;
	cout<<"Enter the plain text: ";
	cin>>s;
	cout<<encrypt(s);

}
