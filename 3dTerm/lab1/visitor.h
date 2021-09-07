#ifndef PATTERN_ITERATOR_VISITOR_VISITOR_H
#define PATTERN_ITERATOR_VISITOR_VISITOR_H
#include <iostream>
#include <string>

enum Directions{
    UP,
    DOWN,
    RIGHT,
    LEFT,
};

class Vector;
class Circle;
class Square;

class Visitor {
public:
    virtual void visit(Vector &ref) = 0;
    virtual void visit(Circle &ref) = 0;
    virtual void visit(Square &ref) = 0;

    virtual ~Visitor() = default;
};

class Figure {
public:
    int _x;
    int _y; //coords of the center
    int _h;  //lenght of vector, radius of circle and half a side for square

    virtual void accept(Visitor &v) = 0;

    virtual ~Figure() = default;
};

class Vector : public Figure {
public:
    int _direction;

    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Circle : public Figure {
public:
    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Square : public Figure {
public:
    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Move : public Visitor {
private:
    int _dx;
    int _dy;
public:
    Move(int dx, int dy){
        _dx = dx;
        _dy = dy;
    };

    void SetDx(int dx){_dx = dx;}
    void SetDy(int dy){_dx = dy;}

    void visit(Vector &ref) override {
        ref._x+=_dx;
        ref._y+=_dy;
    }
    void visit(Circle &ref) override {
        ref._x+=_dx;
        ref._y+=_dy;
    }
    void visit(Square &ref) override {
        ref._x+=_dx;
        ref._y+=_dy;
    }
};

class Scale : public Visitor {
private:
    int _delta;
public:
    Scale(int d){
        _delta = d;
    };

    void SetDelta(int d){_delta = d;}

    void visit(Vector &ref) override {
        ref._h*=_delta;
    }
    void visit(Circle &ref) override {
        ref._h*=_delta;
    }
    void visit(Square &ref) override {
        ref._h*=_delta;
    }
};

class MirrorOx : public Visitor {
public:
    void visit(Vector &ref) override {
        if(ref._direction == RIGHT){
            ref._direction = LEFT;
        }
        else{
            ref._direction = RIGHT;
        }
    }
    void visit(Circle &ref) override {}
    void visit(Square &ref) override {}
};

class MirrorOy : public Visitor {
public:
    void visit(Vector &ref) override {
        if(ref._direction == UP){
            ref._direction = DOWN;
        }
        else{
            ref._direction = UP;
        }
    }
    void visit(Circle &ref) override {}
    void visit(Square &ref) override {}
};
#endif
