#include "Coordinates.h"
#include <cassert>

Coordinates::Coordinates() {
}
Coordinates::Coordinates(int line, int column)
    : line(line), column(column) {
    assert(line >= 0);
    assert(column >= 0);
}

bool Coordinates::operator==(const Coordinates& c) const {
    return line == c.line && column == c.column;
}

bool Coordinates::operator!=(const Coordinates& c) const {
    return line != c.line || column != c.column;
}

bool Coordinates::operator>(const Coordinates& c) const {
    if (line != c.line) {
        return line > c.line;
    }
    return column > c.column;
}

bool Coordinates::operator<(const Coordinates& c) const {
    if (line != c.line) {
        return line < c.line;
    }
    return column < c.column;
}

bool Coordinates::operator>=(const Coordinates& c) const {
    if (line != c.line) {
        return line > c.line;
    }
    return column >= c.column;
}

bool Coordinates::operator<=(const Coordinates& c) const {
    if (line != c.line) {
        return line < c.line;
    }
    return column <= c.column;
}

