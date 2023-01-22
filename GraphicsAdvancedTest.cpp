#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int x, y;
    char label[10];
};

struct Edge {
    struct Node* from;
    struct Node* to;
    char weight[10];
};

void drawNode(struct Node* n) {
    int x = n->x;
    int y = n->y;
    char* label = n->label;
    int radius = 20;

    setcolor(WHITE);
    circle(x, y, radius);
    outtextxy(x - (radius / 2), y - (radius / 2), label);
}

void drawEdge(struct Edge* e) {
    int x1 = e->from->x;
    int y1 = e->from->y;
    int x2 = e->to->x;
    int y2 = e->to->y;
    char* weight = e->weight;

    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    outtextxy((x1 + x2) / 2, (y1 + y2) / 2, weight);
}

void drawGraph(struct Node** nodes, int numNodes, struct Edge** edges, int numEdges) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for (int i = 0; i < numNodes; i++) {
        drawNode(nodes[i]);
    }

    for (int i = 0; i < numEdges; i++) {
        drawEdge(edges[i]);
    }

    getch();
    closegraph();
}

int main() {
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->x = 100;
    node1->y = 200;
    strcpy(node1->label, "A");

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->x = 300;
    node2->y = 200;
    strcpy(node2->label, "B");

    struct Node* nodes[] = {node1, node2};
    int numNodes = sizeof(nodes) / sizeof(nodes[0]);

    struct Edge* edge1 = (struct Edge*)malloc(sizeof(struct Edge));
    edge1->from = node1;
    edge1->to = node2;
    strcpy(edge1->weight, "5");

    struct Edge* edges[] = {edge1};
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    drawGraph(nodes, numNodes, edges, numEdges);

    return 0;
}
