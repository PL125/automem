#ifndef VIEW_H
#define VIEW_H

#include <LinkedList.h>

#include "symbols.h"
#include "math.h"

class View {
    public:
        virtual ~View() {}

        virtual void setup() const = 0;
        virtual void draw() const = 0;
        virtual void update() const = 0;
};

#endif