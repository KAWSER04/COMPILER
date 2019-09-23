#include<bits/stdc++.h>
using namespace std;

char str[100];

bool isother(){
    for(int i=0;str[i];i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')||str[i]=='.'){
            continue;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int isFloat(){
    int cn=0,i;
    for(i=0;str[i]!='.';i++){
        if(str[i]=='.')continue;
        if(str[i]<'0'||str[i]>'9') return 0;
    }
    for(i++;str[i];i++){
        if(str[i]<'0'||str[i]>'9') return 0;
        cn++;
    }
    return cn;
}

int main(){
	int k;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
  for(k=0;k<5;k++){
  	
  	
    cin>>str;
    //cout<<str[1];

    int ln = strlen(str);

    if(isother()){
        puts("Undefined");
    }
    else if((str[0]>='a'&&str[0]<='h')||(str[0]>='A'&&str[0]<='H')||(str[0]>='o'&&str[0]<='z')||(str[0]>='O'&&str[0]<='Z')){
        puts("Float Variable");
    }
    else if((isFloat()==2||isFloat()==1)&&((str[0]>='1'&&str[0]<='9')||(str[0]=='.'||(str[0]=='0'&&str[1]=='.')))){
        //printf("%d\n",isFloat());
        puts("Float Number");
    }
    else if(isFloat()>2&&(str[0]>='1'&&str[0]<='9'||(str[0]=='.'||(str[0]=='0'&&str[1]=='.')))){
        puts("Double Number");
    }
    else{
        puts("Undefined");
    }
}
    return 0;
}
