#ifndef SECTION1_H
#define SECTION1_H
#include "Scene.h"

class Section1 : public Scene{
    public:
    explicit Section1();
    virtual ~Section1();

    void exectue();
    bool isFinished();

    private:
    int state;

};

#endif