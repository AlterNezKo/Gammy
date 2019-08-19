#ifdef __linux__
#ifndef X11_H
#define X11_H

#include <X11/Xlib.h>
#undef None //Needed to avoid build error with qurl.h
#include <cstdint>

class X11
{
    Display* img_dsp;
    Display* gamma_dsp; //Need to use two diffent displays to avoid XIO fatal error
    Screen* scr;
    Window root;

    int ramp_sz;
    int scr_num;
    uint16_t* init_ramp;

    unsigned w, h;

public:
    X11();

    unsigned getWidth();
    unsigned getHeight();

    void getX11Snapshot(uint8_t* buf);
    void fillRamp(uint16_t*& ramp, int amount, int temp);
    void setXF86Brightness(uint16_t scrBr, int temp);
    void setInitialGamma(bool set_previous);

    ~X11();
};

extern X11 x11;

#endif // X11_H
#endif