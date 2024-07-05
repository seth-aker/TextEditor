#ifndef UTILITY_INTERSECTS_H
#define UTILITY_INTERSECTS_H
/**
 * Returns true if the mouse position intersects the object in question's position.
 */
template <typename T>
bool intersects(const T mouseX, const T mouseY, const T objX, const T objY, const T objW, const T objH)
{
    // If any of the below expressions result in true, then the expression should evaluate to false. All of the expressions need to evaluate to false in order for the return to be true.
    return !(mouseX < objX ||       // If mouse is left of the object
        mouseX > objX + objW || // If mouse is right of the object
        mouseY < objY ||        // If mouse is above the object
        mouseY > objY + objH);  // If mouse is below the object
}

#endif
