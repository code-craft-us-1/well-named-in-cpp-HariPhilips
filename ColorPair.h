#pragma once
#include <string>
#include <list>

namespace TelCoColorCoder
{
    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    class ColorPair
    {
        MajorColor m_majorColor;
        MinorColor m_minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor) : m_majorColor(major), m_minorColor(minor) {}

        MajorColor getMajor() { return m_majorColor; };
        MinorColor getMinor() { return m_minorColor; };
        std::string ToString();
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    std::list<ColorPair> PrintColorPair();
}