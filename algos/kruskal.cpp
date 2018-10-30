#include<bits/stdc++.h>
using namespace std;
int parent[50];
int rank[50];
struct edge{
	int src;
	int dest;
	int wt;
};
void makeset(int i)
{
	parent[i]=i;
	rank[i]=0;

}
int find(int x)
{
	if(parent[x]==x)
	{
		return x;
	}
	return(parent[x]);
}
void unions(int x,int y)
{
	if(find(x)==find(y))
	{
		return;
	}
	int px=find(x);
	int py=find(y);

	if(rank[px]>rank[py])
	{
		parent[py]=px;
	}
	else if(rank[px]<rank[py])
	{
		parent[px]=py;
	}
	else{
		parent[px]=py;
		rank[py]+=1;
	}
}
bool cmp(edge e1,edge e2)
{
	return e1.wt<e2.wt;
}
void kruskal(edge arr[],int v,int e)
{
  edge mst[v-1];
  int k=0;
  for(int i=0;i<e;i++)
  {
  	if(find(arr[i].src)!=find(arr[i].dest))
  	{
  	  mst[k]=arr[i];
	  k++;
	  unions(arr[i].src,arr[i].dest);
	}
  }
  for(int i=0;i<k;i++)
  {
  	cout<<mst[i].src<<" "<<mst[i].dest<<" "<<mst[i].wt<<endl;
  }
}
int main()
{
 int v,e;
 cin>>v;
 cin>>e;
 edge arr[e];
 for(int i=0;i<e;i++)
 {
   cin>>arr[i].src>>arr[i].dest>>arr[i].wt;
   makeset(arr[i].src);
   makeset(arr[i].dest);
 }
 sort(arr,arr+e,cmp);
 kruskal(arr,v,e);
 return 0;
}
