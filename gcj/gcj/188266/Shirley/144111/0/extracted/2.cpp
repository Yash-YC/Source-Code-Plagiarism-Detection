// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<queue>
using namespace std;

int n,m;

struct aNode{
	int i;
	int j;
	int p;
	int cost;
	bool operator<(const aNode p)const
	{
		return cost>p.cost;    
	}
};

void XYZ(){
    #ifndef  ONLINE_JUDGE
    freopen("B-small-attempt0.in","r",stdin);
    #endif
}

bool check(int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=m)
		return false;
	return true;
}

int goNorth(int s,int w,int t,int now)
{
	int r;
	int sum = s+w;
	r = (now - t) % sum;
	if(r<0)
		r += sum;
	if(r<s)
		return now + 1;
	return now - r + sum + 1;
}

int goEast(int s,int w,int t,int now)
{
	int r;
	int sum = s + w;
	r = (now - t) % sum;
	if(r<0)
		r += sum;
	if(r>=s)
		return now + 1;
	return now - r + s + 1;
	
}

int main(int argc, char* argv[])
{
	XYZ();

	FILE * cfPtr;
	cfPtr = fopen("out.txt","w");
	int test,k;
	int i,j,h;
	aNode node;
	aNode front,next;
	
	int s[25][25];
	int w[25][25];
	int t[25][25];
	bool flag[25][25][4];
	scanf("%d",&test);
	for(k=1;k<=test;k++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				for(h=0;h<4;h++)
					flag[i][j][h] = false;
		priority_queue <aNode> q;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d%d%d",&s[i][j],&w[i][j],&t[i][j]);
			}
		node.i = n-1;
		node.j = 0;
		node.p = 0;
		node.cost = 0;
		q.push(node);
		while(true)
		{
			front = q.top();
			q.pop();
			flag[front.i][front.j][front.p] = true;
			if(front.i == 0 && front.j == m-1 && front.p == 2)
			{
				fprintf(cfPtr,"Case #%d: %d\n",k,front.cost);
				break;
			}
			if(front.p == 0)
			{
				next.i = front.i;
				next.j = front.j-1;
				next.p = 3;
				next.cost = front.cost+2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i + 1;
				next.j = front.j ;
				next.p = 1;
				next.cost = front.cost + 2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i;
				next.j = front.j;
				next.p = 1;
				next.cost = goNorth(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i;
				next.j = front.j;
				next.p = 3;
				next.cost = goEast(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
			}
			else if(front.p == 1)
			{
				next.i = front.i - 1;
				next.j = front.j;
				next.p = 0;
				next.cost = front.cost + 2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i;
				next.j = front.j - 1;
				next.p = 2;
				next.cost = front.cost + 2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i;
				next.j = front.j;
				next.p = 2;
				next.cost = goEast(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.p = 0;
				next.cost = goNorth(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
			}
			else if(front.p == 2)
			{
				next.i = front.i;
				next.j = front.j + 1;
				next.p = 1;
				next.cost = front.cost + 2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i - 1;
				next.j = front.j;
				next.p = 3;
				next.cost = front.cost + 2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i;
				next.j = front.j;
				next.p = 1;
				next.cost = goEast(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.p = 3;
				next.cost = goNorth(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
			}
			else
			{
				next.i = front.i + 1;
				next.j = front.j;
				next.p = 2;
				next.cost = front.cost + 2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i;
				next.j = front.j + 1;
				next.p = 0;
				next.cost = front.cost + 2;
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.i = front.i;
				next.j = front.j;
				next.p = 2;
				next.cost = goNorth(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
				next.p = 0;
				next.cost = goEast(s[front.i][front.j],w[front.i][front.j],t[front.i][front.j],front.cost);
				if(check(next.i,next.j) && !flag[next.i][next.j][next.p])
					q.push(next);
			}
		}

	}

	return 0;
}
