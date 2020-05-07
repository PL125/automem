#ifndef VIEW_H
#define VIEW_H

#include "symbols.h"
#include "math.h"

#include "lib/stack.h"

class View {
    public:
        virtual ~View() {}

        virtual void render() const = 0;
        virtual void action(Stack<View> *views) const = 0;
};

#endif