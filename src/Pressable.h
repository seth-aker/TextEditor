#ifndef PRESSABLE_H
#define PRESSABLE_H

#include "Typedefs.h"
#include "Intersects.h"
#include <functional>
/* Wrapper class to make an object pressable.
*/
template <typename T>
class Pressable {
private:
    T m_pressableObj;
    Coordinates m_objCoordinates;
    Dimensions m_objDimensions;
    std::function<void()> m_onPress;

public:
    Pressable(T pressableObj, Coordinates objCoord, Dimensions objDim, std::function<void()> onPress)
        : m_pressableObj{ pressableObj },
        m_objCoordinates{ objCoord },
        m_objDimensions{ objDim },
        m_onPress{ onPress }
    {};


    void setOnPress(std::function<void()> onPress) {
        m_onPress = onPress;
    }

    void onPress() {
        m_onPress();
    }

    T* operator->() {
        return m_pressableObj;
    }
    // Returns true if mouse is pressed and intersects with the pressable obj.
    const bool isPressed(Coordinates& mousePos, bool mousePressed) const {
        return (mousePressed &&
            intersects(mousePos.first, mousePos.second, // mouse location
                m_objCoordinates.first, m_objCoordinates.second, // object location
                m_objDimensions.first, m_objDimensions.second));    // object dimensions
    }

    void setCoordinates(Coordinates coord) {
        m_objCoordinates = coord;
    }

    const Coordinates& getCoordinates() const {
        return m_objCoordinates;
    }
    void setDimensions(Dimensions dim) {
        m_objDimensions = dim;
    }

    const Dimensions& getDimensions() const {
        return m_objDimensions;
    }


};




#endif
