#include <iostream>
#include <string>
#include <vector>

template<typename T>
void Process(const T& form) {
    std::cout<<form.GetForm().first<<","<<form.GetForm().second<<"\n";
}
class Shape {
protected:
    std::pair<int, int> form;
public:
    Shape(int h, int w): form(h,w){}
    std::pair<int, int> GetForm() const {
        return form;
    }
    virtual std::string rectangle() const=0;
    virtual ~Shape(){}
};

class Quadrangle: public Shape {
public:
    Quadrangle(int h, int w): Shape(h, w){}
    std::string rectangle() const override{
        return "4";
    }
};

int main() {
    std::vector<Shape*> figure;
    figure.push_back(new Quadrangle(10,20));
    Process(*figure[0]);
    for(Shape* shape: figure) {
        delete shape;
    }
}