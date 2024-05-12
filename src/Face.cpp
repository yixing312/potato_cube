#include <HeadFile.hpp>
#include <Handware.hpp>
#include <Face.hpp>

void print_face(int face)
{
    Handware::tft.setTextWrap(false);
    // Handware::tft.fillScreen(ST77XX_BLACK);
    Handware::tft.setCursor(0, 0);
    Handware::tft.setTextColor(ST77XX_WHITE);
    Handware::tft.setTextSize(1);

    if (face >= 0 && face < 5)
        Handware::tft.setTextSize(2);
    else if (face >= 5 && face < 8)
    {
        Handware::tft.setTextSize(4);
        Handware::tft.setCursor(0, 35);
    }

    Handware::tft.println(faces[face]);
}

void display_face(int face)
{
    Handware::tft.setTextWrap(false);
    // Handware::tft.fillScreen(ST77XX_BLACK);
    Handware::tft.setCursor(0, 0);
    Handware::tft.setTextColor(ST77XX_BLACK);
    Handware::tft.setTextSize(1);

    if (face >= 0 && face < 5)
        Handware::tft.setTextSize(2);
    else if (face >= 5 && face < 7)
    {
        Handware::tft.setTextSize(4);
        Handware::tft.setCursor(0, 35);
    }

    Handware::tft.println(faces[face]);
}