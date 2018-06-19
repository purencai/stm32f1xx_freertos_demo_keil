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
* Source file: loading_128x49                                        *
* Dimensions:  128 * 49                                              *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include "bmp_loading.h"
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
static GUI_CONST_STORAGE GUI_COLOR _Colorsloading_128x49[] = {
  0x000000, 0xFFFFFF
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palloading_128x49 = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsloading_128x49[0]
};

static GUI_CONST_STORAGE unsigned char _acloading_128x49[] = {
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX_____, _______X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ________, ________, __XXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ________, ________, ___XXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ___XX__X, XXX__XX_, ____XXXX, XXXXXXXX,
  XXXXXXXX, X_______, ________, ________, _______X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, _XXXX__X, XXX__XXX, X____XXX, XXXXXXXX,
  XXXXXXXX, ________, ________, ________, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX____, XXXXX__X, XXX__XXX, XX____XX, XXXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX____X, XXXX___X, XXX___XX, XXX____X, XXXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX____XX, XXX____X, XXX____X, XXXX____, XXXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XX__X, X__XXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX___XXX, XXX__XXX, XXXXX__X, XXXXX___, XXXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XX__X, X__XXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXX_XXXX, XXXXXX_X, XXXXXX__, XXXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, X___XXXX, XXXXXX__, _XXXXX__, _XXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, X__XXXXX, XXXXXXX_, _XXXXX__, _XXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XX__X, X__XXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, __XXXXX_, ___XXXXX, __XXXX__, _XXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XX__X, X__XXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, __XXXX__, ____XXXX, __XXXX__, _XXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_______, _______X, XXX_____, ________, _XXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_______, _______X, XXX_____, ________, _XXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_______, _______X, XXX_____, ________, _XXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, __XXXX__, ____XXXX, __XXXX__, _XXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XXXX_, _XXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, __XXXXX_, ___XXXXX, __XXXX__, _XXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XXX__, __XXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, X__XXXXX, XXXXXXX_, _XXXXX__, _XXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXX___, ___XXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, X___XXXX, XXXXXX__, _XXXXX__, _XXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXX___, ___XXX__, XXXXXX_X, XXX____X, X__XX___, XX___X_X, X_X____X, XXXXXXXX, XX__XXXX, XXX_XXXX, XXXXXX_X, XXXXXX__, XXXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XXX__, __XXXX__, XXXXXX_X, XXX_XX_X, _XX_X_XX, _XX_XX__, X_X_XXXX, XXXXXXXX, XX___XXX, XXX__XXX, XXXXX__X, XXXXX___, XXXXXXXX,
  XXXXXXXX, __XXX__X, X__XX__X, X__XXXX_, _XXXXX__, XXXXXX_X, XXX_XX_X, _XX_X_XX, _XX_XX__, __X_X__X, _X_XXXXX, XX____XX, XXX____X, XXX____X, XXXX____, XXXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXX_X, XXX_XX_X, ____X_XX, _XX_XX_X, __X_XX_X, XXXXXXXX, XXX____X, XXXX___X, XXX___XX, XXX____X, XXXXXXXX,
  XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXX__, __X____X, _XX_X___, XX___X_X, X_X____X, XXXXXXXX, XXXX____, XXXXX__X, XXX__XXX, XX____XX, XXXXXXXX,
  XXXXXXXX, ________, ________, ________, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, _XXXX__X, XXX__XXX, X____XXX, XXXXXXXX,
  XXXXXXXX, X_______, ________, ________, _______X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ___XX__X, XXX__XX_, ____XXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ________, ________, ___XXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ________, ________, __XXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX_____, _______X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX
};

GUI_CONST_STORAGE GUI_BITMAP bmloading_128x49 = {
  128, // xSize
  49, // ySize
  16, // BytesPerLine
  1, // BitsPerPixel
  _acloading_128x49,  // Pointer to picture data (indices)
  &_Palloading_128x49   // Pointer to palette
};

/*************************** End of file ****************************/