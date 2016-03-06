/*
 * OSARA: Open Source Accessibility for the REAPER Application
 * Main header
 * Author: James Teh <jamie@nvaccess.org>
 * Copyright 2014-2015 NV Access Limited
 * License: GNU General Public License version 2.0
 */

#ifndef _OSARA_H
#define _OSARA_H

#define UNICODE
#include <windows.h>
#include <string>
#include <sstream>

#define REAPERAPI_MINIMAL
#define REAPERAPI_WANT_GetLastTouchedTrack
#define REAPERAPI_WANT_GetSetMediaTrackInfo
#define REAPERAPI_WANT_TimeMap2_timeToBeats
#define REAPERAPI_WANT_GetCursorPosition
#define REAPERAPI_WANT_GetContextMenu
#define REAPERAPI_WANT_GetSelectedMediaItem
#define REAPERAPI_WANT_GetSetMediaItemInfo
#define REAPERAPI_WANT_GetActiveTake
#define REAPERAPI_WANT_GetTakeName
#define REAPERAPI_WANT_Main_OnCommand
#define REAPERAPI_WANT_CountTracks
#define REAPERAPI_WANT_GetTrack
#define REAPERAPI_WANT_TrackFX_GetNumParams
#define REAPERAPI_WANT_TrackFX_GetParamName
#define REAPERAPI_WANT_TrackFX_GetCount
#define REAPERAPI_WANT_TrackFX_GetFXName
#define REAPERAPI_WANT_TrackFX_GetParam
#define REAPERAPI_WANT_TrackFX_SetParam
#define REAPERAPI_WANT_TrackFX_FormatParamValue
#define REAPERAPI_WANT_GetLastMarkerAndCurRegion
#define REAPERAPI_WANT_EnumProjectMarkers
#define REAPERAPI_WANT_GetSelectedEnvelope
#define REAPERAPI_WANT_GetEnvelopeName
#define REAPERAPI_WANT_NamedCommandLookup
#define REAPERAPI_WANT_GetMasterTrack
#define REAPERAPI_WANT_Track_GetPeakInfo
#define REAPERAPI_WANT_GetHZoomLevel
#define REAPERAPI_WANT_GetToggleCommandState
#define REAPERAPI_WANT_Main_OnCommand
#define REAPERAPI_WANT_Undo_CanUndo2
#define REAPERAPI_WANT_Undo_CanRedo2
#define REAPERAPI_WANT_parse_timestr_pos
#define REAPERAPI_WANT_GetMasterTrackVisibility
#define REAPERAPI_WANT_SetMasterTrackVisibility
#define REAPERAPI_WANT_GetAppVersion
#define REAPERAPI_WANT_SetCursorContext
#define REAPERAPI_WANT_GetPlayPosition
#define REAPERAPI_WANT_SetEditCurPos
#define REAPERAPI_WANT_CountMediaItems
#define REAPERAPI_WANT_GetSet_LoopTimeRange
#define REAPERAPI_WANT_CountTrackMediaItems
#define REAPERAPI_WANT_GetSetMediaItemTakeInfo
#define REAPERAPI_WANT_kbd_getTextFromCmd
// GetCursorContext always seems to return 1.
#define REAPERAPI_WANT_GetCursorContext2
#define REAPERAPI_WANT_CountSelectedMediaItems
#define REAPERAPI_WANT_CountSelectedTracks
#define REAPERAPI_WANT_mkvolstr
#define REAPERAPI_WANT_mkpanstr
#define REAPERAPI_WANT_parsepanstr
#define REAPERAPI_WANT_GetExtState
#define REAPERAPI_WANT_SetExtState
#define REAPERAPI_WANT_GetEnvelopePoint
#define REAPERAPI_WANT_GetEnvelopePointByTime
#define REAPERAPI_WANT_CountEnvelopePoints
#define REAPERAPI_WANT_format_timestr_pos
#define REAPERAPI_WANT_GetPlayState
#define REAPERAPI_WANT_TimeMap_curFrameRate
#define REAPERAPI_WANT_GetTrackMediaItem
#define REAPERAPI_WANT_Undo_BeginBlock
#define REAPERAPI_WANT_Undo_EndBlock
#define REAPERAPI_WANT_IsTrackVisible
#define REAPERAPI_WANT_GetMasterMuteSoloFlags
#define REAPERAPI_WANT_CountProjectMarkers
#define REAPERAPI_WANT_CountTempoTimeSigMarkers
#define REAPERAPI_WANT_FindTempoTimeSigMarker
#define REAPERAPI_WANT_GetTempoTimeSigMarker
#define REAPERAPI_WANT_GetTakeNumStretchMarkers
#define REAPERAPI_WANT_GetTakeStretchMarker
#define REAPERAPI_WANT_SetTakeStretchMarker
#define REAPERAPI_WANT_ValidatePtr
#define REAPERAPI_WANT_DeleteTempoTimeSigMarker
#define REAPERAPI_WANT_MIDIEditor_GetActive
#define REAPERAPI_WANT_MIDIEditor_GetTake
#define REAPERAPI_WANT_MIDI_CountEvts
#define REAPERAPI_WANT_MIDI_GetNote
#define REAPERAPI_WANT_MIDI_GetProjTimeFromPPQPos
#define REAPERAPI_WANT_MIDI_EnumSelNotes
#define REAPERAPI_WANT_MIDIEditor_GetSetting_int
#define REAPERAPI_WANT_MIDIEditor_OnCommand
#define REAPERAPI_WANT_TakeFX_GetNumParams
#define REAPERAPI_WANT_TakeFX_GetParamName
#define REAPERAPI_WANT_TakeFX_GetCount
#define REAPERAPI_WANT_TakeFX_GetFXName
#define REAPERAPI_WANT_TakeFX_GetParam
#define REAPERAPI_WANT_TakeFX_SetParam
#define REAPERAPI_WANT_TakeFX_FormatParamValue
#define REAPERAPI_WANT_plugin_getapi
#define REAPERAPI_WANT_Envelope_FormatValue
#define REAPERAPI_WANT_CountTrackEnvelopes
#define REAPERAPI_WANT_GetTrackEnvelope
#define REAPERAPI_WANT_CountTakeEnvelopes
#define REAPERAPI_WANT_GetTakeEnvelope
#define REAPERAPI_WANT_GetEnvelopeStateChunk
#include <reaper/reaper_plugin.h>
#include <reaper/reaper_plugin_functions.h>

typedef struct Command {
	int section;
	gaccel_register_t gaccel;
	const char* id;
	void (*execute)(Command*);
} Command;
extern int lastCommandRepeatCount;

extern HINSTANCE pluginHInstance;
extern HWND mainHwnd;

// We maintain our own idea of focus for context sensitivity.
enum FakeFocus {
	FOCUS_NONE = 0,
	FOCUS_TRACK,
	FOCUS_ITEM,
	FOCUS_RULER,
	FOCUS_MARKER,
	FOCUS_REGION,
	FOCUS_TIMESIG,
	FOCUS_STRETCH,
	FOCUS_ENVELOPE
};
extern enum FakeFocus fakeFocus;

void outputMessage(const std::string& message);
void outputMessage(std::ostringstream& message);

typedef enum {
	TF_NONE,
	TF_MEASURE,
	TF_MINSEC,
	TF_SEC,
	TF_FRAME,
	TF_HMSF,
	TF_SAMPLE
} TimeFormat;
const TimeFormat TF_RULER = TF_NONE;
std::string formatTime(double time, TimeFormat format=TF_RULER, bool isLength=false, bool useCache=true);
void resetTimeCache(TimeFormat excludeFormat=TF_NONE);

#ifdef _WIN32
#include <string>
#include <oleacc.h>

std::wstring widen(const std::string& text);
std::string narrow(const std::wstring& text);

extern IAccPropServices* accPropServices;
#endif

#endif
