#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Graph
{
    private:
        int V;     // πλήθος των κορυφών του γραφήματος
        int*data; // πίνακας γειτνίασης
        int*periotoi;
    public:
        Graph(int v) : V(v)
            {
                data = new int[v * v];
                for (int i = 0; i < v * v; i++)
                {
                    data[i] = 0;
                }
                periotoi = new int[V];
            }
        ~Graph(){  
            }
        int* greedyColoring()
        {
            // Assign the first color to first vertex
            periotoi[0] = 0;
            // Initialize remaining V-1 vertices as unassigned
            for (int u = 1; u < V; u++)
                periotoi[u] = -1; // no color is assigned to u
            // A temporary array to store the available colors. True
            // value of available[cr] would mean that the color cr is
            // assigned to one of its adjacent vertices
            bool available[V];
            for (int cr = 0; cr < V; cr++)
                available[cr] = true;
            // Assign colors to remaining V-1 vertices
            for (int u = 0; u < V; u++)
            {
                // Process all adjacent vertices and flag their colors
                // as unavailable
                int col; 
                for(col=0;col<V;col++)
                {
                    if(data[u*V+col]!=0)
                            if(periotoi[col]!=-1)
                            {
                                available[periotoi[col]] = false;
                            }
                }
                int cr;
                for (cr = 0; cr < V; cr++)
                    if (available[cr]) break;
                periotoi[u] = cr; // Assign the found color
                // Reset the values back to true for the next iteration
                for (col=0;col<V;col++)
                    if (periotoi[col] != -1)
                        {
                        available[periotoi[col]] = true;
                        }
            }
            set<int>numCol;
            for (int u = 0; u < V; u++) numCol.insert(periotoi[u]);
            cout<<endl<<"Number of Colors/periods = "<<numCol.size()<<endl;
            return periotoi;
    }
    void writeSolToFile(int*sol, string name)
        {
            ofstream  myfile("../datasets/"+name+".msol");
            if(myfile.is_open())
            {
                for(int i=0;i<V;i++){
                    myfile<<i+1<<" "<<sol[i]<<endl;
                }
            }
            cout<<endl<<"solution's file : ../datasets/"<<name<<".msol"<<endl;
            myfile.close();
        }
    int get_V(){return V;}
    void insert_edge(int i, int j, int value)
        {
            V=get_V();
            data[i * V + j] = value;
        }
    int get_edge_value(int i, int j)
        {
            return data[i * V + j];
        }
        // επιστρέφει ένα set από ακεραίους που είναι
        // οι αριθμοί κορυφών με τους οποίους συνδέεται απευθείας η κορυφή v
    set<int> get_neighbors(int v)
        { 
            set<int> neighbors;
            for (int j = 0; j < V; j++)
            {
                if (get_edge_value(v, j) > 0)
                    neighbors.insert(j);
            }
            return neighbors;
        }
};
bool check_coloring(Graph g, int *solution)
    {
        bool proper_coloring = true;
        for (int v = 0; v < g.get_V(); v++)
            {
                int color_v = solution[v];
                set<int> neighbors_of_v = g.get_neighbors(v);
                for (int v2 : neighbors_of_v)
                {   
                    if (v!=v2){
                        int color_v2 = solution[v2];
                        if (color_v == color_v2)
                        {
                            cout<<v<<" "<<v2<<endl;
                            proper_coloring = false;
                            goto jump;
                        }
                    }
                }
            }
        jump:
            return proper_coloring;
    }

void loadProblem(Graph g,int *adj_matrix,int V)
    {
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if (adj_matrix[i*V+j] >= 0){
                    g.insert_edge(i,j, adj_matrix[i*V+j]);
                }
            }
        }
    }
