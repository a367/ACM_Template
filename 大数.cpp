/*==================================================*\
| 求N的阶乘, 返回阶乘结果的位数
| 本程序直接输出n!的结果，需要返回结果请保留long a[]
\*==================================================*/
int factorial(int n)
{
    long a[10000];
    int i,j,l,c,m=0,w;
    a[0]=1;
    for(i=1; i<=n; i++)
    {
        c=0;
        for(j=0; j<=m; j++)
        {
            a[j]=a[j]*i+c;
            c=a[j]/10000;
            a[j]=a[j]%10000;
        }
        if(c>0)
        {
            m++;
            a[m]=c;
        }
    }
    w=m*4+log10(a[m])+1;
    printf("\n%ld",a[m]);
    for(i=m-1; i>=0; i--) printf("%4.4ld",a[i]);
    return w;
} 
/*==================================================*\
| 大数相乘， s存放结果
\*==================================================*/
void mult(char a[],char b[],char s[])
{
    int i,j,k=0,alen,blen,sum=0,res[65][65]={0},flag=0;
    char result[65];
    alen=strlen(a);blen=strlen(b); 
    for (i=0;i<alen;i++)
    for (j=0;j<blen;j++) res[i][j]=(a[i]-'0')*(b[j]-'0');
    for (i=alen-1;i>=0;i--)
        {
            for (j=blen-1;j>=0;j--) sum=sum+res[i+blen-j-1][j];
            result[k]=sum%10;
            k=k+1;
            sum=sum/10;
        }
    for (i=blen-2;i>=0;i--)
        {
            for (j=0;j<=i;j++) sum=sum+res[i-j][j];
            result[k]=sum%10;
            k=k+1;
            sum=sum/10;
        }
    if (sum!=0) {result[k]=sum;k=k+1;}
    for (i=0;i<k;i++) result[i]+='0';
    for (i=k-1;i>=0;i--) s[i]=result[k-1-i];
    s[k]='\0';
    while(1)
        {
        if (strlen(s)!=strlen(a)&&s[0]=='0') 
            strcpy(s,s+1);
        else
            break;
        }
}
/*==================================================*\
| 大数相乘， back存放结果
\*==================================================*/
void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
    c=(char *) malloc(l*sizeof(char));
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=0;up=0;
    while(i>=0||j>=0)
        {
            if(i<0) x='0'; else x=a[i];
            if(j<0) y='0'; else y=b[j];
            z=x-'0'+y-'0';
            if(up) z+=1;
            if(z>9) {up=1;z%=10;} else up=0;
            c[k++]=z+'0';
            i--;j--;
        }
    if(up) c[k++]='1';
    i=0;
    c[k]='\0';
    for(k-=1;k>=0;k--)
        back[i++]=c[k];
    back[i]='\0';
} 
/*==================================================*\
| 大数相减，s1-s2 t存放结果(不考虑结果为负数情况)
\*==================================================*/
void sub(char s1[],char s2[],char t[])
{
    int i,l2,l1,k;
    l2=strlen(s2);l1=strlen(s1);
    t[l1]='\0';l1--;
    for (i=l2-1;i>=0;i--,l1--)
        {
        if (s1[l1]-s2[i]>=0) 
            t[l1]=s1[l1]-s2[i]+'0';
        else
            {
            t[l1]=10+s1[l1]-s2[i]+'0';
            s1[l1-1]=s1[l1-1]-1;
            }
        }
    k=l1;
    while(s1[k]<0) {s1[k]+=10;s1[k-1]-=1;k--;}
    while(l1>=0) {t[l1]=s1[l1];l1--;}
loop:
    if (t[0]=='0') 
        {
        l1=strlen(s1);
        for (i=0;i<l1-1;i++) t[i]=t[i+1];
        t[l1-1]='\0';
        goto loop;
        }
    if (strlen(t)==0) {t[0]='0';t[1]='\0';}
} 

