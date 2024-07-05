#ifndef TEXT_EDIT_TYPEDEFS_H
#define TEXT_EDIT_TYPEDEFS_H
#include <utility>

/**
 * The location of the top right corner of an object.
 * \param first x coordinate
 * \param second y coordinate
 */
typedef std::pair<int, int> Coordinates;

/**
 * The dimensions of an object
 * \param first Object width
 * \param second Object height
 */
typedef std::pair<int, int> Dimensions;

#endif
