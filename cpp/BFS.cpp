/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*


Lec 6 --> Graph
Single Source Shortest Path using BFS 
Page 19,20

*/




#include <iostream>

#include <map>
#include <queue>
#include <list>
#include <climits>

using namespace std;





template <typename T>
class Graph
{
  
  map <T, list<T> > l;
  
  public:
  
  void addEdge(T x, T y)
  {
      l[x].push_back(y);
      l[y].push_back(x);
      
  }
  
  void bfsUsingShortestPath(T source)
  {

      queue <T> q;

      
      map<T,int> dist;
      
      for(auto pair: l)
      {
          
          T node = pair.first;
          dist[node] = INT_MAX;
          
      }

      
      q.push(source);
      dist[source] = 0;
      
      
      while(!q.empty())
      {
          
          T node = q.front();
          q.pop();

          
          for(auto neigh: l[node])
          {
              if(dist[neigh] == INT_MAX)
              {
                  q.push(neigh);
                  dist[neigh] = dist[node] + 1;
              }
              
              
              
          }
      }

      for(auto x: l)
          {
              T node = x.first;
              int distance = dist[node];
              cout << "Node:  " << node << " is at a distance from source at:  " << distance << endl;
              
          }
      
      
  }

    
};



int main()
{
    
    Graph <int> G;
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,5);

    G.bfsUsingShortestPath(0);
    
    G.print();
    

    return 0;
}
