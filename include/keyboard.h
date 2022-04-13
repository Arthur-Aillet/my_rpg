/*
** EPITECH PROJECT, 2022
** Armory - keyboard macros
** File description:
** macros for the get keyboard input function's returned char *
*/

#ifndef KEYBOARD_MACROS_H_
    #define KEYBOARD_MACROS_H_

    #include "csfml_libs.h"
    #include "inventory_macros.h"

    #define A       keys[0]     //sfKeyA
    #define B       keys[1]     //sfKeyB
    #define C       keys[2]     //sfKeyC
    #define D       keys[3]     //sfKeyD
    #define E       keys[4]     //sfKeyE
    #define F       keys[5]     //sfKeyF
    #define G       keys[6]     //sfKeyG
    #define H       keys[7]     //sfKeyH
    #define I       keys[8]     //sfKeyI
    #define J       keys[9]     //sfKeyJ
    #define K       keys[10]    //sfKeyK
    #define L       keys[11]    //sfKeyL
    #define M       keys[12]    //sfKeyM
    #define N       keys[13]    //sfKeyN
    #define O       keys[14]    //sfKeyO
    #define P       keys[15]    //sfKeyP
    #define Q       keys[16]    //sfKeyQ
    #define R       keys[17]    //sfKeyR
    #define S       keys[18]    //sfKeyS
    #define T       keys[19]    //sfKeyT
    #define U       keys[20]    //sfkeyU
    #define V       keys[21]    //sfKeyV
    #define W       keys[22]    //sfKeyW
    #define X       keys[23]    //sfKeyX
    #define Y       keys[24]    //sfKeyY
    #define Z       keys[25]    //sfKeyZ
    #define NUM0    keys[26]    //sfKeyNum0
    #define NUM1    keys[27]    //sfKeyNum1
    #define NUM2    keys[28]    //sfKeyNum2
    #define NUM3    keys[29]    //sfKeyNum3
    #define NUM4    keys[30]    //sfKeyNum4
    #define NUM5    keys[31]    //sfKeyNum5
    #define NUM6    keys[32]    //sfKeyNum6
    #define NUM7    keys[33]    //sfKeyNum7
    #define NUM8    keys[34]    //sfKeyNum8
    #define NUM9    keys[35]    //sfKeyNum9
    #define ESC     keys[36]    //sfKeyEscape
    #define LCTRL   keys[37]    //sfKeyLcontrol
    #define LSHIFT  keys[38]    //sfKeyLshift
    #define LALT    keys[39]    //sfkeyLalt
    #define LSYSTEM keys[40]    //sfKeyLSystem
    #define RCTRL   keys[41]    //sfkeyRcontrol
    #define RSHIFT  keys[42]    //sfKeyRshift
    #define RALT    keys[43]    //sfkeyRalt
    #define RSYSTEM keys[44]    //sfKeyRSystem
    #define MENU    keys[45]    //sfKeyMenu
    #define LBRACK  keys[46]    //sfKeyLBracket
    #define RBRACK  keys[47]    //sfKeyRBracket
    #define SEMICOL keys[48]    //sfKeySemiColon
    #define COMMA   keys[49]    //sfKeyComma
    #define PERIOD  keys[50]    //sfKeyPeriod
    #define QUOTE   keys[51]    //sfKeyQuote
    #define SLASH   keys[52]    //sfKeySlash
    #define BSLASH  keys[53]    //sfKeyBackSlash
    #define TIDLE   keys[54]    //sfKeyTilde
    #define EQUAL   keys[55]    //sfKeyEqual
    #define DASH    keys[56]    //sfKeyDash
    #define HYPHEN  keys[56]    //sfKeyHyphen
    #define SPACE   keys[57]    //sfKeySpace
    #define RETURN  keys[58]    //sfKeyReturn
    #define ENTER   keys[58]    //sfKeyEnter
    #define BACK    keys[59]    //sfKeyBack
    #define BSPACE  keys[59]    //sfKeyBackspace
    #define TAB     keys[60]    //sfKeyTab
    #define PGUP    keys[61]    //sfKeyPageUp
    #define PGDWN   keys[62]    //sfKeyPageDown
    #define END     keys[63]    //sfKeyEnd
    #define HOME    keys[64]    //sfKeyHome
    #define INSERT  keys[65]    //sfKeyInsert
    #define DEL     keys[66]    //sfKeyDelete
    #define ADD     keys[67]    //sfKeyAdd
    #define SUB     keys[68]    //sfKeySubtract
    #define MULT    keys[69]    //sfKeyMultiply
    #define DIV     keys[70]    //sfKeyDivide
    #define LEFT    keys[71]    //sfKeyLeft
    #define RIGHT   keys[72]    //sfKeyRight
    #define UP      keys[73]    //sfKeyUp
    #define DOWN    keys[74]    //sfKeyDown
    #define NUMP0   keys[75]    //sfKeyNumpad0
    #define NUMP1   keys[76]    //sfKeyNumpad1
    #define NUMP2   keys[77]    //sfKeyNumpad2
    #define NUMP3   keys[78]    //sfKeyNumpad3
    #define NUMP4   keys[79]    //sfKeyNumpad4
    #define NUMP5   keys[80]    //sfKeyNumpad5
    #define NUMP6   keys[81]    //sfKeyNumpad6
    #define NUMP7   keys[82]    //sfKeyNumpad7
    #define NUMP8   keys[83]    //sfKeyNumpad8
    #define NUMP9   keys[84]    //sfKeyNumpad9
    #define F1      keys[85]    //sfKeyF1
    #define F2      keys[86]    //sfKeyF2
    #define F3      keys[87]    //sfKeyF3
    #define F4      keys[88]    //sfKeyF4
    #define F5      keys[89]    //sfKeyF5
    #define F6      keys[90]    //sfKeyF6
    #define F7      keys[91]    //sfKeyF7
    #define F8      keys[92]    //sfKeyF8
    #define F9      keys[93]    //sfKeyF9
    #define F10     keys[94]    //sfKeyF10
    #define F11     keys[95]    //sfKeyF11
    #define F12     keys[96]    //sfKeyF12
    #define F13     keys[97]    //sfKeyF13
    #define F14     keys[98]    //sfKeyF14
    #define F15     keys[99]    //sfKeyF15
    #define PAUSE   keys[100]   //sfKeyPause
    #define COUNT   keys[101]   //sfKeyCount
    #define LCLICK  keys[102]   //event.mouseButton.button == 0
    #define RCLICK  keys[103]   //event.mouseButton.button == 1
    #define VSCROLL keys[104]   //event.mouseWheelScroll.delta y
    #define HSCROLL keys[105]   //event.mouseWheelScroll.delta x
    #define PRESS   2
    #define HELD    1
    #define RELEASE -1
    #define NHELD   0

char *get_keyboard_input(char *keys, sfRenderWindow *window);

#endif /* !KEYBOARD_MACROS_H_ */

