#include<bits/stdc++.h>
using namespace std;

bool isOther(char str[]){
    for(int i=0;str[i];i++){
        //cout<<str[i]<<endl;
        if(str[i]=='_'&&i==2) continue;
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')){
            continue;
        }
        else return 1;
    }
    return 0;
}

bool isBinary(char str[]){
    if(strlen(str)<2) return 0;
    if(str[0]!='0') return 0;
    for(int i=1;str[i];i++){
        if(str[i]!='1'&&str[i]!='0') return 0;
    }
    return 1;
}

bool isValid(char str[]){
    if(strlen(str)<4) return 0;
    for(int i=3;str[i];i++){
        if(str[i]=='_') return 0;
    }
    return 1;
}

int main(){
	int k=0;
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	for(k=0;k<=3;k++){
    char str[1000];
    cin>>str;
    //strcpy(str,"0011");

    if(isOther(str)){
        puts("Undefined");
    }
    else if(str[0]=='c'&&str[1]=='h'&&str[2]=='_'&&isValid(str)){
        puts("Character Variable");
    }
    else if(str[0]=='b'&&str[1]=='n'&&str[2]=='_'&&isValid(str)){
        puts("Binary Variable");
    }
    else if(isBinary(str)){
        puts("Binary Number");
    }
    else puts("Undefined");
}

    return 0;
}
