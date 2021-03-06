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
#include "wm_mabot.h"
#include "bmp_battery.h"
#include "bmp_runing_status.h"
#include "bmp_dividing.h"
#include "bmp_mini_mabot.h"

#include "usart.h"
#include "message_manager.h"
#include "power_function.h"
// USER END

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_MABOT      (GUI_ID_USER + 0x00)
#define ID_IMAGE_BATTERY     (GUI_ID_USER + 0x01)
#define ID_IMAGE_STATUS      (GUI_ID_USER + 0x02)
#define ID_IMAGE_TITLE       (GUI_ID_USER + 0x03)
#define ID_IMAGE_DIVID       (GUI_ID_USER + 0x04)

#define ID_TIMER_MABOT       0   
#define ID_TIMER_BATTERY     1   

typedef enum{
    bottom = 0,
    bottom_center,
    top,
    top_center
}MABOT_POSITION;

WM_HWIN hwin_mabot = WM_HWIN_NULL;
static  WM_HTIMER htimer_battery_runing = WM_HWIN_NULL;   // battery charge........

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = 
{
    { WINDOW_CreateIndirect, "wm_picture",   ID_WINDOW_MABOT,   0, 0, 128, 64, 0, 0x0, 0 },
    { IMAGE_CreateIndirect, "image_battery", ID_IMAGE_BATTERY,  105, 0, 19, 14, 0, 0, 0 },
    { IMAGE_CreateIndirect, "image_logo",    ID_IMAGE_STATUS,     0, 16, 128, 49, 0, 0, 0 },
    { IMAGE_CreateIndirect, "image_title",   ID_IMAGE_TITLE,      0, 0, 64, 14, 0, 0, 0 },
    { IMAGE_CreateIndirect, "image_divid",   ID_IMAGE_DIVID,      0, 15, 128, 1, 0, 0, 0 },
};

static void wm_mabot_init(const WM_MESSAGE * pMsg)
{
    WM_CreateTimer(WM_GetClientWindow(pMsg->hWin), ID_TIMER_MABOT, 2000, 0);
    IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_STATUS),&bmruning_status1_128x49);
    IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_TITLE),&bmmini_mabot_43x14);
    IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_DIVID),&bmdividing_128x1);
    //IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery100_23x14);
}

static void wm_mabot_doing(const WM_MESSAGE * pMsg)
{
    static MABOT_POSITION mabot_position = bottom;
    switch(mabot_position)
    {
        case bottom:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_STATUS),&bmruning_status1_128x49);
            mabot_position = bottom_center;
            break;
        case bottom_center:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_STATUS),&bmruning_status2_128x49);
            mabot_position = top;
            break;
        case top:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_STATUS),&bmruning_status3_128x49);
            mabot_position = top_center;
            break;
        case top_center:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_STATUS),&bmruning_status4_128x49);
            mabot_position = bottom;
            break;
    }
}

static void wm_mabot_battery_image_doing(const WM_MESSAGE * pMsg)
{
    static POWER_IMAGE_STATUS power_image_status = zero;
    switch(power_image_status)
    {    
        case zero:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery0_23x14);
            power_image_status = low;
            break;
        case low:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery34_23x14);
            power_image_status = medium;
            break;
        case medium:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery67_23x14);
            power_image_status = full;
            break;
        case full:
            IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery100_23x14);
            power_image_status = zero;
            break;
        default:
            break;
    }
}

static void wm_mabot_delete_htimer(const WM_MESSAGE * pMsg)
{
    if(htimer_battery_runing != WM_HWIN_NULL)
    {
        WM_DeleteTimer(htimer_battery_runing);
        htimer_battery_runing = WM_HWIN_NULL;
    }
}

static void wm_mabot_update_battery(const WM_MESSAGE * pMsg)
{
    POWER_STATUS power_status = full;
    if(gui_msg.type == bat_power)
    {
        power_status = gui_msg.data.percent;
        switch(power_status)
        {
            case full:
                IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery100_23x14);
                wm_mabot_delete_htimer(pMsg);
                break;
            case medium:
                IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery67_23x14);
                wm_mabot_delete_htimer(pMsg);
                break;
            case low:
                IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery34_23x14);
                wm_mabot_delete_htimer(pMsg);
                break;
            case zero:
                IMAGE_SetBitmap(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY),&bmbattery0_23x14);
                wm_mabot_delete_htimer(pMsg);
                break;
            case charge:
                if(htimer_battery_runing == WM_HWIN_NULL)
                {
                    htimer_battery_runing = WM_CreateTimer(WM_GetClientWindow(pMsg->hWin), ID_TIMER_BATTERY, 3000, 0);
                }
                break;
            default:
                break;
        }  
    }
}

static void wm_mabot_free_window_object(const WM_MESSAGE * pMsg)
{
    // emwin-V5.04 WM_DeleteWindow() now also deletes any associated timer but
    WM_DeleteTimer(htimer_battery_runing);
    htimer_battery_runing = WM_HWIN_NULL;
    WM_DeleteWindow(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_STATUS));
    WM_DeleteWindow(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_TITLE));
    WM_DeleteWindow(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_DIVID));
    WM_DeleteWindow(WM_GetDialogItem(pMsg->hWin, ID_IMAGE_BATTERY));
    WM_DeleteWindow(WM_GetDialogItem(pMsg->hWin, ID_WINDOW_MABOT));
}

static void _cbDialog(WM_MESSAGE * pMsg)
{
    int id = 0;
    switch (pMsg->MsgId) 
    {
        case WM_INIT_DIALOG:
            wm_mabot_init(pMsg);
            break;
        case WM_DELETE:
            wm_mabot_free_window_object(pMsg);
            break;
        case WM_TIMER:
            id = WM_GetTimerId(pMsg->Data.v);
            switch (id)
            {
                case ID_TIMER_MABOT:
                    wm_mabot_doing(pMsg);
                    wm_mabot_update_battery(pMsg);
                    WM_RestartTimer(pMsg->Data.v, 2000);
                    break;
                case ID_TIMER_BATTERY:
                    wm_mabot_battery_image_doing(pMsg);
                    WM_RestartTimer(pMsg->Data.v, 3000);
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

void create_mabot_window(void) {
    hwin_mabot = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
}

/*************************** End of file ****************************/
