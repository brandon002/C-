#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//referensi:https://cppsecrets.com/users/22319897989712197103975756505164103109971051084699111109/String-Compression.php
int compress(const string& s)
{
    size_t counter = 1;
    char current = s[0];
    for (char c : s)
    {
        if (c != current)
        {
            ++counter;
        }
		current = c;
        
    }

    return counter;
}

int main(int argc, char** argv)
{
	string strink;
	
	cin>>strink;
	int tes;
	cin>>tes;
	
	int a,b;
	for(int i=0;i<tes;i++){
		cin>> a >> b;//cout<<"P"<<endl;
		string str = strink.substr(a-1,b-a+1); //cout<<"P";
		cout<<compress(str)<<endl; 
	}
}

