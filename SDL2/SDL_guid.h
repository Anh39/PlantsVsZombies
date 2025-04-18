/*
  Simple DirectMedia Layer
<<<<<<< HEAD
  Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>
=======
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>
>>>>>>> 5e9bf6f7f7c32dc8630af8186b69b98806c89a83

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

<<<<<<< HEAD
/* WIKI CATEGORY: GUID */

/**
 * # CategoryGUID
 *
 * A GUID is a 128-bit value that represents something that is uniquely
 * identifiable by this value: "globally unique."
=======
/**
 *  \file SDL_guid.h
 *
 *  Include file for handling ::SDL_GUID values.
>>>>>>> 5e9bf6f7f7c32dc8630af8186b69b98806c89a83
 */

#ifndef SDL_guid_h_
#define SDL_guid_h_

#include "SDL_stdinc.h"
#include "SDL_error.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

/**
<<<<<<< HEAD
 * An SDL_GUID is a 128-bit identifier.
 *
 * This is an acronym for "Globally Unique ID."
 *
 * While a GUID can be used to assign a unique value to almost anything, in
 * SDL these are largely used to identify input devices across runs of SDL
 * programs on the same platform.If the device is detached and then
 * re-attached to a different port, or if the base system is rebooted, the
 * device should still report the same GUID.
 *
 * GUIDs are as precise as possible but are not guaranteed to distinguish
 * physically distinct but equivalent devices. For example, two game
 * controllers from the same vendor with the same product ID and revision may
 * have the same GUID.
 *
 * GUIDs may be platform-dependent (i.e., the same device may report different
 * GUIDs on different operating systems).
 */
typedef struct SDL_GUID {
=======
 * An SDL_GUID is a 128-bit identifier for an input device that
 *   identifies that device across runs of SDL programs on the same
 *   platform.  If the device is detached and then re-attached to a
 *   different port, or if the base system is rebooted, the device
 *   should still report the same GUID.
 *
 * GUIDs are as precise as possible but are not guaranteed to
 *   distinguish physically distinct but equivalent devices.  For
 *   example, two game controllers from the same vendor with the same
 *   product ID and revision may have the same GUID.
 *
 * GUIDs may be platform-dependent (i.e., the same device may report
 *   different GUIDs on different operating systems).
 */
typedef struct {
>>>>>>> 5e9bf6f7f7c32dc8630af8186b69b98806c89a83
    Uint8 data[16];
} SDL_GUID;

/* Function prototypes */

/**
<<<<<<< HEAD
 * Get an ASCII string representation for a given SDL_GUID.
 *
 * You should supply at least 33 bytes for pszGUID.
 *
 * \param guid the SDL_GUID you wish to convert to string.
 * \param pszGUID buffer in which to write the ASCII string.
 * \param cbGUID the size of pszGUID.
=======
 * Get an ASCII string representation for a given ::SDL_GUID.
 *
 * You should supply at least 33 bytes for pszGUID.
 *
 * \param guid the ::SDL_GUID you wish to convert to string
 * \param pszGUID buffer in which to write the ASCII string
 * \param cbGUID the size of pszGUID
>>>>>>> 5e9bf6f7f7c32dc8630af8186b69b98806c89a83
 *
 * \since This function is available since SDL 2.24.0.
 *
 * \sa SDL_GUIDFromString
 */
extern DECLSPEC void SDLCALL SDL_GUIDToString(SDL_GUID guid, char *pszGUID, int cbGUID);

/**
<<<<<<< HEAD
 * Convert a GUID string into a SDL_GUID structure.
=======
 * Convert a GUID string into a ::SDL_GUID structure.
>>>>>>> 5e9bf6f7f7c32dc8630af8186b69b98806c89a83
 *
 * Performs no error checking. If this function is given a string containing
 * an invalid GUID, the function will silently succeed, but the GUID generated
 * will not be useful.
 *
<<<<<<< HEAD
 * \param pchGUID string containing an ASCII representation of a GUID.
 * \returns a SDL_GUID structure.
=======
 * \param pchGUID string containing an ASCII representation of a GUID
 * \returns a ::SDL_GUID structure.
>>>>>>> 5e9bf6f7f7c32dc8630af8186b69b98806c89a83
 *
 * \since This function is available since SDL 2.24.0.
 *
 * \sa SDL_GUIDToString
 */
extern DECLSPEC SDL_GUID SDLCALL SDL_GUIDFromString(const char *pchGUID);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_guid_h_ */

/* vi: set ts=4 sw=4 expandtab: */
