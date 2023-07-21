#pragma once

#include <Core_api.h>

#include <cstdint>

namespace easy::core {

    class CORE_EXPORT Color {
    public:
        Color() = default;
        Color(const Color&) = default;
        Color(Color&&) = default;
        Color(uint8_t r, uint8_t g, uint8_t b, float a = 1);

        Color& operator=(const Color&) = default;
        Color& operator=(Color&&) = default;

        void SetRed(uint8_t value);
        void SetGreen(uint8_t value);
        void SetBlue(uint8_t value);
        void SetAlpha(float value);

        uint8_t GetRed();
        uint8_t GetGreen();
        uint8_t GetBlue();
        float GetAlpha();

        static float To1(uint8_t value);
        static uint8_t To255(float value);

    private:
        float r_ = 1;
        float g_ = 1;
        float b_ = 1;
        float a_ = 1;
    };
    
    struct CORE_EXPORT Palette {
        static const Color RED;
        static const Color GREEN;
        static const Color BLUE;
    };
}
