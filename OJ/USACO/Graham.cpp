/**
凸包问题 —— Graham扫描法：
    找出点集p[]中最下面的点（有多个时取最左边的），以该点为极点，求出其他所有点的极角，
显然，极角范围为 [0, 180)度，对这些点按极角的升序排序，也就是按极角的余切值降序排列，
先把极点和排序后的第一个点和第二个点入栈，再一次循环(i = 3 -> n-1)，若栈顶的两个点和
当前的点p[i]这三点连线的方向向顺时针方向偏转，则栈顶元素出栈，直到向逆时针方向偏转或者
栈内只有2个元素了，就把当前点p[i]入栈。
最后栈中的元素就是所要求的凸包上的点，这里指的是凸包的极点（直线上的非端点不是凸包的极点）
**/

struct point
{
    double x, y, dx, dy;

    point(): x(0), y(0), dx(0), dy(0){}
    void setDxDy(int x0, int y0)
    {
        dx = x - x0;
        dy = y - y0;
    }
    /* 设当前点为p，若向量<p,p1>到向量<p1,p2>的转角为逆时针，则返回true，
       若为顺时针或夹角为0，则返回false。
       这里用向量叉积来判断，向量叉积大于0则返回true.           */
    bool mult(point p1, point p2)
    {
        return (p1.x - x)*(p2.y - p1.y) > (p2.x - p1.x)*(p1.y - y);
    }
    // 余切值大的小，余切值相等时距离极点近的小
    bool operator < (const point &p) const
    {
        return ( dx*p.dy > dy*p.dx || (dx*p.dy == dy*p.dx && dy < p.dy) );
    }
};

/* 点集p[0...n-1]，找出凸包上的极点（直线上的非端点不是极点）
   保存在res[]中，函数返回凸包中点的数量             */
int graham(point p[], int n, point res[])
{
    // 先找到最下面的点（有多个时取左），并放在p[0]的位置
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if ( p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[i].y) )
            k = i;
    }
    if ( k > 0 )
    {
        point t = p[0];
        p[0] = p[k];
        p[k] = t;
    }
    // 求每个点相对于p[0]的dx,dy，用于算极角的余切值
    for (int i = 0; i < n; i++)
    {
        p[i].setDxDy(p[0].x, p[0].y);
    }
    // 按极角升序排列，实际为了方便按极角的余切值的降序排列
    sort(p+1, p+n);
    // 先把p[0,1,2]入栈
    if ( n == 0 ) return 0;
    res[0] = p[0];
    if ( n == 1 ) return 1;
    res[1] = p[1];
    if ( n == 2 ) return 2;
    res[2] = p[2];
    int top = 2;
    // 按顺序依次进行入栈和出栈的操作
    for (int i = 3; i < n; i++)
    {
        while ( top >= 1 && !res[top-1].mult(res[top], p[i]) )
            top--;
        res[++top] = p[i];
    }
    return top + 1;
}
