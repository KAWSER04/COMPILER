#include<bits/stdc++.h>
using namespace std;

char str[1000],tr[1000];
char gr[][10] = {"E+E","E-E","E*E","E/E","(E)","a","b","c"};

void replac(int pos,char st[]){
    int i;
    for(i=0;st[i];i++){
        tr[pos+i] = st[i];
    }
    tr[pos+i] = '\0';
}

int main(){
    int i,j,ln,op;
    cin>>str;
    strcpy(tr,"E");
    ln = strlen(str);
    puts("E");
    for(i=0,j=0;i<ln;){
            if(i+1<ln){
            if(str[i+1]=='+') op = 0;
            else if(str[i+1]=='-') op = 1;
            else if(str[i+1]=='*') op = 2;
            else op =3;
            replac(j,gr[op]);
            puts(tr);
        }
        tr[j] = str[i];
        puts(tr);
        j += 2;
        i += 2;
    }

    return 0;
}
