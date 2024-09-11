#include <iostream>
#include "ColorPair.h"


namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };
    int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    std::list<ColorPair> PrintColorPair()
    {
        std::list<ColorPair> colorPairList;
        for (int i = 1; i <= numberOfMinorColors * numberOfMajorColors; i++)
        {
            ColorPair colorPair = GetColorFromPairNumber(i);
            colorPairList.push_back(colorPair);
            std::cout << i << " - " << colorPair.ToString() << std::endl;
        }
        return colorPairList;
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    std::string ColorPair::ToString() {
        std::string colorPairStr = MajorColorNames[m_majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[m_minorColor];
        return colorPairStr;
    }
}