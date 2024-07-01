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
    Coordinates objCoordinates;
    Dimensions dimensions;
    std::function<void()> m_onPress;

public:
    Pressable() {
        m_pressableObj{};

        m_onPress = NULL;
    };
    Pressable(T pressableObj)
        : m_pressableObj{ pressableObj }
    {
        m_onPress = NULL:
    }
    Pressable(T pressableObj, std::function<void()> onPress)
        : m_pressableObj{ pressableObj },

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
    bool isPressed(Coordinates& mousePos, bool mousePressed) {
        if (intersects(mousePos.first, mousePos.second)
    }

};




#endif
