#include <random>
#include <helpers.h>
#include <vector>
#define MAX_WIDTH int 1000
#define MAX_HIEGHT int 750
// All cell types
enum CellType {
    empty=NULL,
    died=0,
    photos=1,
    violent=2
};
//Basic cell obj
class Cell {
    public:
        // cell type :: enum`CellType`(6)
        CellType type = CellType::empty;
        float weight = 0;
        // Стратегия клетки при итерация(её действия)
        virtual void strategy() = 0;
        Position pos;
        Cell(float weight, Position pos){
            this->weight = weight;
            this->pos = pos;
        }
        void feed(){
            weight -= rand()%5 / ((rand() % 101));   
        }
        void is_die(){
            if(weight<0){
                delete this;
            };
        }
        void iter(){
            feed();
            strategy();
            is_die();
        };
};
//Basic field object
class Field {
    public:
        // 2d matrix :: obj class`Cell`(12) 
        std::vector<std::vector<Cell>> field;
        Field(std::vector<std::vector<Cell>> _field){
            field = _field;
        }
        void iter(){
            for(std::vector<Cell> y : field){
                for(auto cell : y){
                    cell.iter();
                }
            }
        }
};