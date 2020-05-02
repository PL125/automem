#ifndef VIEW_H
#define VIEW_H

#include "../utils/stack.h"

class View {
    public:
        virtual void render();
        virtual void actions(Stack<View> *views);
};

#endif