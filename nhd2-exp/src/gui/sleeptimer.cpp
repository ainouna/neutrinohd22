/*      
        Neutrino-GUI  -   DBoxII-Project

        Copyright (C) 2001 Steffen Hehn 'McClean'
        Homepage: http://dbox.cyberphoria.org/

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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>

#include <global.h>

#include <gui/sleeptimer.h>

#include <gui/widget/hintbox.h>
#include <gui/widget/messagebox.h>
#include <gui/widget/stringinput.h>

#include <timerdclient/timerdclient.h>

#include <daemonc/remotecontrol.h>

#include <system/debug.h>


extern CRemoteControl * g_RemoteControl; /* neutrino.cpp */

int CSleepTimerWidget::exec(CMenuTarget* parent, const std::string &)
{
	dprintf(DEBUG_NORMAL, "CSleepTimerWidget::exec\n");

	int    res = RETURN_REPAINT;
	int    shutdown_min = 0;
	char   value[16];
	CStringInput* inbox = NULL;

	if (parent)
		parent->hide();
   
	shutdown_min = g_Timerd->getSleepTimerRemaining();  // remaining shutdown time?
	sprintf(value,"%03d", shutdown_min);
	CSectionsdClient::CurrentNextInfo info_CurrentNext;
	g_InfoViewer->getEPG(g_RemoteControl->current_channel_id, info_CurrentNext);
	
  	if ( info_CurrentNext.flags & CSectionsdClient::epgflags::has_current) 
	{
  		time_t jetzt = time(NULL);
  		int current_epg_zeit_dauer_rest = (info_CurrentNext.current_zeit.dauer + 150 - (jetzt - info_CurrentNext.current_zeit.startzeit ))/60 ;
  		
  		if(shutdown_min == 0 && current_epg_zeit_dauer_rest > 0 && current_epg_zeit_dauer_rest < 1000)
  		{
  			sprintf(value,"%03d", current_epg_zeit_dauer_rest);
  		}
  	}

	inbox = new CStringInput(_("Sleeptimer"), value, 3, _("Shutdown time in min. (000=off)"), _("The STB will shutdown after this time."), "0123456789 ");
	inbox->exec (NULL, "");
	inbox->hide ();

	delete inbox;

	int new_val = atoi(value);
		
	if(shutdown_min != new_val) 
	{
		shutdown_min = new_val;
		
		dprintf(DEBUG_NORMAL, "CSleepTimerWidget::exec: sleeptimer min: %d\n", shutdown_min);
		
		if (shutdown_min == 0)	// if set to zero remove existing sleeptimer 
		{
			if(g_Timerd->getSleeptimerID() > 0) 
			{
				g_Timerd->removeTimerEvent(g_Timerd->getSleeptimerID());
			}
		}
		else	// set the sleeptimer to actual time + shutdown mins and announce 1 min before
			g_Timerd->setSleeptimer(time(NULL) + ((shutdown_min - 1) * 60), time(NULL) + shutdown_min * 60, 0);
	}
	
	return res;
}


