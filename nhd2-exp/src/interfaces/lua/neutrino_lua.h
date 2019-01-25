/*
	$Id: neutrino_lua.h 25.01.2019 mohousch Exp $

	Kommentar:

	Diese GUI wurde von Grund auf neu programmiert und sollte nun vom
	Aufbau und auch den Ausbaumoeglichkeiten gut aussehen. Neutrino basiert
	auf der Client-Server Idee, diese GUI ist also von der direkten DBox-
	Steuerung getrennt. Diese wird dann von Daemons uebernommen.


	License: GPL

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __neutrino_lua_h__
#define __neutrino_lua_h__

/* LUA Is C */
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <string>
#include <vector>


class neutrinoLua
{
	private:
		lua_State* lua;

	public:
		neutrinoLua();
		~neutrinoLua();

		void runScript(const char *fileName, std::vector<std::string> *argv = NULL, std::string *result_code = NULL, std::string *result_string = NULL, std::string *error_string = NULL);
	void abortScript();

		// Example: runScript(fileName, "Arg1", "Arg2", "Arg3", ..., NULL);
		// Type of all parameters: const char*
		// The last parameter to NULL is imperative.
		void runScript(const char *fileName, const char *arg0, ...);
};

#endif



