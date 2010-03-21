/******************************************************************************
/ SnM_Actions.h
/
/ Copyright (c) 2009-2010 Tim Payne (SWS), JF B�dague 
/ http://www.standingwaterstudios.com/reaper
/
/ Permission is hereby granted, free of charge, to any person obtaining a copy
/ of this software and associated documentation files (the "Software"), to deal
/ in the Software without restriction, including without limitation the rights to
/ use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
/ of the Software, and to permit persons to whom the Software is furnished to
/ do so, subject to the following conditions:
/ 
/ The above copyright notice and this permission notice shall be included in all
/ copies or substantial portions of the Software.
/ 
/ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
/ EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
/ OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
/ NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
/ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
/ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/ FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
/ OTHER DEALINGS IN THE SOFTWARE.
/
******************************************************************************/

#pragma once

#include "SNM_Chunk.h"

#define SNM_CMD_SHORTNAME(_ct) (_ct->accel.desc + 9) // +9 to skip "SWS/S&M: "
#define SNM_FORMATED_INI_FILE "%s\\Plugins\\S&M.ini"

// *** SnM_Actions.cpp ***
int SnMActionsInit();
void SNM_ShowConsoleMsg(const char* _title, const char* _msg); 


// *** SnM_FX.cpp ***
void patchSelTracksFXState(int _mode, int _token, int _fx, const char* _value, const char * _undoMsg);
void toggleFXOfflineSelectedTracks(COMMAND_T* _ct);
void toggleFXBypassSelectedTracks(COMMAND_T* _ct);
void toggleExceptFXOfflineSelectedTracks(COMMAND_T* _ct);
void toggleExceptFXBypassSelectedTracks(COMMAND_T* _ct);
void toggleAllFXsOfflineSelectedTracks(COMMAND_T* _ct);
void toggleAllFXsBypassSelectedTracks(COMMAND_T* _ct);
void setFXOfflineSelectedTracks(COMMAND_T* _ct); 
void setFXBypassSelectedTracks(COMMAND_T* _ct);
void setFXOnlineSelectedTracks(COMMAND_T* _ct);
void setFXUnbypassSelectedTracks(COMMAND_T* _ct);
void setAllFXsBypassSelectedTracks(COMMAND_T* _ct); // ..related online/offline actions natively implemented

int selectFX(MediaTrack* _tr, int _fx);
int getSelectedFX(MediaTrack* _tr);
void selectFX(COMMAND_T* _ct);


// *** SnM_FXChain.cpp ***
void loadPasteTakeFXChain(COMMAND_T* _ct);
void loadPasteAllTakesFXChain(COMMAND_T* _ct);
void loadPasteTakeFXChain(const char* _title, int _slot, bool _activeOnly);
void copyTakeFXChain(COMMAND_T* _ct);
void cutTakeFXChain(COMMAND_T* _ct);
void pasteTakeFXChain(COMMAND_T* _ct);
void pasteAllTakesFXChain(COMMAND_T* _ct);
void clearActiveTakeFXChain(COMMAND_T* _ct);
void clearAllTakesFXChain(COMMAND_T* _ct);
void setTakeFXChain(const char* _title, int _slot, bool _activeOnly, bool _clear);
//void setActiveTakeFXChain(COMMAND_T* _ct);
//void setAllTakesFXChain(COMMAND_T* _ct);

void loadPasteTrackFXChain(COMMAND_T* _ct);
void clearTrackFXChain(COMMAND_T* _ct);
void setTrackFXChain(const char* _title, int _slot, bool _clear);
void copyTrackFXChain(COMMAND_T* _ct);
void cutTrackFXChain(COMMAND_T* _ct);
void pasteTrackFXChain(COMMAND_T* _ct);

int promptForSlot(const char* _title);
void clearFXChainSlot(COMMAND_T* _ct);
void showFXChainSlots(COMMAND_T* _ct);
void loadStoreFXChain(int _slot, const char* _filename);
void browseStoreFXChain(int _slot, const char* _title);
void loadOrBrowseFXChain(int _slot, const char* _title);
void readIniFile(int _slot, char* _buf, int _bufSize);
void saveIniFile(int _slot, const char* _path);


// *** SnM_Windows.cpp ***
void toggleShowHideWin(const char * _title);
void closeWin(const char * _title);
void closeOrToggleWindows(bool _routing, bool _env, bool _toggle);
void closeRoutingWindows(COMMAND_T * _c);
void closeEnvWindows(COMMAND_T * _c);
void toggleRoutingWindows(COMMAND_T * _c);
void toggleEnvWindows(COMMAND_T * _c);

void showFXChain(MediaTrack* _tr, int _fx);
void showFXChain(COMMAND_T* _ct);
void floatFX(MediaTrack* _tr, int _fx);
void unfloatFX(MediaTrack* _tr, int _fx);
void floatFX(COMMAND_T* _ct);
void unfloatFX(COMMAND_T* _ct);

void setMainWindowActive(COMMAND_T* _ct);


// *** SnM_Sends.cpp ***
bool addSend(MediaTrack * _srcTr, MediaTrack * _destTr, int _type, SNM_SendPatcher* _p);
void cueTrack(char * _busName, int _type, const char * _undoMsg);
void cueTrackPrompt(COMMAND_T* _ct);
void cueTrack(COMMAND_T* _ct);
void removeReceives(COMMAND_T* _ct);


// *** SnM_Item.cpp ***
bool selectItemsByName(const char* cUndoMsg, char* cName);
bool selectItemsByNamePrompt(const char* cCaption, char * _reply);
void selectItemsByNamePrompt(COMMAND_T* _ct);
void clearTake(COMMAND_T* _ct);
bool addEmptyTake(MediaItem* _item);
bool addTake(MediaItem* _item, WDL_String* _chunk);
bool removeTake(MediaItem* _item, int _take);
bool removeTakeOrItem(MediaTrack* _tr, MediaItem* _item, int _take);
void moveTake(COMMAND_T* _ct);
int makeTakeLanesSelectedTracks(const char* _undoTitle);
void selectTakeLane(COMMAND_T* _ct);
void makeTakeLanesSelectedTracks(COMMAND_T* _ct);
void removeEmptyTakes(COMMAND_T* _ct);
void splitMidiAudio(COMMAND_T* _ct);


// *** SnM_Misc.cpp ***
void moveTrack(int _src, int _dest); 
void moveTest(COMMAND_T* _ct);
