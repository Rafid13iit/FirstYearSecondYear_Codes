#include <header.h>
#include <globalVariable.h>

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct Node {
    int x, y;
    int g, h;

    //a constructor which is used to initialize the variables
    Node(int _x, int _y, int _g, int _h) : x(_x), y(_y), g(_g), h(_h) {}

    
    //overloaded operator <  is used to order the elements in the priority queue
    /*The overloaded operator < compares the f-value (g+h) of two nodes, 
    where a node with a lower f-value is considered to have higher priority. */
    bool operator<(const Node &other) const {
        return g + h > other.g + other.h;
    }
    /*The function "return g + h > other.g + other.h" returns true if 
    the f-value of the current node is greater than the f-value of the other node. */
};

int Astar(int sx, int sy, int ex, int ey, int width, int height) {
    priority_queue<Node> q;
    unordered_map<int, unordered_map<int, bool>> visited;
    /*The priority queue is used to store the nodes to be visited and 
    the unordered_map is used to store the nodes that have already been visited.*/

    q.push(Node(sx, sy, 0, abs(sx - ex) + abs(sy - ey)));

    while (!q.empty()) {
        Node curr = q.top();
        q.pop();

        if (curr.x == ex && curr.y == ey) {
            return curr.g;
        }

        if (visited[curr.x][curr.y]) {
            continue;
        }

        visited[curr.x][curr.y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                continue;
            }
            if (visited[nx][ny]) {
                continue;
            }

            q.push(Node(nx, ny, curr.g + 1, abs(nx - ex) + abs(ny - ey)));
        }
    }
    return -1;
}

void A_star_algorithm() {

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    outtextxy(400, 30, "A* Algorithm");

    Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    int sx, sy, ex, ey;
    int width, height;

    cin >> sx >> sy >> ex >> ey >> width >> height;

    int distance = Astar(sx, sy, ex, ey, width, height);
    cout << distance << endl;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");


    prevWindowArrow();

    int x = mousex();
    int y = mousey();
    if (ismouseclick(WM_LBUTTONDOWN)) {
        clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event
        if (x > 50 && x < 110 && y > 50 && y < 90) {
            // button was clicked
            cleardevice();
            delay(100);
            //getch();
            showList();
            //break;
        }
    } 

}
