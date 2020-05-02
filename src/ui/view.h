#ifndef VIEW_H
#define VIEW_H

#include "../utils/stack.h"

class View {
    public:
        virtual void render();
        virtual void action(Stack<View> *views);
};

#endif