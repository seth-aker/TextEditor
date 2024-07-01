#include "TextCoordinates.h"
#include <cassert>

TextCoordinates::TextCoordinates() {
}
TextCoordinates::TextCoordinates(int line, int column)
    : line(line), column(column) {
    assert(line >= 0);
    assert(column >= 0);
}

bool TextCoordinates::operator==(const TextCoordinates& c) const {
    return line == c.line && column == c.column;
}

bool TextCoordinates::operator!=(const TextCoordinates& c) const {
    return line != c.line || column != c.column;
}

bool TextCoordinates::operator>(const TextCoordinates& c) const {
    if (line != c.line) {
        return line > c.line;
    }
    return column > c.column;
}

bool TextCoordinates::operator<(const TextCoordinates& c) const {
    if (line != c.line) {
        return line < c.line;
    }
    return column < c.column;
}

bool TextCoordinates::operator>=(const TextCoordinates& c) const {
    if (line != c.line) {
        return line > c.line;
    }
    return column >= c.column;
}

bool TextCoordinates::operator<=(const TextCoordinates& c) const {
    if (line != c.line) {
        return line < c.line;
    }
    return column <= c.column;
}

