#include <bits/stdc++.h>
using namespace std;

string codes[11] ={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","yz"}; 

void printKPC(string ques,string ans)
{
    if(ques.size()==0)
    {
        cout << ans << endl;
        return;
    }
    
    char ch = ques[0];
    string rem = ques.substr(1,ques.size());
    
    string code4ch = codes[ch - '0'];
    for(int i=0;i<code4ch.size();++i)
    {
        char cho = code4ch[i];
        printKPC(rem,ans+cho);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad.
    You do not need to return anything just print them.
    */
    printKPC(to_string(num),"");
}

