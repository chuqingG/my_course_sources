//最高分唯一
//float型精确到0.1
#include<stdio.h>
#include<math.h>
#define N 3
#define M 5
void f_a_s(float g[N][M],float a_s[N])
{
    int i,j;
    float s_s[N]={0};
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            s_s[i]+=g[i][j];
    for(i=0;i<N;i++)
        a_s[i]=s_s[i]/M;
}

void f_a_c(float g[N][M],float a_c[M])
{
    int i,j;
    float s_c[M]={0};
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            s_c[j]+=g[i][j];
    for(j=0;j<M;j++)
        a_c[j]=s_c[j]/N;
}

float f_m(float g[N][M])
{
    float m=0;
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            m=m>g[i][j]?m:g[i][j];
    return m;
}

int f_m_s(float m,float g[N][M])
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            if(fabs(g[i][j]-m)<0.01)
                return i;
}

int f_m_c(float m,float g[N][M])
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            if(fabs(g[i][j]-m)<0.01)
                return j;
}

float f_v_s(float a_s[N])
{
    int i;
    float v_s,s1=0,s2=0;
    for(i=0;i<N;i++)
    {
        s1+=a_s[i];
        s2+=pow(a_s[i],2);
    }
    v_s=s2/N-pow(s1/N,2);
    return v_s;
}

void main()
{
    float g[N][M];
    float a_s[N];
    float a_c[M];
    float m,v_s;
    int i,j,s,c;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            scanf("%f",&g[i][j]);



    f_a_s(g,a_s);
    f_a_c(g,a_c);
    m=f_m(g);
    s=f_m_s(m,g);
    c=f_m_c(m,g);
    v_s=f_v_s(a_s);
    for(i=0;i<N;i++)
        printf("%.1f\t",a_s[i]);
    printf("\n");
    for(j=0;j<M;j++)
        printf("%.1f\t",a_c[j]);
    printf("\nm=%.1f\ts=%d\tc=%d\nv_s=%.1f",m,s,c,v_s);

}
