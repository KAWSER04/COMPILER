#include <stdio.h>
#include <string.h>
char grammar[][10] = {"E+E","E-E","E*E","E/E","(E)","a","b","c"};
char target[100],str[100];

void replace(int pos,char *s){
    int i,ln_tar,ln_gram;
    ln_gram=strlen(s);
    ln_tar=strlen(target);
    for(i=0;i<ln_gram;i++){
        target[i+pos]=s[i];
    }
}

int main(){
    int i,j,ln,op;
    strcpy(target,"E");
    scanf("%s",str);
    ln=strlen(str);
    puts(target);
    for(i=0,j=0;i<ln;){
        if(target[j]=='E' && i+1<ln){
            switch (str[i+1]){
                case '+':
                    op=0;
                    break;
                case '-':
                    op=1;
                    break;
                case '*':
                    op=2;
                    break;
                case '/':
                    op=3;
                    break;
                case '(':
                    op=4;
                    break;
            }
            replace(j,grammar[op]);
            puts(target);
            target[j]=str[i];
            puts(target);
            i=i+2;
            j=j+2;
        }
        else if(target[j]=='E'){
            target[j]=str[i];
            puts(target);
            i++;
        }
    }
    return 0;
}
