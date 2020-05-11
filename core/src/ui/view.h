#ifndef VIEW_H
#define VIEW_H

#include <LinkedList.h>

#include "symbols.h"
#include "math.h"

class View {
    public:
        virtual ~View() {}

        virtual void setup() = 0;
        virtual void render() = 0;
        virtual void action(LinkedList<View*> *views) = 0;
};

#endif