#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int dictionary_size;
    cout << "Enter the size of the dictionary:";
    cin>>dictionary_size;
    string dict[dictionary_size];
    for(int i=0;i<dictionary_size;i++){
        cout <<"Enter a word: ";
        cin >> dict[i];
    }
    int str_size;
    cout << "How many lines are there ? ";
    cin >> str_size;
    string str[str_size];
    for(int i=0;i<str_size;i++){
        cout << "Enter a string: ";
        cin>>str[i];
    }
    for (int c=0; c<str_size; c++) {
        int g_count=0;
        for(int i=0;i<dictionary_size;i++){
            string s=dict[i];
            map<char,int>mp;
            for(int i=1;i<s.length()-1;i++)
                mp[s[i]]++;
            set<string> st;
            for(int i=0;i<str[c].length();i++){
                //below if() is for checking if any substring occurs whose first and last char is same 
                if(str[c][i]==s[0] && str[c][i+s.length()-1]==s[s.length()-1] && (i+s.length()-1)<str[c].length()){
                    map<char,int>mp1;
                    for(int j=i+1;j<i+s.length()-1;j++)
                        mp1[str[c][j]]++;
                    if(mp1==mp){
                        string r=str[c].substr(i,s.length()); // string r is required string
                        st.insert(r); // used stack as we want unique strings
                    }
                }
            }
            //cout<<dict[i]<<" "<<st.size()<<endl;
            g_count+=st.size();
            
        }
        cout<<"Case #" << c+1 << ": " <<g_count<<endl;
    }
    
    return 0;
}
