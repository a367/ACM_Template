/*==================================================*\
|递推求欧拉函数 phi(i)
\*==================================================*/
for (i = 1; i <= maxn; i++) phi[i] = i;
for (i = 2; i <= maxn; i += 2) phi[i] /= 2;
for (i = 3; i <= maxn; i += 2) if(phi[i] == i) {
	for (j = i; j <= maxn; j += i) 
		phi[j] = phi[j] / i * (i - 1);
}
/*==================================================*\
|单独求欧拉函数 phi(x)
\*==================================================*/
unsigned euler(unsigned x)
{// 就是公式
unsigned i, res=x;
for (i = 2; i < (int)sqrt(x * 1.0) + 1; i++)
if(x%i==0) {
	res = res / i * (i - 1);
	while (x % i == 0) x /= i; // 保证i一定是素数
	}
	if (x > 1) res = res / x * (x - 1);
	return res;
}
/*==================================================*\
| GCD 最大公约数
\*==================================================*/
int gcd(int x, int y){
	if (!x || !y) return x > y ? x : y;
	for (int t; t = x % y; x = y, y = t);
	return y;
}
/*==================================================*\
| 快速 GCD
\*==================================================*/
int kgcd(int a, int b){
	if (a == 0) return b;
	if (b == 0) return a;
	if (!(a & 1) && !(b & 1)) return kgcd(a>>1, b>>1) << 1;
	else if (!(b & 1)) return kgcd(a, b>>1);
	else if (!(a & 1)) return kgcd(a>>1, b);
	else return kgcd(abs(a - b), min(a, b));
}
/*==================================================*\
| 扩展 GCD
| 求x, y使得gcd(a, b) = a * x + b * y;
\*==================================================*/
int extgcd(int a, int b, int & x, int & y){
	if (b == 0) { x=1; y=0; return a; }
	int d = extgcd(b, a % b, x, y);
	int t = x; x = y; y = t - a / b * y;
	return d;
}
/*==================================================*\
| 求 m^n mod k 时间复杂度为 O((logn)^3).
\*==================================================*/
 int quickpow(int m, int n, int k){
    int b = 1;
	while (n > 0){
		if (n & 1)
			b = (b*m)%k;
		n = n >> 1 ;
		m = (m*m)%k;
    }
    return b;
}

/*==================================================*\
| 阶乘最后非零位,复杂度 O(nlogn)
\*==================================================*/
//返回该位, n 以字符串方式传入
#include <string.h>
#define MAXN 10000
int lastdigit(char* buf){
	const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
	int len=strlen(buf),a[MAXN],i,c,ret=1;
	if (len==1) return mod[buf[0]-'0'];
	for (i=0;i<len;i++) a[i]=buf[len-1-i]-'0';
	for (;len;len-=!a[len-1]){
		ret=ret*mod[a[1]%2*10+a[0]]%5;
		for (c=0,i=len-1;i>=0;i--)
			c=c*10+a[i],a[i]=c/5,c%=5;
	}
	return ret+ret%2*5;
}