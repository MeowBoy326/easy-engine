#include <Core/h/Color.h>

namespace easy::core {

    const Color Palette::RED(255, 0, 0);
    const Color Palette::GREEN(0, 255, 0);
    const Color Palette::BLUE(0, 0, 255);

    Color::Color(uint8_t r, uint8_t g, uint8_t b, float a)
    {
        SetRed(r);
        SetGreen(g);
        SetBlue(b);
        SetAlpha(a);
    }

    void Color::SetRed(uint8_t value)
    {
        r_ = To1(value);
    }

    void Color::SetGreen(uint8_t value)
    {
        g_ = To1(value);
    }

    void Color::SetBlue(uint8_t value)
    {
        b_ = To1(value);
    }

    void Color::SetAlpha(float value)
    {
        if (value > 1) a_ = 1;
        else if (value < 0) a_ = 0;
        else a_ = value;
    }

    uint8_t Color::GetRed()
    {
        return To255(r_);
    }

    uint8_t Color::GetGreen()
    {
        return To255(g_);
    }

    uint8_t Color::GetBlue()
    {
        return To255(b_);
    }

    float Color::GetAlpha()
    {
        return a_;
    }

    float Color::To1(uint8_t value)
    {
        return value / 255.f;
    }

    uint8_t Color::To255(float value)
    {
        return (uint8_t)(value * 255);
    }
}
