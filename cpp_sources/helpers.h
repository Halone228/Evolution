#include <vector>

class Position {
    public:
        int x,y;
        Position(int x, int y){ this->x = x; this->y = y;}
        Position(std::vector<int> pos) {x,y = pos[0],pos[1];}
        Position(int* pos) {x,y = pos[0],pos[1];}
        Position(){x,y=0;}
};