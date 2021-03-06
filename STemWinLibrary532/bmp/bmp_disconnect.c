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
* Source file: disconnect_128x49                                     *
* Dimensions:  128 * 49                                              *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include "bmp_disconnect.h"
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
static GUI_CONST_STORAGE GUI_COLOR _Colorsdisconnect_128x49[] = {
  0x000000, 0xFFFFFF
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Paldisconnect_128x49 = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsdisconnect_128x49[0]
};

static GUI_CONST_STORAGE unsigned char _acdisconnect_128x49[] = {
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, ____XXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX____X, XX____XX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX___X_X, XX_X___X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXX_X, XX_XXX__, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXX__X, XX__XXX_, _XXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, _XXXX_XX, XXX_XXXX, _XXXXXXX, XXXXXXXX,
  XXXXXX__, ________, ________, ________, ____XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXX_XXX, XXXX_XXX, __XXXXXX, XXXXXXXX,
  XXXXX___, ________, ________, ________, _____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XX_XXX_, __XXX_XX, __XXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, X____XXX, XXXXXXXX, XX____XX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ________, X_______, __XXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XX____XX, XXXXXXXX, X____XXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ________, X_______, __XXXXXX, XXXXXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XX__XX__, XXX__XXX, XXXXXXXX, XXX____X, XXXXXXXX, ____XXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XX_XXX_, __XXX_XX, __XXXXXX, XXXXXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XX__XX__, XXX__XXX, XXXXXXXX, XXXX____, XXXXXXX_, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXX_XXX, XXXX_XXX, __XXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXX___, _XXXXX__, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, _XXXX_XX, XXX_XXXX, _XXXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXX__, __XXX___, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXX__X, XX__XXX_, _XXXXXXX, XXXXXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XX__XX__, XXX__XXX, XXXXXXXX, XXXXXXX_, ___X____, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXX_X, XX_XXX__, XXXXXXXX, XXXXXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XX__XX__, XXX__XXX, XXXXXXXX, XXXXXXXX, _______X, XXXXXXXX, XXXXXXXX, XXXXXXX_, _____XXX, XX__XX_X, XX_XX__X, XXXXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, X____XXX, X____XXX, X_____XX, XX____XX, XX____XX, XXXXX___, XXXX___X, XXX____X, XX____XX, XXXXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, X____XXX, X____XXX, XX___XXX, XX____XX, XX____XX, XXXX___X, XXXXX___, XXXXX___, ____XXXX, XXXXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, X____XXX, X____XXX, X_____XX, XX____XX, XX____XX, XXX__XXX, X__XXXX_, _XX_____, ______XX, XXXXXXXX, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, _______X, XXXXXXXX, XXXXXXXX, XX__XXXX, X__XXXXX, ____XXXX, XXXXX__X, XXXXXXXX, XXXXXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XXXX__XX, XXX__XXX, XXXXXXXX, XXXXXXX_, ___X____, XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXXXXXX, X_X_____, ______XX, XXXXXXXX, XXXXXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XXX____X, XXX__XXX, XXXXXXXX, XXXXXX__, __XXX___, _XXXXXXX, XXXXXXXX, X__XXXXX, X__XXXXX, X__XXX__, ___XXXXX, XXX_____, XXXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XX______, XXX__XXX, XXXXXXXX, XXXXX___, _XXXXX__, __XXXXXX, XXXXXXXX, X__XXXXX, ____XXXX, X__XX__X, XX__XXXX, XX__XXX_, _XXXXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XX______, XXX__XXX, XXXXXXXX, XXXX____, XXXXXXX_, ___XXXXX, XXXXXXXX, X_XX__X_, _XX__X__, XX_X__XX, XXX__X__, X__XXXXX, __XXXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XXX____X, XXX__XXX, XXXXXXXX, XXX____X, XXXXXXXX, ____XXXX, XXXXXXXX, X_XX__X_, _XX__X__, XX___XXX, XXXX____, __XXXXXX, X__XXXXX,
  XXXXX__X, XX__XX__, XX__XX__, XXXX__XX, XXX__XXX, XXXXXXXX, XX____XX, XXXXXXXX, X____XXX, XXXXXXXX, X__XXXXX, ____XXXX, X___XXX_, __XXX___, _XXX___X, XX_XXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, X____XXX, XXXXXXXX, XX____XX, XXXXXXXX, X__XXXXX, X__XXXXX, X_______, X_______, _XXX_X_X, XX_XXXXX,
  XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXXXXXX, X_X_XXX_, __XXX___, _XXX___X, XX_XXXXX,
  XXXXX___, ________, ________, ________, _____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, X__XXXXX, __X__XXX, XXXX____, __XXXXXX, X__XXXXX,
  XXXXXX__, ________, ________, ________, ____XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, X__XXXX_, _XXX__XX, XXX__X__, X__XXXXX, __XXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXX__, XXXXX__X, XX__XXXX, XX__XXX_, _XXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, XXXX___X, XXXXXX__, ___XXXXX, XXX_____, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
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

GUI_CONST_STORAGE GUI_BITMAP bmdisconnect_128x49 = {
  128, // xSize
  49, // ySize
  16, // BytesPerLine
  1, // BitsPerPixel
  _acdisconnect_128x49,  // Pointer to picture data (indices)
  &_Paldisconnect_128x49   // Pointer to palette
};

/*************************** End of file ****************************/
