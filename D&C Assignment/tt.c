#include<stdio.h>
#include<string.h>
char* remove_multiple_spaces(char *s){
    int i,j,k,m,cnt,n,len;
    len=strlen(s);
    char *p;
    cnt=0;
    for(i=0; i<len; i++){
        if(s[i]==' ' && s[i+1]==' '){
            cnt++;
        }
    }
    n=len-cnt+1;
    printf("%d\n",n);
    p=(char*)malloc(n*sizeof(char));
    k=0;
    for(j=0;j<len;j++){
        if(s[j]==' ' && s[j+1]==' '){
            p[k++]=' ';                     
            for(m=j;s[m]==' ';m++)
            {
            } j=m;
            p[k]=s[j];
            k++;
        }
            else{p[k]=s[j];k++;}
    }
    p[k++]='\0';
    return p;
}
int main(){
    char a[]="Tushmi is   not   single";//True
    char *r;// scanf("%[^\n]s",str)
    r=remove_multiple_spaces(a);
    printf("%s",r);
    free(r);
    return 0;
}