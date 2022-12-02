#include<bits/stdc++.h>
using namespace std;

class edge{//EVERY EDGE HAS THESE 3 THINGS
public:
    int src;
    int dest;
    int weight;
};
bool compare(edge e1,edge e2)//SORT ACCORDING TO WEIGHT
{
    return e1.weight<e2.weight;
}

int getparent(int v,int* parent)//RECURSIVE FIND THE PARENT OF A VERTEX
{
    if(parent[v]==v)//STOP WHEN ANY VERTEX HAS SAME VERTEX AS PARENT MEANS THAT'S THE ROOT
    {
        return v;
    }
    return getparent(parent[v],parent);
}
edge* kruskals(edge* edges,int n ,int e)//RETURNS THE OUTPUT ARRAY OF EDGE TYPE ...WITH NO CYCLES AND MINIMUM SPANNING TREE EDGES 
{
    //sorted the edges array in increasing order
    sort(edges,edges+e,compare);

    edge* output=new edge[n-1];//Make OUTPUT ARRAY OF EDGE TYPE
    int* parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count<(n-1))//JABTAK EDGES N-1 NA HO JAI TA TAK KEEP ON SEARCHING
    {
        //check the topmost parent of v1 and v2.
        //v1 and v2  are vertices of current edge

        edge currentedge=edges[i];//EDGE VARIABLE HOLDING EDGE
        int srcparent=getparent(currentedge.src,parent);
        int destparent=getparent(currentedge.dest,parent);

        if(srcparent != destparent)
        {
            output[count]=currentedge;
            count+=1;
            parent[srcparent]=destparent;
        }
        i+=1;
    }
    return output;
}
int main()
{
    int n,e;
    cin>>n>>e;
    edge* edges=new edge[e];

    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].src=s;
        edges[i].dest=d;
        edges[i].weight=w;
    }
    edge* output=kruskals(edges,n,e);
    long int sum=0;
    for(int i=0;i<n-1;i++)
    {
       /* if(output[i].src<output[i].dest)//EDGE PRINTING AS SMALL LARGE WEIGHT
        {
            cout<<output[i].src<<" "<<output[i].dest<<" " <<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<< " "<<output[i].src<<" "<<output[i].weight<<endl;
        }
        sum+=output[i].weight;*/
        sum+=output[i].weight;
    }
    cout<<sum<<endl;
    return 0;
}
