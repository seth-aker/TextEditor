#ifndef UTILITY_INTERSECTS_H
#define UTILITY_INTERSECTS_H
template <typename T>
bool intersects(T mouseX, T mouseY, T objX, T objY, T objW, T objH)
{
    return !(mouseX < objX || mouseX > objX + objW || mouseY < objY || mouseY > objY + objH);
}

#endif
