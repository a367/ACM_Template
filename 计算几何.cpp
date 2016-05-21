/*==================================================*\
| Graham 求凸包 O(N * logN)
| CALL: nr = graham(pnt, int n, res); res[]为凸包点集;
\*==================================================*/
struct point { double x, y; };
bool mult(point sp, point ep, point op){
	return (sp.x - op.x) * (ep.y - op.y)
		>= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r){
	return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[], int n, point res[]){
	int i, len, k = 0, top = 1;
	sort(pnt, pnt + n);
	if (n == 0) return 0; res[0] = pnt[0];
	if (n == 1) return 1; res[1] = pnt[1];
	if (n == 2) return 2; res[2] = pnt[2];
	for (i = 2; i < n; i++) {
		while (top && mult(pnt[i], res[top], res[top-1]))
			top--;
		res[++top] = pnt[i];
	}
	len = top; res[++top] = pnt[n - 2];
	for (i = n - 3; i >= 0; i--) {
		while (top!=len && mult(pnt[i], res[top],res[top-1])) 
			top--;
		res[++top] = pnt[i];
	}
	return top; // 返回凸包中点的个数
}
/*==================================================*\
| 判断线段相交
\*==================================================*/
const double eps=1e-10;
struct point { double x, y; };
double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }
bool inter(point a, point b, point c, point d){
	if ( min(a.x, b.x) > max(c.x, d.x) ||
		min(a.y, b.y) > max(c.y, d.y) ||
		min(c.x, d.x) > max(a.x, b.x) ||
		min(c.y, d.y) > max(a.y, b.y) ) return 0;
	double h, i, j, k;
	h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
	j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
	k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
	return h * i <= eps && j * k <= eps;
}

/*==================================================*\
| 求多边形重心
| INIT: pnt[]已按顺时针(或逆时针)排好序;
| CALL: res = bcenter(pnt, n);
\*==================================================*/
struct point { double x, y; };
point bcenter(point pnt[], int n){
	point p, s;
	double tp, area = 0, tpx = 0, tpy = 0;
	p.x = pnt[0].x; p.y = pnt[0].y;
	for (int i = 1; i <= n; ++i) { // point: 0 ~ n-1
		s.x = pnt[(i == n) ? 0 : i].x;
		s.y = pnt[(i == n) ? 0 : i].y;
		tp = (p.x * s.y - s.x * p.y); area += tp / 2;
		tpx += (p.x + s.x) * tp; tpy += (p.y + s.y) * tp;
		p.x = s.x; p.y = s.y;
	}
	s.x = tpx / (6 * area); s.y = tpy / (6 * area);
	return s;
}

/*==================================================*\
| 求a,b,c构成三角形面积
\*==================================================*/
double getTriangleArea(double a, double b, double c){
	double p = (a + b + c) / 2;	
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

/*==================================================*\
| 判断线段与直线是否相交
| p1,p2 线段的两个端点 p3,p4 直线上的两个点
| 返回值 0 不相交 1 相交
\*==================================================*/
struct Point{ double x,y; };
int lineintersect(Point p1,Point p2,Point p3,Point p4){
    Point tp1,tp2,tp3;
    tp1.x=p1.x-p3.x;
    tp1.y=p1.y-p3.y;
    tp2.x=p4.x-p3.x;
    tp2.y=p4.y-p3.y;
    tp3.x=p2.x-p3.x;
    tp3.y=p2.y-p3.y;
    if ((tp1.x*tp2.y-tp1.y*tp2.x)*(tp2.x*tp3.y-tp2.y*tp3.x)>=0) 
    	return 1; else return 0;
}

