#include <graphics.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void visualize() {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");

        int radius = 20;
        int x_center = 50, y_center = 50;
        int x_spacing = 100, y_spacing = 100;

        // Draw vertices
        for (int v = 0; v < V; v++) {
            int x = x_center + (v % 2) * x_spacing;
            int y = y_center + (v / 2) * y_spacing;
            circle(x, y, radius);
            stringstream ss;
            ss << v;
            string str = ss.str();
            //outtextxy(x - 5, y - 5, str.data());
        }

        // Draw edges
        for (int v = 0; v < V; v++) {
            for (int i = 0; i < adj[v].size(); i++) {
                int w = adj[v][i];
                int x1 = x_center + (v % 2) * x_spacing;
                int y1 = y_center + (v / 2) * y_spacing;
                int x2 = x_center + (w % 2) * x_spacing;
                int y2 = y_center + (w / 2) * y_spacing;
                line(x1, y1, x2, y2);
            }
        }
        delay(1000);
        getch();
        closegraph();
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.visualize();
    return 0;
}
