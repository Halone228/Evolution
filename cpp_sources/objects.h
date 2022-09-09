#include <iostream>
#include <vector>
#include <cstdlib>
#include <basicObjects.h>

class DiedCell : public Cell{
    public:
        DiedCell(float weight,Position pos) : Cell(weight,pos){};
        void strategy(){}
};
class PhotosCell : public Cell{
    public:
        PhotosCell(float weight,Position pos) : Cell(weight,pos){};
        void strategy(){
            weight += rand()%100 / ((rand() % 101) + 50);
        }
};