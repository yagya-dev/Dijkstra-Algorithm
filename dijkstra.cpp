 #include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define TEMP 0
#define PERM 1
#define NIL -1
#define INF 10000
void create_graph();
void findpath(int ,int);
int min_temp();
void dijkstra(int);
int n;
int adjacency[MAX][MAX];
int predecessor[MAX];
int status[MAX],i;
int pathlength[MAX];
int main()
{
int s,v;
create_graph();
cout<<"ENTER ANY SOURCE VERTEX"<<"  ";cin>>s;
dijkstra(s);
while(1)
{
cout<<"ENTER ANY DESTINATION VERTEX(-1 to QUIT)"<<endl;
cin>>v;
if(v==-1)
break;
else if(v>=n||v<0)
cout<<"INVALID CHOICE"<<endl;
else if(s==v)
cout<<"SOURCE AND DESTINATION ARE SAME"<<endl;
else if(pathlength[v]==INF)
cout<<"THERE IS NO PATH FOR DESTINATION"<<endl;
else
findpath(s,v);


}
}
void findpath(int s,int v)
{
int distance=0,u,z=v,counts=0,arr[n];
while(v!=s)
{
counts++;
arr[counts]=v;
u=predecessor[v];
distance+=adjacency[u][v];
v=u;
}counts++;
arr[counts]=s;
cout<<"PATH FROM"<<" "<<s<<"TO"<<" "<<z<<"IS"<<endl;
for(i=counts;i>0;i--)
cout<<arr[i]<<"->";
cout<<endl<<"SHORTEST DISTANCE IS"<<" "<<distance;
}


void create_graph()
{int max_edges,origin,destination,j,weight;
cout<<"ENTER THE TOTAL NO OF VERTICES"<<"  ";
cin>>n;
for(i=0;i<n;i++)for(j=0;j<n;j++)adjacency[i][j]=0;
max_edges=n*(n-1);
for(i=0;i<max_edges;i++)
{cout<<"ENTER EDGE NO .. "<<i+1<<" FIRSTLY SOURCE VETEX THEN DESTINATION  -1 -1 to QUIT"<<endl;
cin>>origin>>destination;
if(origin==-1||destination==-1)
break;
cout<<"ENTER THE WEIGHT OF THAT WEIGHT"<<endl;
cin>>weight;
if(origin>=n||destination>=n)
{cout<<"INVALID EDGE"<<endl;i--;}
else
adjacency[origin][destination]=weight;
}
}
void dijkstra(int s)
{int current;
for(i=0;i<n;i++)
{
status[i]=TEMP;predecessor[i]=NIL;pathlength[i]=INF;
}
pathlength[s]=0;
while(1)
{
current=min_temp();
if(current==NIL)return;
status[current]=PERM;
for(i=0;i<n;i++)
{
if(adjacency[current][i]!=0&&status[i]==TEMP)
{
if(pathlength[current]+adjacency[current][i]<pathlength[i])
{pathlength[i]=pathlength[current]+adjacency[current][i];predecessor[i]=current;}
}
}

}


}
int min_temp()
{
int k=NIL,mini=INF;
for(i=0;i<n;i++)
{
if(status[i]==TEMP&&pathlength[i]<mini){mini=pathlength[i];k=i;}
}
return k;
}
