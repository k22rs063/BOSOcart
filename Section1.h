#ifndef SECTION1_H
#define SECTION1_H
#include "Scene.h"
#include "ev3api.h"

class Section1 : public Scene{
    public:
    explicit Section1();
    virtual ~Section1();

    void execute();
    bool isFinished();

    private:
    int state;
    bool flag=false;

};

#endif