//
//  main.cpp
//  ��������
//
//  Created by ������ on 2018/10/20.
//  Copyright  2018�� ������. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,x[100],y[100],z[100],num[100][100];          //�������飬��¼����
    float l[100],p=0;                 //��������
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    int k=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            l[k]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
            num[i][j]=k;
            k++;
        }
    }
    float a[100];                     //��������
    for (int i=1;i<k;i++)             //��������
    {
        a[i]=l[i];
    }
    for (int i=1;i<k-1;k++)           //ð������
    {
        for (int j=1;j<=k-1-i;j++)
        {
            if (a[i]<a[i+1])
            {
                p=a[i];
                a[i]=a[i+1];
                a[i+1]=p;
            }
        }
    }
    for (int i=1;i<k;i++)
    {
        if (a[i]==a[i-1])
            continue;
        for (int j=1;j<k;j++)
        {
            if (l[j]==a[i])
            {
                for (int p=1;i<=n;i++)
                {
                    for (int q=i+1;j<=n;j++)
                    {
                        if (num[p][q]==j)
                            printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n",x[p],y[p],z[p],x[q],y[q],z[q],l[j]);
                    }
                }
            }
        }
    }
    return 0;
}

