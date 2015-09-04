/**
͹������ ���� Grahamɨ�跨��
    �ҳ��㼯p[]��������ĵ㣨�ж��ʱȡ����ߵģ����Ըõ�Ϊ���㣬����������е�ļ��ǣ�
��Ȼ�����Ƿ�ΧΪ [0, 180)�ȣ�����Щ�㰴���ǵ���������Ҳ���ǰ����ǵ�����ֵ�������У�
�ȰѼ���������ĵ�һ����͵ڶ�������ջ����һ��ѭ��(i = 3 -> n-1)����ջ�����������
��ǰ�ĵ�p[i]���������ߵķ�����˳ʱ�뷽��ƫת����ջ��Ԫ�س�ջ��ֱ������ʱ�뷽��ƫת����
ջ��ֻ��2��Ԫ���ˣ��Ͱѵ�ǰ��p[i]��ջ��
���ջ�е�Ԫ�ؾ�����Ҫ���͹���ϵĵ㣬����ָ����͹���ļ��㣨ֱ���ϵķǶ˵㲻��͹���ļ��㣩
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
    /* �赱ǰ��Ϊp��������<p,p1>������<p1,p2>��ת��Ϊ��ʱ�룬�򷵻�true��
       ��Ϊ˳ʱ���н�Ϊ0���򷵻�false��
       ����������������жϣ������������0�򷵻�true.           */
    bool mult(point p1, point p2)
    {
        return (p1.x - x)*(p2.y - p1.y) > (p2.x - p1.x)*(p1.y - y);
    }
    // ����ֵ���С������ֵ���ʱ���뼫�����С
    bool operator < (const point &p) const
    {
        return ( dx*p.dy > dy*p.dx || (dx*p.dy == dy*p.dx && dy < p.dy) );
    }
};

/* �㼯p[0...n-1]���ҳ�͹���ϵļ��㣨ֱ���ϵķǶ˵㲻�Ǽ��㣩
   ������res[]�У���������͹���е������             */
int graham(point p[], int n, point res[])
{
    // ���ҵ�������ĵ㣨�ж��ʱȡ�󣩣�������p[0]��λ��
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
    // ��ÿ���������p[0]��dx,dy�������㼫�ǵ�����ֵ
    for (int i = 0; i < n; i++)
    {
        p[i].setDxDy(p[0].x, p[0].y);
    }
    // �������������У�ʵ��Ϊ�˷��㰴���ǵ�����ֵ�Ľ�������
    sort(p+1, p+n);
    // �Ȱ�p[0,1,2]��ջ
    if ( n == 0 ) return 0;
    res[0] = p[0];
    if ( n == 1 ) return 1;
    res[1] = p[1];
    if ( n == 2 ) return 2;
    res[2] = p[2];
    int top = 2;
    // ��˳�����ν�����ջ�ͳ�ջ�Ĳ���
    for (int i = 3; i < n; i++)
    {
        while ( top >= 1 && !res[top-1].mult(res[top], p[i]) )
            top--;
        res[++top] = p[i];
    }
    return top + 1;
}