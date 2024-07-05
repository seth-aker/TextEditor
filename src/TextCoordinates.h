#ifndef TEXT_COORDINATES_H
#define TEXT_COORDINATES_H

struct TextCoordinates {
    int line = 0;
    int column = 0;

    TextCoordinates();
    TextCoordinates(int line, int col);
    bool operator== (const TextCoordinates& c) const;
    bool operator!= (const TextCoordinates& c) const;
    bool operator< (const TextCoordinates& c) const;
    bool operator> (const TextCoordinates& c) const;
    bool operator<= (const TextCoordinates& c) const;
    bool operator>= (const TextCoordinates& c) const;

};

#endif /* TEXT_COORDINATES_H */ 
