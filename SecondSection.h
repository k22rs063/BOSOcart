#ifndef SECONDSECTION_H
#define SECONDSECTION_H
#include "Scene.h"

class SecondSection : public Scene{
    public:
    explicit SecondSection();
    virtual ~SecondSection();

    void execute();
    bool isFinished();

    private:
    int state;
    bool flag=false;

};

#endif