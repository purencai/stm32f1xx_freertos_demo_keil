/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter (ST) for emWin V5.32.                      *
*        Compiled Oct  8 2015, 11:58:22                              *
*                                                                    *
*        (c) 1998 - 2015 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: scan_again_128x64                                     *
* Dimensions:  128 * 64                                              *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include "bmp_scan_again.h"
#include <stdlib.h>

/*********************************************************************
*
*       Palette
*
*  Description
*    The following are the entries of the palette table.
*    The entries are stored as a 32-bit values of which 24 bits are
*    actually used according to the following bit mask: 0xBBGGRR
*
*    The lower   8 bits represent the Red   component.
*    The middle  8 bits represent the Green component.
*    The highest 8 bits represent the Blue  component.
*/
static GUI_CONST_STORAGE GUI_COLOR _Colorsscan_again_128x64[] = {
  0x000000, 0xFFFFFF
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palscan_again_128x64 = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsscan_again_128x64[0]
};

static GUI_CONST_STORAGE unsigned char _acscan_again_128x64[] = {
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXX__, ________, ________, ________, ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXX___, ________, ________, ________, ________, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXX___X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXX___XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, X___XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX___XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, X__XXXXX, XXXXXXX_, ________, ____XXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, ___XXXXX, XXXXX___, ________, ______XX, XXXXXXXX, XXXX___X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, ___XXXXX, XXXX____, ________, _______X, XXXXXXXX, XXXX____, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXX_____, ________, ________, XXXXXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XX______, __XXXXXX, X_______, _XXXXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XX______, XXXXXXXX, XXX_____, _XXXXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, X______X, XXXXXXXX, XXXX____, __XXXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, ______XX, XXXXXXXX, XXXXX___, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, _____XXX, XXXXXXXX, XXXXXX__, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, _____XXX, XXXXXXXX, XXXXXX__, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, ____XXXX, XXXXXXXX, XXXXXXX_, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, ____XXXX, XXXXXXXX, XXXXXXX_, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, ____XXXX, XXXXXXXX, XXXXXXX_, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, ____XXXX, XXXXXXXX, XXXXXXX_, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, _____XXX, XXXXXXXX, XXXXXX__, ___XXXXX, XXXX__X_, XXXXXXXX, XX______, ____XXX_, _______X, XXXX__XX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, _____XXX, XXXXXXXX, XXXXXX__, ___XXXXX, XXXX__X_, XXXXXXXX, XX______, ____XXX_, _______X, XXXX__XX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, X_____XX, XXXXXXXX, XXXXX___, __XXXXXX, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, _XXXXXX_, _XXXXX__, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, X______X, XXXXXXXX, XXXX____, __XXXXXX, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, _XXXXXX_, _XXXXX__, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XX______, XXXXXXXX, XXX_____, ___XXXXX, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, _______X, XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XX______, __XXXXXX, X_______, ____XXXX, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, _______X, XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXX_____, ________, ________, _____XXX, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, ___XXXXX, XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXXX____, ________, ________, ______XX, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, _____XXX, XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXXXXX__, ________, ____X___, _______X, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, _XX_____, _XXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXXXXXXX, ________, ___XXX__, ________, XXXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, _XXXX___, _XXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ________, _XXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ________, _XXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_______, _XXX__X_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXX_, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______, _XXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, ________, _XXXXXXX, __XXXXXX, X____XXX, __XXXXXX, __XXXXXX,
  XXXXXXX_, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX_____, _XXX__X_, XXXXXXXX, XXXXXX__, XXXXXXX_, ________, _XXXXXXX, __XXXXXX, X____XXX, ___XXXXX, __XXXXXX,
  XXXXXXX_, X___XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX___X_, XXXXXXXX, XXXX__XX, __XXXXX_, _XXXXXXX, XXXXXX__, XX__XXXX, XX__XXXX, ____XXXX, __XXXXXX,
  XXXXXXX_, X___XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX___X_, XXXXXXXX, XXXX__XX, __XXXXX_, _XXXXXXX, XXXXXX__, XX__XXXX, XX__XXXX, __X__XXX, __XXXXXX,
  XXXXXXX_, X____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX____X_, XXXXXXXX, XX__XXXX, XX__XXX_, _XXX____, _XXX__XX, XXXX__XX, XX__XXXX, __X___XX, __XXXXXX,
  XXXXXXX_, X__X__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__X__X_, XXXXXXXX, XX__XXXX, XX__XXX_, _XXX____, _XXX__XX, XXXX__XX, XX__XXXX, __XX___X, __XXXXXX,
  XXXXXXX_, X__X____, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ___X__X_, XXXXXXXX, XX______, ____XXX_, _XXXXXX_, _XXX____, ______XX, XX__XXXX, __XXX__X, __XXXXXX,
  XXXXXXX_, ___XX___, ________, ________, ________, ________, __XX____, XXXXXXXX, XX______, ____XXX_, _XXXXXX_, _XXX____, ______XX, XX__XXXX, __XXXX__, __XXXXXX,
  XXXXXXX_, _X__XX__, ________, ________, ________, ________, _XX__X__, XXXXXXXX, XX__XXXX, XX__XXX_, ________, _XXX__XX, XXXX__XX, X____XXX, __XXXXX_, __XXXXXX,
  XXXXXXX_, _XX__XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XX__, XXXXXXXX, XX__XXXX, XX__XXX_, ________, _XXX__XX, XXXX__XX, X____XXX, __XXXXXX, __XXXXXX,
  XXXXXXXX, __XX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, X__XX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XX__XX__, ________, ________, ________, ________, _XX__XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXX__XXX, ________, ________, ________, _______X, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXX___X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXX___, ________, ________, ________, ________, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX
};

GUI_CONST_STORAGE GUI_BITMAP bmscan_again_128x64 = {
  128, // xSize
  64, // ySize
  16, // BytesPerLine
  1, // BitsPerPixel
  _acscan_again_128x64,  // Pointer to picture data (indices)
  &_Palscan_again_128x64   // Pointer to palette
};

/*************************** End of file ****************************/
