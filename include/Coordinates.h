#ifndef COORDINATES_H
#define COORDINATES_H

struct Coordinates {
    int line = 0;
    int column = 0;

    Coordinates();
    Coordinates(int line, int col);
    bool operator== (const Coordinates& c) const;
    bool operator!= (const Coordinates& c) const;
    bool operator< (const Coordinates& c) const;
    bool operator> (const Coordinates& c) const;
    bool operator<= (const Coordinates& c) const;
    bool operator>= (const Coordinates& c) const;

};

#endif /* COORDINATES_H */ 
