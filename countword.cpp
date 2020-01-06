#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int dictionary_size;
	cin>>dictionary_size;
	string dict[dictionary_size];
	for(int i=0;i<dictionary_size;i++)cin>>dict[i];
	string str;
	cin>>str;
	int g_count=0;
	for(int i=0;i<dictionary_size;i++){
		string s=dict[i];
		map<char,int>mp;
		for(int i=1;i<s.length()-1;i++)
			mp[s[i]]++;
		set<string> st;
		for(int i=0;i<str.length();i++){
			//below if() is for checking if any substring occurs whose first and last char is same 
			if(str[i]==s[0] && str[i+s.length()-1]==s[s.length()-1] && (i+s.length()-1)<str.length()){
				
				map<char,int>mp1;
				for(int j=i+1;j<i+s.length()-1;j++)
					mp1[str[j]]++;
				
				if(mp1==mp){
					string r=str.substr(i,s.length()); // string r is required string
					st.insert(r); // used stack as we want unique strings
				}
			}
		}
		
		cout<<dict[i]<<" "<<st.size()<<endl;
		g_count+=st.size();
		
	}
	cout<<"final ans "<<g_count<<endl;
	
	return 0;
}
