#include<bits/stdc++.h>
using namespace std;

string keywords[32]={"auto","double","int","struct","break","else","long",
       "switch","case","enum","register","typedef","char",
       "extern","return","union","const","float","short",
       "unsigned","continue","for","signed","void","default",
       "goto","sizeof","voltile","do","if","static","while"};


bool iskeyword(string st){
    for(int i = 0;i<32; i++){
        if(keywords[i]==st) return 1;
    }
    return 0;
}

bool isother(string str){
    for(int i=0;i<str.size();i++){
        if(str[i]=='_'||str[i]=='.') continue;
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')){
            continue;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int number(string str){
    int cn = 0;
    for(int i =0; i<str.size();i++){
        if(str[i]=='.'){
            cn++;
        }
        else if(!isdigit(str[i])){
            return -1;
        }
    }
    if(cn==1) return 2;
    if(cn==0) return 1;
    return 0;
}

bool isarithmetic(string ch){
    if(ch=="+"||ch=="-"||ch=="*"||ch=="/"||ch=="%"||ch=="^"||ch=="=") return 1;
    return 0;
}

bool isrelational(string st){
    if(st=="<"||st==">"||st=="!="||st=="=="||st=="<="||st==">=") return 1;
    return 0;
}


void checker(string str){

    if(isother(str)&&!isarithmetic(str)&&!isrelational(str)){
            puts("Undefined");
        }
        else if(iskeyword(str)){
            puts("Keyword");
        }
        else if(str[0]=='_'||isalpha(str[0])){
            puts("Identifier");
        }
        else if(isarithmetic(str)){
            puts("Arithmetic Op");
        }
        else if(isrelational(str)){
            puts("Relational Op");
        }
        else{
            int x = number(str);
            if(x==-1){
                puts("Undefined");
            }
            else if(x==1){
                puts("Integer");
            }
            else if(x==2){
                puts("Float");
            }
            else{
                puts("Undefined");
            }
        }
}


int main(){

    string str;

    freopen("7_8.cpp","r",stdin);

    while(cin>>str){
        cout<<str<<" ";
        checker(str);
    }
    return 0;
}
