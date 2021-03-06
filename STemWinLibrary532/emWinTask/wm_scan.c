/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
#include "wm_scan.h"
#include "bmp_scan.h"

#include "usart.h"
#include "message_manager.h"

#define ID_WINDOW_SCAN              (GUI_ID_USER + 0x00)
#define ID_IMAGE_SCAN               (GUI_ID_USER + 0x01)

#define ID_TIMER_SCAN               0

typedef enum{
    bottom = 0,
    left_bottom,
    left,
    left_top,
    top,
    right_top,
    right,
    right_bottom,
}SCAN_POSITION;

WM_HWIN hwin_scan = WM_HWIN_NULL;
static WM_HTIMER htimer_scan = WM_HWIN_NULL;       //static image

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = 
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_SCAN, 0, 0, 128, 64, 0, 0x0, 0 },
    { IMAGE_CreateIndirect,  "Image" , ID_IMAGE_SCAN,  0, 0, 128, 64, 0, 0x0, 0 },
};

static void wm_scan_init(const WM_MESSAGE * pMsg)
{
    htimer_scan = WM_CreateTimer ( WM_GetClientWindow ( pMsg->hWin ), ID_TIMER_SCAN, 2000, 0 );
    IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan1_128x64 );
}

static void wm_scan_doing(const WM_MESSAGE * pMsg)
{
    static SCAN_POSITION scan_position = left;
    switch(scan_position)
    {
        case bottom:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan1_128x64 );
            scan_position = left_bottom;
            break;
        case left_bottom:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan2_128x64 );
            scan_position = left;
            break;
        case left:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan3_128x64 );
            scan_position = left_top;
            break;
        case left_top:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan4_128x64 );
            scan_position = top;
            break;
        case top:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan5_128x64 );
            scan_position = right_top;
            break;
        case right_top:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan6_128x64 );
            scan_position = right;
            break;
        case right:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan7_128x64 );
            scan_position = right_bottom;
            break;
        case right_bottom:
            IMAGE_SetBitmap ( WM_GetDialogItem ( pMsg->hWin, ID_IMAGE_SCAN ), &bmscan8_128x64 );
            scan_position = bottom;
            break;
    }
    WM_RestartTimer(pMsg->Data.v, 2000);
}

static void wm_scan_free_window_object(const WM_MESSAGE * pMsg)
{
    // emwin-V5.04 WM_DeleteWindow() now also deletes any associated timer but
    WM_DeleteTimer(htimer_scan);
    htimer_scan = WM_HWIN_NULL;
    WM_DeleteWindow(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_SCAN));
    WM_DeleteWindow(WM_GetDialogItem(pMsg->hWin, ID_WINDOW_SCAN));
}

static void _cbDialog(WM_MESSAGE * pMsg) 
{
    int  id = 0;
    switch (pMsg->MsgId) 
    {
        case WM_INIT_DIALOG:
            wm_scan_init(pMsg);
            break;
        case WM_DELETE:
            wm_scan_free_window_object(pMsg);
            break;  
        case WM_TIMER:
            id = WM_GetTimerId(pMsg->Data.v);
            switch (id)
            {
                case ID_TIMER_SCAN:
                    wm_scan_doing(pMsg);
                    break;
                default:
                    break;
            } 
            break;
        default:
            WM_DefaultProc(pMsg);
            break;
    }
}

void create_scan_window(void)
{
    hwin_scan = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
}

/*************************** End of file ****************************/
