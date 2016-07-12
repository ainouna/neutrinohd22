/*
  $Id: test.cpp 2014/01/22 mohousch Exp $

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

#include <plugin.h>


extern "C" void plugin_exec(void);
extern "C" void plugin_init(void);
extern "C" void plugin_del(void);

class CTestMenu : CMenuTarget
{
	private:
		void testCStringInput();
		void testCStringInputSMS();
		void testCPINInput();
		void testCIPInput();
		void testCDateInput();
		void testCMACInput();
		void testCTimeInput();
		void testCIntInput();
		void testCInfoBox();
		void testCInfoBoxShowMsg();
		void testCInfoBoxInfoBox();
		void testCMessageBox();
		void testCMessageBoxInfoMsg();
		void testCMessageBoxErrorMsg();
		void testCHintBox();
		void testCHintBoxInfo();
		void testCHelpBox();
		void testCTextBox();
		void testCListFrameBox();
		void testCListBox();
		void testCListBoxDetails();
		void testCListBoxDetailsTitleInfo();
		void testCProgressBar();
		void testCProgressWindow();
		void testCButtons();
		//
		void testAudioPlayer();
		void testInternetRadio();
		void testRecordBrowser();
		void testMovieBrowser();
		void testFilePlayBack();
		void testPictureViewer();
		void testUPNPBrowser();
		//
		void testPlayMovieURL();
		void testPlayAudioURL();
		void testShowPictureURL();
		//
		void testPlayMovieFolder();
		void testPlayAudioFolder();
		void testShowPictureFolder();
		//
		void testStartPlugin();
		//
		void testShowActuellEPG();
		void testChannelSelectWidget();
		void testBEChannelSelectWidget();
		//
		void testAVSelectWidget();
		void testAudioSelectWidget();
		void testDVBSubSelectWidget();
		void testAlphaSetupWidget();
		void testPSISetup();
		void testRCLock();
		void testSleepTimerWidget();
		void testMountGUI();
		void testUmountGUI();
		void testMountSmallMenu();
		void testVFDController();
		void testColorChooser();
		void testKeyChooser();
		
		//
		void testFrameBox();

		//
		void testPluginsList();
		void testURIMovieBrowser();
		void testURIRecordBrowser();
		void testPlayMovieDir();
	public:
		CTestMenu();
		~CTestMenu();
		int exec(CMenuTarget* parent, const std::string& actionKey);
		void hide();
		void showTestMenu();
};

CTestMenu::CTestMenu()
{
}

CTestMenu::~CTestMenu()
{
}

void CTestMenu::hide()
{
	CFrameBuffer::getInstance()->paintBackground();
	CFrameBuffer::getInstance()->blit();
}

void CTestMenu::testCStringInput()
{
	std::string value;
	CStringInput * stringInput = new CStringInput("CStringInput", (char *)value.c_str());
	
	stringInput->exec(NULL, "");
	stringInput->hide();
	delete stringInput;
	stringInput = NULL;
	value.clear();
}
void CTestMenu::testCStringInputSMS()
{
	std::string value;
	CStringInputSMS * stringInputSMS = new CStringInputSMS("CStringInputSMS", (char *)value.c_str());
	
	stringInputSMS->exec(NULL, "");
	stringInputSMS->hide();
	delete stringInputSMS;
	value.clear();
}

void CTestMenu::testCPINInput()
{
	std::string value;
	CPINInput * pinInput = new CPINInput("CPINInput", (char *)value.c_str());
	
	pinInput->exec(NULL, "");
	pinInput->hide();
	delete pinInput;
	value.clear();
}

void CTestMenu::testCIPInput()
{
	std::string value;
	CIPInput * ipInput = new CIPInput(LOCALE_STREAMINGMENU_SERVER_IP, value);
	
	ipInput->exec(NULL, "");
	ipInput->hide();
	delete ipInput;
	value.clear();
}

void CTestMenu::testCMACInput()
{
	std::string value;
	CMACInput * macInput = new CMACInput(LOCALE_RECORDINGMENU_SERVER_MAC, (char *)value.c_str());
	
	macInput->exec(NULL, "");
	macInput->hide();
	delete macInput;
	value.clear();
}

void CTestMenu::testCDateInput()
{
	time_t value;
	CDateInput * dateInput = new CDateInput(LOCALE_FILEBROWSER_SORT_DATE, &value);
	
	dateInput->exec(NULL, "");
	dateInput->hide();
	delete dateInput;
}

void CTestMenu::testCTimeInput()
{
	std::string value;
	CTimeInput * timeInput = new CTimeInput(LOCALE_FILEBROWSER_SORT_DATE, (char *)value.c_str());
	
	timeInput->exec(NULL, "");
	timeInput->hide();
	delete timeInput;
	value.clear();
}

void CTestMenu::testCIntInput()
{
	int value;
	CIntInput * intInput = new CIntInput(LOCALE_FILEBROWSER_SORT_DATE, value);
	
	intInput->exec(NULL, "");
	intInput->hide();
	delete intInput;
}

void CTestMenu::testCInfoBox()
{
	int mode =  CInfoBox::SCROLL | CInfoBox::TITLE | CInfoBox::FOOT;
	CBox position(g_settings.screen_StartX + 50, g_settings.screen_StartY + 50, g_settings.screen_EndX - g_settings.screen_StartX - 100, g_settings.screen_EndY - g_settings.screen_StartY - 100); 
	
	CInfoBox * infoBox = new CInfoBox("testing CInfoBox", g_Font[SNeutrinoSettings::FONT_TYPE_MENU], mode, &position, "CInfoBox", g_Font[SNeutrinoSettings::FONT_TYPE_MENU_TITLE], NULL);
	
	infoBox->exec();
	infoBox->hide();
	delete infoBox;
}

void CTestMenu::testCInfoBoxShowMsg()
{
	InfoBox("CInfoBox", "testing CInfobox");	// UTF-8
}

void CTestMenu::testCInfoBoxInfoBox()
{
	std::string buffer;
	
	// prepare print buffer  
	buffer = "CInfoBox";
	buffer += "\n";
	buffer += "testing CInfoBox";
	buffer += "\n";

	// thumbnail
	int pich = 246;	//FIXME
	int picw = 162; 	//FIXME
	
	std::string thumbnail = PLUGINDIR "/netzkino/netzkino.png";
	if(access(thumbnail.c_str(), F_OK))
		thumbnail = "";
	
	int mode =  CInfoBox::SCROLL | CInfoBox::TITLE | CInfoBox::FOOT;
	CBox position(g_settings.screen_StartX + 50, g_settings.screen_StartY + 50, g_settings.screen_EndX - g_settings.screen_StartX - 100, g_settings.screen_EndY - g_settings.screen_StartY - 100); 
	
	CInfoBox * infoBox = new CInfoBox("testing CInfoBox", g_Font[SNeutrinoSettings::FONT_TYPE_MENU], mode, &position, "CInfoBox", g_Font[SNeutrinoSettings::FONT_TYPE_MENU_TITLE], NEUTRINO_ICON_BUTTON_SETUP);
	infoBox->setText(&buffer, thumbnail, picw, pich);
	infoBox->exec();
	delete infoBox;
}

void CTestMenu::testCMessageBox()
{
	CMessageBox * messageBox = new CMessageBox(LOCALE_MESSAGEBOX_INFO, "testing CMessageBox");
	
	messageBox->exec();
	messageBox->hide();
	delete messageBox;
}

void CTestMenu::testCMessageBoxInfoMsg()
{
	MessageBox(LOCALE_MESSAGEBOX_INFO, "testing CMessageBox", CMessageBox::mbrBack, CMessageBox::mbBack, NEUTRINO_ICON_INFO);
}

void CTestMenu::testCMessageBoxErrorMsg()
{
	MessageBox(LOCALE_MESSAGEBOX_ERROR, "testing CMessageBox", CMessageBox::mbrCancel, CMessageBox::mbCancel, NEUTRINO_ICON_ERROR);
}

void CTestMenu::testCHintBox()
{
	CHintBox * hintBox = new CHintBox(LOCALE_MESSAGEBOX_INFO, "testing CHintBox");
	
	hintBox->paint();
	sleep(3);
	hintBox->hide();
	delete hintBox;
}

void CTestMenu::testCHintBoxInfo()
{
	HintBox(LOCALE_MESSAGEBOX_INFO, "testing CHintBox");
}

void CTestMenu::testCHelpBox()
{
	Helpbox * helpBox = new Helpbox();
	
	helpBox->addLine(NEUTRINO_ICON_BUTTON_RED, "testing CHelpBox");
	helpBox->addLine("HELPBOX");
	helpBox->addLine("");
	helpBox->addPagebreak();
	helpBox->show(LOCALE_MESSAGEBOX_INFO);
	
	delete helpBox;
}

void CTestMenu::testCTextBox()
{
	CBox Box;
	
	Box.iX = g_settings.screen_StartX + 10;
	Box.iY = g_settings.screen_StartY + 10;
	Box.iWidth = g_settings.screen_EndX - g_settings.screen_StartX - 20;
	Box.iHeight = (g_settings.screen_EndY - g_settings.screen_StartY - 20);
	
	CTextBox * textBox = new CTextBox("CTextBox", NULL, CTextBox::SCROLL, &Box);
	
	std::string text = "testing CTextBox";
		
	int pich = 246;	//FIXME
	int picw = 162; 	//FIXME
		
	std::string fname;

	fname = PLUGINDIR "/netzkino/netzkino.png";
		
	if(access(fname.c_str(), F_OK))
		fname = "";
	
	textBox->setText(&text, fname, picw, pich);
	
	textBox->paint();
	
	sleep(3);
	
	delete textBox;
	textBox = NULL;
}

void CTestMenu::testCListFrameBox()
{
	CBox listFrameBox;
	LF_LINES listFrameLines;
	
	listFrameBox.iX = g_settings.screen_StartX + 10;
	listFrameBox.iY = g_settings.screen_StartY + 10;
	listFrameBox.iWidth = w_max ( (CFrameBuffer::getInstance()->getScreenWidth() / 20 * 17), (CFrameBuffer::getInstance()->getScreenWidth() / 20 ));
	listFrameBox.iHeight = h_max ( (CFrameBuffer::getInstance()->getScreenHeight() / 20 * 16), (CFrameBuffer::getInstance()->getScreenHeight() / 20));

	// recalculate x and y
	listFrameBox.iX = CFrameBuffer::getInstance()->getScreenX() + ((CFrameBuffer::getInstance()->getScreenWidth() - (listFrameBox.iWidth)) / 2);
	listFrameBox.iY = CFrameBuffer::getInstance()->getScreenY() + ((CFrameBuffer::getInstance()->getScreenHeight() - listFrameBox.iHeight) / 2);
	
	CListFrame * listFrame = new CListFrame(&listFrameLines, NULL, CListFrame::TITLE | CListFrame::HEADER_LINE, &listFrameBox);
	
	std::string testIcon = PLUGINDIR "/youtube/youtube_small.png";

	// title
	listFrame->setTitle("listFrameBox", testIcon);

	//
	std::string string_item = "Pro Sieben";

	listFrameLines.lineArray[1].clear();
	listFrameLines.lineArray[1].push_back(string_item);
	
	listFrame->setLines(&listFrameLines);
	listFrame->getSelectedLine();
	//
	
	// paint
	listFrame->paint();
	listFrame->showSelection(true);
	
	sleep(3);
	
	delete listFrame;
	listFrame = NULL;
}

void CTestMenu::testCListBox()
{
	CListBox * listBox = new CListBox("listBox", MENU_WIDTH, MENU_HEIGHT, false, false, true);

	listBox->exec(NULL, "");
	delete listBox;
}

void CTestMenu::testCListBoxDetails()
{
	CListBox * listBox = new CListBox("listBoxInfoDetails", w_max ( (CFrameBuffer::getInstance()->getScreenWidth() / 20 * 17), (CFrameBuffer::getInstance()->getScreenWidth() / 20 )), h_max ( (CFrameBuffer::getInstance()->getScreenHeight() / 20 * 16), (CFrameBuffer::getInstance()->getScreenHeight() / 20)), true, false, true);
	
	listBox->exec(NULL, "");
	delete listBox;
}

void CTestMenu::testCListBoxDetailsTitleInfo()
{
	CListBox * listBox = new CListBox("listBoxDetailsTitleInfo", w_max ( (CFrameBuffer::getInstance()->getScreenWidth() / 20 * 17), (CFrameBuffer::getInstance()->getScreenWidth() / 20 )), h_max ( (CFrameBuffer::getInstance()->getScreenHeight() / 20 * 16), (CFrameBuffer::getInstance()->getScreenHeight() / 20)), true, true, true);
	
	listBox->exec(NULL, "");
	delete listBox;
}

void CTestMenu::testCProgressBar()
{
	CProgressBar *timescale = NULL;
	
	CBox Box;
	
	Box.iX = g_settings.screen_StartX + 10;
	Box.iY = g_settings.screen_StartY + 10;
	Box.iWidth = (g_settings.screen_EndX - g_settings.screen_StartX - 20);
	Box.iHeight = (g_settings.screen_EndY - g_settings.screen_StartY - 20)/40;
	
	timescale = new CProgressBar(Box.iWidth, Box.iHeight, 30, 100, 70, true);
	timescale->reset();
	
	timescale->paint(Box.iX, Box.iY, 10);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 20);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 30);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 40);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 50);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 60);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 70);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 80);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 90);
	usleep(1000000);
	timescale->paint(Box.iX, Box.iY, 100);
	
	delete timescale;
	timescale = NULL;
	//
	hide();
}

void CTestMenu::testCProgressWindow()
{
	CProgressWindow * progress;
	
	progress = new CProgressWindow();
	progress->setTitle("CProgressWindow");
	progress->exec(NULL, "");
	
	progress->showStatusMessageUTF("testing CProgressWindow");
	progress->showGlobalStatus(0);
	usleep(1000000);
	progress->showGlobalStatus(10);
	usleep(1000000);
	progress->showGlobalStatus(20);
	usleep(1000000);
	progress->showGlobalStatus(30);
	usleep(1000000);
	progress->showGlobalStatus(40);
	usleep(1000000);
	progress->showGlobalStatus(50);
	usleep(1000000);
	progress->showGlobalStatus(60);
	usleep(1000000);
	progress->showGlobalStatus(70);
	usleep(1000000);
	progress->showGlobalStatus(80);
	usleep(1000000);
	progress->showGlobalStatus(90);
	usleep(1000000);
	progress->showGlobalStatus(100);
	usleep(1000000);
	
	progress->hide();
	delete progress;
	progress = NULL;
        
}

const struct button_label Buttons[4] =
{
	{ NEUTRINO_ICON_BUTTON_RED, NONEXISTANT_LOCALE, "add" },
	{ NEUTRINO_ICON_BUTTON_GREEN, NONEXISTANT_LOCALE, "remove" },
	{ NEUTRINO_ICON_BUTTON_YELLOW, NONEXISTANT_LOCALE, "delete" },
	{ NEUTRINO_ICON_BUTTON_BLUE, NONEXISTANT_LOCALE, "rename" },
	
};

void CTestMenu::testCButtons()
{
	int icon_w, icon_h;
	CFrameBuffer::getInstance()->getIconSize(NEUTRINO_ICON_BUTTON_RED, &icon_w, &icon_h);
	::paintButtons(CFrameBuffer::getInstance(), g_Font[SNeutrinoSettings::FONT_TYPE_INFOBAR_SMALL], g_Locale, g_settings.screen_StartX + 50 + BORDER_LEFT, g_settings.screen_StartY + 50, (g_settings.screen_EndX - g_settings.screen_StartX - 100)/4, 4, Buttons, icon_h);
	usleep(1000000);
	hide();
}

void CTestMenu::testAudioPlayer()
{
	CAudioPlayerGui tmpAudioPlayerGui;
	tmpAudioPlayerGui.exec(NULL, "");
}

void CTestMenu::testInternetRadio()
{
	CAudioPlayerGui tmpAudioPlayerGui(true);
	tmpAudioPlayerGui.exec(NULL, "");
}

void CTestMenu::testRecordBrowser()
{
	//moviePlayerGui->exec(NULL, "tsmoviebrowser");
	CMoviePlayerGui tmpMoviePlayerGui;
					
	tmpMoviePlayerGui.exec(NULL, "tsmoviebrowser");
}

void CTestMenu::testMovieBrowser()
{
	//moviePlayerGui->exec(NULL, "moviebrowser");
	CMoviePlayerGui tmpMoviePlayerGui;
					
	tmpMoviePlayerGui.exec(NULL, "moviebrowser");
}

void CTestMenu::testFilePlayBack()
{
	//moviePlayerGui->exec(NULL, "fileplayback");
	CMoviePlayerGui tmpMoviePlayerGui;
					
	tmpMoviePlayerGui.exec(NULL, "fileplayback");
}

void CTestMenu::testPictureViewer()
{
	CPictureViewerGui tmpPictureViewerGui;
	tmpPictureViewerGui.exec(NULL, "");
}

void CTestMenu::testUPNPBrowser()
{
	CUpnpBrowserGui tmpUPNPBrowserGui;
	tmpUPNPBrowserGui.exec(NULL, "");
}

void CTestMenu::testPlayMovieURL()
{
	neutrino_msg_t msg;
	neutrino_msg_data_t data;
	
	CMoviePlayerGui tmpMoviePlayerGui;	
	CFileBrowser * fileBrowser;
	
	fileBrowser = new CFileBrowser();
	
	CFileFilter fileFilter;
	
	fileFilter.addFilter("ts");
	fileFilter.addFilter("mpg");
	fileFilter.addFilter("mpeg");
	fileFilter.addFilter("divx");
	fileFilter.addFilter("avi");
	fileFilter.addFilter("mkv");
	fileFilter.addFilter("asf");
	fileFilter.addFilter("aiff");
	fileFilter.addFilter("m2p");
	fileFilter.addFilter("mpv");
	fileFilter.addFilter("m2ts");
	fileFilter.addFilter("vob");
	fileFilter.addFilter("mp4");
	fileFilter.addFilter("mov");	
	fileFilter.addFilter("flv");	
	fileFilter.addFilter("dat");
	fileFilter.addFilter("trp");
	fileFilter.addFilter("vdr");
	fileFilter.addFilter("mts");
	fileFilter.addFilter("wmv");
	fileFilter.addFilter("wav");
	fileFilter.addFilter("flac");
	fileFilter.addFilter("mp3");
	fileFilter.addFilter("wma");
	fileFilter.addFilter("ogg");

	fileBrowser->Multi_Select    = false;
	fileBrowser->Dirs_Selectable = false;
	fileBrowser->Filter = &fileFilter;
	
	std::string Path_local = g_settings.network_nfs_moviedir;

BROWSER:
	if (fileBrowser->exec(Path_local.c_str()))
	{
		Path_local = fileBrowser->getCurrentDir();
		
		CFile * file;
		
		if ((file = fileBrowser->getSelectedFile()) != NULL) 
		{
			// fill file info
			file->Title = file->getFileName();
			file->Info1 = file->getFileName();   // IMDB
			//file->Info2 = file->getFileName(); // IMDB

			std::string fname = "";
			fname = file->Name;
			changeFileNameExt(fname, ".jpg");
						
			if(!access(fname.c_str(), F_OK) )
				file->Thumbnail = fname.c_str();
					
			tmpMoviePlayerGui.addToPlaylist(*file);
			tmpMoviePlayerGui.exec(NULL, "urlplayback");
		}

		g_RCInput->getMsg_ms(&msg, &data, 10); // 1 sec
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
	
	delete fileBrowser;
}

void CTestMenu::testPlayAudioURL()
{
	neutrino_msg_t msg;
	neutrino_msg_data_t data;
		
	CFileBrowser * fileBrowser;
	
	fileBrowser = new CFileBrowser();
	
	CFileFilter fileFilter;
	
	fileFilter.addFilter("cdr");
	fileFilter.addFilter("mp3");
	fileFilter.addFilter("mpa");
	fileFilter.addFilter("mp2");
	fileFilter.addFilter("ogg");
	fileFilter.addFilter("wav");
	fileFilter.addFilter("flac");
	fileFilter.addFilter("aac");
	fileFilter.addFilter("dts");
	fileFilter.addFilter("m4a");
	
	fileBrowser->Multi_Select = false;
	fileBrowser->Dirs_Selectable = false;
	fileBrowser->Filter = &fileFilter;
	
	std::string Path_local = g_settings.network_nfs_audioplayerdir;

BROWSER:
	if (fileBrowser->exec(Path_local.c_str()))
	{
		Path_local = fileBrowser->getCurrentDir();
		
		CFile * file;
		
		if ((file = fileBrowser->getSelectedFile()) != NULL) 
		{
			CAudioPlayerGui tmpAudioPlayerGui;
			
			if (file->getType() == CFile::FILE_AUDIO)
			{
				CAudiofileExt audiofile(file->Name, file->getExtension());
				tmpAudioPlayerGui.addToPlaylist(audiofile);
				tmpAudioPlayerGui.exec(NULL, "urlplayback");
			}
		}

		g_RCInput->getMsg_ms(&msg, &data, 10); // 1 sec
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
	
	delete fileBrowser;
}

void CTestMenu::testShowPictureURL()
{
	neutrino_msg_t msg;
	neutrino_msg_data_t data;

	CFileBrowser * fileBrowser;
	
	fileBrowser = new CFileBrowser();
	
	CFileFilter fileFilter;
	
	fileFilter.addFilter("png");
	fileFilter.addFilter("bmp");
	fileFilter.addFilter("jpg");
	fileFilter.addFilter("jpeg");
	
	fileBrowser->Multi_Select    = false;
	fileBrowser->Dirs_Selectable = false;
	fileBrowser->Filter = &fileFilter;
	
	std::string Path_local = g_settings.network_nfs_audioplayerdir;

BROWSER:
	if (fileBrowser->exec(Path_local.c_str()))
	{
		Path_local = fileBrowser->getCurrentDir();
		
		CFile * file;
		
		if ((file = fileBrowser->getSelectedFile()) != NULL) 
		{
			CPictureViewerGui tmpPictureViewerGui;
			CPicture pic;
			struct stat statbuf;
			
			pic.Filename = file->Name;
			std::string tmp = file->Name.substr(file->Name.rfind('/') + 1);
			pic.Name = tmp.substr(0, tmp.rfind('.'));
			pic.Type = tmp.substr(tmp.rfind('.') + 1);
			
			if(stat(pic.Filename.c_str(), &statbuf) != 0)
				printf("stat error");
			pic.Date = statbuf.st_mtime;
							
			tmpPictureViewerGui.addToPlaylist(pic);
			tmpPictureViewerGui.exec(NULL, "urlplayback");
		}

		g_RCInput->getMsg_ms(&msg, &data, 10); // 1 sec
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
	
	delete fileBrowser;
}

void CTestMenu::testPlayMovieFolder()
{
	CMoviePlayerGui tmpMoviePlayerGui;
	
	CFileBrowser * fileBrowser;
	
	fileBrowser = new CFileBrowser();
	
	CFileFilter fileFilter;
	
	fileFilter.addFilter("ts");
	fileFilter.addFilter("mpg");
	fileFilter.addFilter("mpeg");
	fileFilter.addFilter("divx");
	fileFilter.addFilter("avi");
	fileFilter.addFilter("mkv");
	fileFilter.addFilter("asf");
	fileFilter.addFilter("aiff");
	fileFilter.addFilter("m2p");
	fileFilter.addFilter("mpv");
	fileFilter.addFilter("m2ts");
	fileFilter.addFilter("vob");
	fileFilter.addFilter("mp4");
	fileFilter.addFilter("mov");	
	fileFilter.addFilter("flv");	
	fileFilter.addFilter("dat");
	fileFilter.addFilter("trp");
	fileFilter.addFilter("vdr");
	fileFilter.addFilter("mts");
	fileFilter.addFilter("wmv");
	fileFilter.addFilter("wav");
	fileFilter.addFilter("flac");
	fileFilter.addFilter("mp3");
	fileFilter.addFilter("wma");
	fileFilter.addFilter("ogg");

	fileBrowser->Multi_Select = true;
	fileBrowser->Filter = &fileFilter;
	
	std::string Path_local = g_settings.network_nfs_moviedir;

BROWSER:
	if (fileBrowser->exec(Path_local.c_str()))
	{
		Path_local = fileBrowser->getCurrentDir();
		CFile file;
		CFileList::const_iterator files = fileBrowser->getSelectedFiles().begin();
		for(; files != fileBrowser->getSelectedFiles().end(); files++)
		{
			file.Name = files->Name;

			// fill file info
			file.Title = files->getFileName();
			file.Info1 = files->getFileName();	// IMDB
			//file.Info2 = files->getFileName(); 	// IMDB

			std::string fname = "";
			fname = files->Name;
			changeFileNameExt(fname, ".jpg");
						
			if(!access(fname.c_str(), F_OK) )
				file.Thumbnail = fname.c_str();
					
			tmpMoviePlayerGui.addToPlaylist(file);
		}
		
		tmpMoviePlayerGui.exec(NULL, "urlplayback");
		
		neutrino_msg_t msg;
		neutrino_msg_data_t data;

		g_RCInput->getMsg_ms(&msg, &data, 10);
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
	
	delete fileBrowser;
}

void CTestMenu::testPlayAudioFolder()
{
	neutrino_msg_t msg;
	neutrino_msg_data_t data;
		
	CFileBrowser * fileBrowser;

	CFileFilter fileFilter;
	
	CFileList filelist;
	
	fileFilter.addFilter("cdr");
	fileFilter.addFilter("mp3");
	fileFilter.addFilter("m2a");
	fileFilter.addFilter("mpa");
	fileFilter.addFilter("mp2");
	fileFilter.addFilter("ogg");
	fileFilter.addFilter("wav");
	fileFilter.addFilter("flac");
	fileFilter.addFilter("aac");
	fileFilter.addFilter("dts");
	fileFilter.addFilter("m4a");
	
	fileBrowser = new CFileBrowser();
	fileBrowser->Multi_Select = true;
	fileBrowser->Dirs_Selectable = false;
	fileBrowser->Filter = &fileFilter;
	
	std::string Path_local = g_settings.network_nfs_audioplayerdir;

BROWSER:
	if (fileBrowser->exec(Path_local.c_str()))
	{
		Path_local = fileBrowser->getCurrentDir();
		
		CAudioPlayerGui tmpAudioPlayerGui;
		CFileList::const_iterator files = fileBrowser->getSelectedFiles().begin();
		
		for(; files != fileBrowser->getSelectedFiles().end(); files++)
		{

			if ( (files->getExtension() == CFile::EXTENSION_CDR)
					||  (files->getExtension() == CFile::EXTENSION_MP3)
					||  (files->getExtension() == CFile::EXTENSION_WAV)
					||  (files->getExtension() == CFile::EXTENSION_FLAC)
			)
			{
				CAudiofileExt audiofile(files->Name, files->getExtension());
				tmpAudioPlayerGui.addToPlaylist(audiofile);
			}
		}
		
		tmpAudioPlayerGui.exec(NULL, "urlplayback");

		g_RCInput->getMsg_ms(&msg, &data, 10); // 1 sec
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
	
	delete fileBrowser;
}

void CTestMenu::testShowPictureFolder()
{
	neutrino_msg_t msg;
	neutrino_msg_data_t data;

	CFileBrowser * fileBrowser;
	
	CFileFilter fileFilter;
	
	CFileList filelist;
	int selected = 0;
	
	fileFilter.addFilter("png");
	fileFilter.addFilter("bmp");
	fileFilter.addFilter("jpg");
	fileFilter.addFilter("jpeg");
	
	fileBrowser = new CFileBrowser();
	fileBrowser->Multi_Select    = true;
	fileBrowser->Dirs_Selectable = true;
	fileBrowser->Filter = &fileFilter;
	
	std::string Path_local = g_settings.network_nfs_audioplayerdir;

BROWSER:
	if (fileBrowser->exec(Path_local.c_str()))
	{
		Path_local = fileBrowser->getCurrentDir();
		
		CPictureViewerGui tmpPictureViewerGui;
		CPicture pic;
		struct stat statbuf;
				
		CFileList::const_iterator files = fileBrowser->getSelectedFiles().begin();
		
		for(; files != fileBrowser->getSelectedFiles().end(); files++)
		{

			if (files->getType() == CFile::FILE_PICTURE)
			{
				pic.Filename = files->Name;
				std::string tmp = files->Name.substr(files->Name.rfind('/') + 1);
				pic.Name = tmp.substr(0, tmp.rfind('.'));
				pic.Type = tmp.substr(tmp.rfind('.') + 1);
			
				if(stat(pic.Filename.c_str(), &statbuf) != 0)
					printf("stat error");
				pic.Date = statbuf.st_mtime;
				
				tmpPictureViewerGui.addToPlaylist(pic);
			}
		}
		
		tmpPictureViewerGui.exec(NULL, "urlplayback");

		g_RCInput->getMsg_ms(&msg, &data, 10); // 1 sec
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
	
	delete fileBrowser;
}

void CTestMenu::testStartPlugin()
{
	g_PluginList->startPlugin("youtube");
}

void CTestMenu::testShowActuellEPG()
{
	std::string title = "testShowActuellEPG:";
	std::string buffer = "EPG Information: ";

	// get EPG
	CEPGData epgData;
	event_id_t epgid = 0;
			
	if(sectionsd_getActualEPGServiceKey(live_channel_id&0xFFFFFFFFFFFFULL, &epgData))
		epgid = epgData.eventID;

	if(epgid != 0) 
	{
		CShortEPGData epgdata;
				
		if(sectionsd_getEPGidShort(epgid, &epgdata)) 
		{
			title += g_Zapit->getChannelName(live_channel_id);
			title += ":";
			title += epgdata.title;

			buffer += epgdata.info1;
			buffer += "\n";
			buffer += epgdata.info2;
			
			InfoBox(title.c_str(), buffer.c_str());	// UTF-8
			
		}
	}

	title += getNowTimeStr("%d.%m.%Y %H:%M");
	//
	
	InfoBox(title.c_str(), buffer.c_str());	//
}

void CTestMenu::testChannelSelectWidget()
{
	CSelectChannelWidget * CSelectChannelWidgetHandler = new CSelectChannelWidget();
	CSelectChannelWidgetHandler->exec(NULL, "tv");
		
	//CSelectChannelWidget_TVChanID;
	//CSelectChannelWidget_TVChanName.c_str();
		
	delete CSelectChannelWidgetHandler;
	CSelectChannelWidgetHandler = NULL;
}

void CTestMenu::testBEChannelSelectWidget()
{	
#if 0	
	CBEChannelSelectWidget * channelSelectWidget = new CBEChannelSelectWidget("BEChannelSelectWidget", 1, CZapitClient::MODE_TV);

	channelSelectWidget->exec(this, "");
#endif

	CBEChannelWidget* channelWidget = new CBEChannelWidget("BEChannelSelectWidget", true);
	channelWidget->exec( this, "");
}

void CTestMenu::testAVSelectWidget()
{
	CAVPIDSelectWidget * AVSelectHandler = new CAVPIDSelectWidget();
	AVSelectHandler->exec(NULL, "");
		
	delete AVSelectHandler;
	AVSelectHandler = NULL;
}

void CTestMenu::testAudioSelectWidget()
{
	CAudioSelectMenuHandler * ASelectHandler = new CAudioSelectMenuHandler();
	ASelectHandler->exec(NULL, "");
	delete ASelectHandler;
	ASelectHandler = NULL;
}

void CTestMenu::testDVBSubSelectWidget()
{
	CDVBSubSelectMenuHandler * dvbSubSelectHandler = new CDVBSubSelectMenuHandler();
	dvbSubSelectHandler->exec(NULL, "");
	delete dvbSubSelectHandler;
	dvbSubSelectHandler = NULL;
}

void CTestMenu::testAlphaSetupWidget()
{
	CAlphaSetup * alphaSetup = new CAlphaSetup(LOCALE_COLORMENU_GTX_ALPHA, &g_settings.gtx_alpha);
	alphaSetup->exec(NULL, "");
	delete alphaSetup;
	alphaSetup = NULL;
}

void CTestMenu::testPSISetup()
{
	CPSISetup * psiSetup = new CPSISetup(LOCALE_VIDEOMENU_PSISETUP, &g_settings.contrast, &g_settings.saturation, &g_settings.brightness, &g_settings.tint);
	psiSetup->exec(NULL, "");
	delete psiSetup;
	psiSetup = NULL;
}

void CTestMenu::testRCLock()
{
	CRCLock * rcLock = new CRCLock();
	rcLock->exec(NULL, CRCLock::NO_USER_INPUT);
	delete rcLock;
	rcLock = NULL;
}

void CTestMenu::testSleepTimerWidget()
{
	CSleepTimerWidget * sleepTimerHandler = new CSleepTimerWidget();
	sleepTimerHandler->exec(NULL, "");
	delete sleepTimerHandler;
	sleepTimerHandler = NULL;
}

void CTestMenu::testMountGUI()
{
	CNFSMountGui * mountGUI = new CNFSMountGui();
	mountGUI->exec(NULL, "");
	delete mountGUI;
	mountGUI = NULL;
}

void CTestMenu::testUmountGUI()
{
	CNFSUmountGui * umountGUI = new CNFSUmountGui();
	umountGUI->exec(NULL, "");
	delete umountGUI;
	umountGUI = NULL;
}

void CTestMenu::testMountSmallMenu()
{
	CNFSSmallMenu * mountSmallMenu = new CNFSSmallMenu(true);
	mountSmallMenu->exec(NULL, "");
	delete mountSmallMenu;
	mountSmallMenu = NULL;
}

void CTestMenu::testVFDController()
{
	CVfdControler * vfdControllerHandler = new CVfdControler(LOCALE_LCDMENU_HEAD, NULL);
	vfdControllerHandler->exec(NULL, "");
	delete vfdControllerHandler;
	vfdControllerHandler = NULL;
}

void CTestMenu::testColorChooser()
{
	CColorChooser * colorChooserHandler = new CColorChooser(LOCALE_COLORMENU_BACKGROUND, &g_settings.menu_Head_red, &g_settings.menu_Head_green, &g_settings.menu_Head_blue, &g_settings.menu_Head_alpha, CNeutrinoApp::getInstance()->colorSetupNotifier);

	colorChooserHandler->exec(NULL, "");
	delete colorChooserHandler;
	colorChooserHandler = NULL;
}

void CTestMenu::testKeyChooser()
{
	CKeyChooserItem * keyChooser = new CKeyChooserItem("testing CKeyChooser", &g_settings.mb_truncate);

	keyChooser->exec(NULL, "");
	delete keyChooser;
	keyChooser = NULL;
}

void CTestMenu::testFrameBox()
{
	CSmartMenu * smartMenu = new CSmartMenu(LOCALE_MAINMENU_HEAD, NEUTRINO_ICON_BUTTON_SETUP);

	// tv
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_TVMODE, CNeutrinoApp::getInstance(), "tv", NEUTRINO_ICON_MENUITEM_TV), true);

	// radio
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_RADIOMODE, CNeutrinoApp::getInstance(), "radio", NEUTRINO_ICON_MENUITEM_RADIO));

	// webtv
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_WEBTVMODE, CNeutrinoApp::getInstance(), "webtv", NEUTRINO_ICON_MENUITEM_WEBTV));

#if defined (ENABLE_SCART)
	// scart
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_SCARTMODE, CNeutrinoApp::getInstance(), "scart", NEUTRINO_ICON_MENUITEM_SCART));
#endif

	// mediaplayer
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_MEDIAPLAYER, new CMediaPlayerMenu(), NULL, NEUTRINO_ICON_MENUITEM_MEDIAPLAYER));
	
	// main setting menu
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_SETTINGS, new CMainSetup(), NULL, NEUTRINO_ICON_MENUITEM_SETTINGS));

	// service
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_SERVICE, new CServiceSetup(), NULL, NEUTRINO_ICON_MENUITEM_SERVICE));
	
	// timerlist
	smartMenu->addItem(new CMenuFrameBox(LOCALE_TIMERLIST_NAME, new CTimerList, NULL, NEUTRINO_ICON_MENUITEM_TIMERLIST));
	
	// features
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_FEATURES, CNeutrinoApp::getInstance(), "features", NEUTRINO_ICON_MENUITEM_FEATURES));

	// power menu
	smartMenu->addItem(new CMenuFrameBox(LOCALE_MAINMENU_POWERMENU, new CPowerMenu(), NULL, NEUTRINO_ICON_MENUITEM_POWERMENU));

	//box info
	smartMenu->addItem( new CMenuFrameBox(LOCALE_DBOXINFO, new CDBoxInfoWidget, NULL, NEUTRINO_ICON_MENUITEM_BOXINFO));

	smartMenu->exec(NULL, "");
	smartMenu->hide();
	delete smartMenu;
	smartMenu = NULL;
}

void CTestMenu::testPluginsList()
{
	CPluginList * pluginList = new CPluginList( LOCALE_USERMENU_ITEM_PLUGINS);
	pluginList->exec(NULL, "");
	delete pluginList;
	pluginList = NULL;
}

void CTestMenu::testURIMovieBrowser()
{
	CMoviePlayerGui tmpMoviePlayerGui;
			
	CMovieBrowser * moviebrowser;
	std::string Path_local = g_settings.network_nfs_moviedir;
	
	moviebrowser = new CMovieBrowser();
	MI_MOVIE_INFO * p_movie_info;

	moviebrowser->setMode(MB_SHOW_FILES);
	
BROWSER:	
	if (moviebrowser->exec(Path_local.c_str())) 
	{
		// get the current path and file name
		Path_local = moviebrowser->getCurrentDir();

		// get the current file name
		CFile * file;

		if ((file = moviebrowser->getSelectedFile()) != NULL) 
		{
			// movieinfos
			p_movie_info = moviebrowser->getCurrentMovieInfo();
			
			file->Title = p_movie_info->epgTitle;
			file->Info1 = p_movie_info->epgInfo1;
			file->Info2 = p_movie_info->epgInfo2;
			file->Thumbnail = p_movie_info->tfile;
					
			tmpMoviePlayerGui.addToPlaylist(*file);
			tmpMoviePlayerGui.exec(NULL, "urlplayback");
		}
		
		neutrino_msg_t msg;
		neutrino_msg_data_t data;

		g_RCInput->getMsg_ms(&msg, &data, 10); // 1 sec
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
						
	delete moviebrowser;
}

void CTestMenu::testURIRecordBrowser()
{
	CMoviePlayerGui tmpMoviePlayerGui;
			
	CMovieBrowser * moviebrowser;
	std::string Path_local = g_settings.network_nfs_moviedir;
	
	moviebrowser = new CMovieBrowser();
	MI_MOVIE_INFO * p_movie_info;

	moviebrowser->setMode(MB_SHOW_RECORDS);
	
BROWSER:	
	if (moviebrowser->exec(Path_local.c_str())) 
	{
		// get the current path and file name
		Path_local = moviebrowser->getCurrentDir();

		// get the current file name
		CFile * file;

		if ((file = moviebrowser->getSelectedFile()) != NULL) 
		{
			// movieinfos
			p_movie_info = moviebrowser->getCurrentMovieInfo();
			
			file->Title = p_movie_info->epgTitle;
			file->Info1 = p_movie_info->epgInfo1;
			file->Info2 = p_movie_info->epgInfo2;
			file->Thumbnail = p_movie_info->tfile;
					
			tmpMoviePlayerGui.addToPlaylist(*file);
			tmpMoviePlayerGui.exec(NULL, "urlplayback");
		}
		
		neutrino_msg_t msg;
		neutrino_msg_data_t data;

		g_RCInput->getMsg_ms(&msg, &data, 10); // 1 sec
		
		if (msg != CRCInput::RC_home) 
		{
			goto BROWSER;
		}
	}
						
	delete moviebrowser;
}

void CTestMenu::testPlayMovieDir()
{
	//
	CFileFilter fileFilter;
	
	fileFilter.addFilter("ts");
	fileFilter.addFilter("mpg");
	fileFilter.addFilter("mpeg");
	fileFilter.addFilter("divx");
	fileFilter.addFilter("avi");
	fileFilter.addFilter("mkv");
	fileFilter.addFilter("asf");
	fileFilter.addFilter("aiff");
	fileFilter.addFilter("m2p");
	fileFilter.addFilter("mpv");
	fileFilter.addFilter("m2ts");
	fileFilter.addFilter("vob");
	fileFilter.addFilter("mp4");
	fileFilter.addFilter("mov");	
	fileFilter.addFilter("flv");	
	fileFilter.addFilter("dat");
	fileFilter.addFilter("trp");
	fileFilter.addFilter("vdr");
	fileFilter.addFilter("mts");
	fileFilter.addFilter("wmv");
	fileFilter.addFilter("wav");
	fileFilter.addFilter("flac");
	fileFilter.addFilter("mp3");
	fileFilter.addFilter("wma");
	fileFilter.addFilter("ogg");
	//

	CMoviePlayerGui tmpMoviePlayerGui;
	
	std::string Path_local = g_settings.network_nfs_moviedir;
	Path_local += "/";

	CFileList filelist;

	if(CFileHelpers::getInstance()->readDir(Path_local, &filelist, &fileFilter))
	{
		// filter them
		CFile file;
		CFileList::iterator files = filelist.begin();
		for(; files != filelist.end() ; files++)
		{
			file.Name = files->Name;

			// fill file info
			file.Title = files->getFileName();
			file.Info1 = files->getFileName();	// IMDB
			//file.Info2 = files->getFileName(); 	// IMDB

			std::string fname = "";
			fname = files->Name;
			changeFileNameExt(fname, ".jpg");
						
			if(!access(fname.c_str(), F_OK) )
				file.Thumbnail = fname.c_str();
	
			tmpMoviePlayerGui.addToPlaylist(file);
		}
		
		tmpMoviePlayerGui.exec(NULL, "urlplayback");
	}
}

int CTestMenu::exec(CMenuTarget* parent, const std::string& actionKey)
{
	dprintf(DEBUG_NORMAL, "\nCTestMenu::exec: actionKey:%s\n", actionKey.c_str());
	
	if(parent)
		hide();
	
	if(actionKey == "stringinput")
	{
		testCStringInput();
	}
	else if(actionKey == "stringinputsms")
	{
		testCStringInputSMS();
	}
	else if(actionKey == "pininput")
	{
		testCPINInput();
	}
	else if(actionKey == "ipinput")
	{
		testCIPInput();
	}
	else if(actionKey == "macinput")
	{
		testCMACInput();
	}
	else if(actionKey == "dateinput")
	{
		testCDateInput();
	}
	else if(actionKey == "timeinput")
	{
		testCTimeInput();
	}
	else if(actionKey == "intinput")
	{
		testCIntInput();
	}
	else if(actionKey == "infobox")
	{
		testCInfoBox();
	}
	else if(actionKey == "infoboxshowmsg")
	{
		testCInfoBoxShowMsg();
	}
	else if(actionKey == "infoboxinfobox")
	{
		testCInfoBoxInfoBox();
	}
	else if(actionKey == "messagebox")
	{
		testCMessageBox();
	}
	else if(actionKey == "messageboxinfomsg")
	{
		testCMessageBoxInfoMsg();
	}
	else if(actionKey == "messageboxerrormsg")
	{
		testCMessageBoxErrorMsg();
	}
	else if(actionKey == "hintbox")
	{
		testCHintBox();
	}
	else if(actionKey == "hintboxinfo")
	{
		testCHintBoxInfo();
	}
	else if(actionKey == "helpbox")
	{
		testCHelpBox();
	}
	else if(actionKey == "textbox")
	{
		testCTextBox();
	}
	else if(actionKey == "listframebox")
	{
		testCListFrameBox();
	}
	else if(actionKey == "listbox")
	{
		testCListBox();
	}
	else if(actionKey == "listboxdetails")
	{
		testCListBoxDetails();
	}
	else if(actionKey == "listboxdetailstitleinfo")
	{
		testCListBoxDetailsTitleInfo();
	}
	else if(actionKey == "progressbar")
	{
		testCProgressBar();
	}
	else if(actionKey == "progresswindow")
	{
		testCProgressWindow();
	}
	else if(actionKey == "buttons")
	{
		testCButtons();
	}
	else if(actionKey == "audioplayer")
	{
		testAudioPlayer();
	}
	else if(actionKey == "internetradio")
	{
		testInternetRadio();
	}
	else if(actionKey == "tsmoviebrowser")
	{
		testRecordBrowser();
	}
	else if(actionKey == "moviebrowser")
	{
		testMovieBrowser();
	}
	else if(actionKey == "fileplayback")
	{
		testFilePlayBack();
	}
	else if(actionKey == "pictureviewer")
	{
		testPictureViewer();
	}
	else if(actionKey == "upnpbrowser")
	{
		testUPNPBrowser();
	}
	else if(actionKey == "playmovieurl")
	{
		testPlayMovieURL();
	}
	else if(actionKey == "playaudiourl")
	{
		testPlayAudioURL();
	}
	else if(actionKey == "showpictureurl")
	{
		testShowPictureURL();
	}
	else if(actionKey == "playmoviefolder")
	{
		testPlayMovieFolder();
	}
	else if(actionKey == "playaudiofolder")
	{
		testPlayAudioFolder();
	}
	else if(actionKey == "showpicturefolder")
	{
		testShowPictureFolder();
	}
	else if(actionKey == "startplugin")
	{
		testStartPlugin();
	}
	else if(actionKey == "showepg")
	{
		testShowActuellEPG();
	}
	else if(actionKey == "channelselect")
	{
		testChannelSelectWidget();
	}
	else if(actionKey == "bechannelselect")
	{
		testBEChannelSelectWidget();
	}
	else if(actionKey == "avselect")
	{
		testAVSelectWidget();
	}
	else if(actionKey == "aselect")
	{
		testAudioSelectWidget();
	}
	else if(actionKey == "dvbsubselect")
	{
		testDVBSubSelectWidget();
	}
	else if(actionKey == "alphasetup")
	{
		testAlphaSetupWidget();
	}
	else if(actionKey == "psisetup")
	{
		testPSISetup();
	}
	else if(actionKey == "rclock")
	{
		testRCLock();
	}
	else if(actionKey == "sleeptimer")
	{
		testSleepTimerWidget();
	}
	else if(actionKey == "mountgui")
	{
		testMountGUI();
	}
	else if(actionKey == "umountgui")
	{
		testUmountGUI();
	}
	else if(actionKey == "mountsmallmenu")
	{
		testMountSmallMenu();
	}
	else if(actionKey == "vfdcontroller")
	{
		testVFDController();
	}
	else if(actionKey == "colorchooser")
	{
		testColorChooser();
	}
	else if(actionKey == "keychooser")
	{
		testKeyChooser();
	}
	else if(actionKey == "framebox")
	{
		testFrameBox();
	}
	else if(actionKey == "pluginslist")
	{
		testPluginsList();
	}
	else if(actionKey == "urimoviebrowser")
	{
		testURIMovieBrowser();
	}
	else if(actionKey == "urirecordbrowser")
	{
		testURIRecordBrowser();
	}
	else if(actionKey == "playmoviedir")
	{
		testPlayMovieDir();
	}
	
	return menu_return::RETURN_REPAINT;
}

void CTestMenu::showTestMenu()
{
	/// menue.cpp
	CMenuWidget * mainMenu = new CMenuWidget("testMenu", NEUTRINO_ICON_BUTTON_SETUP);
	
	mainMenu->addItem(new CMenuForwarder("CStringInput", true, NULL, this, "stringinput"));
	mainMenu->addItem(new CMenuForwarder("CStringInputSMS", true, NULL, this, "stringinputsms"));
	mainMenu->addItem(new CMenuForwarder("CPINInput", true, NULL, this, "pininput"));
	mainMenu->addItem(new CMenuForwarder("CIPInput", true, NULL, this, "ipinput"));
	mainMenu->addItem(new CMenuForwarder("CMACInput", true, NULL, this, "macinput"));
	mainMenu->addItem(new CMenuForwarder("CDateInput", true, NULL, this, "dateinput"));
	mainMenu->addItem(new CMenuForwarder("CTimeInput", true, NULL, this, "timeinput"));
	mainMenu->addItem(new CMenuForwarder("CIntInput", true, NULL, this, "intinput"));
	mainMenu->addItem(new CMenuForwarder("CInfoBox", true, NULL, this, "infobox"));
	mainMenu->addItem(new CMenuForwarder("CInfoBoxShowMsg", true, NULL, this, "infoboxshowmsg"));
	mainMenu->addItem(new CMenuForwarder("CInfoBoxInfoBox", true, NULL, this, "infoboxinfobox"));
	mainMenu->addItem(new CMenuForwarder("CMessageBox", true, NULL, this, "messagebox"));
	mainMenu->addItem(new CMenuForwarder("CMessageBoxInfoMsg", true, NULL, this, "messageboxinfomsg"));
	mainMenu->addItem(new CMenuForwarder("CMessageBoxErrorMsg", true, NULL, this, "messageboxerrormsg"));
	mainMenu->addItem(new CMenuForwarder("CHintBox", true, NULL, this, "hintbox"));
	mainMenu->addItem(new CMenuForwarder("CHintBoxInfo", true, NULL, this, "hintboxinfo"));
	mainMenu->addItem(new CMenuForwarder("CHelpBox", true, NULL, this, "helpbox"));
	mainMenu->addItem(new CMenuForwarder("CTextBox", true, NULL, this, "textbox"));
	mainMenu->addItem(new CMenuForwarder("CListFrameBox", true, NULL, this, "listframebox"));
	mainMenu->addItem(new CMenuForwarder("CListBox", true, NULL, this, "listbox"));
	mainMenu->addItem(new CMenuForwarder("CListBoxInfoDetails", true, NULL, this, "listboxdetails"));
	mainMenu->addItem(new CMenuForwarder("CListBoxDetailsTitleInfo", true, NULL, this, "listboxdetailstitleinfo"));
	mainMenu->addItem(new CMenuForwarder("CProgressBar", true, NULL, this, "progressbar"));
	mainMenu->addItem(new CMenuForwarder("CProgressWindow", true, NULL, this, "progresswindow"));
	mainMenu->addItem(new CMenuForwarder("CButtons", true, NULL, this, "buttons"));

	mainMenu->addItem( new CMenuSeparator(CMenuSeparator::LINE) );
	mainMenu->addItem(new CMenuForwarder("AudioPlayer", true, NULL, this, "audioplayer"));
	mainMenu->addItem(new CMenuForwarder("InternetRadio", true, NULL, this, "internetradio"));
	mainMenu->addItem(new CMenuForwarder("TSMovieBrowser", true, NULL, this, "tsmoviebrowser"));
	mainMenu->addItem(new CMenuForwarder("MovieBrowser", true, NULL, this, "moviebrowser"));
	mainMenu->addItem(new CMenuForwarder("FilePlayBack", true, NULL, this, "fileplayback"));
	mainMenu->addItem(new CMenuForwarder("PictureViewer", true, NULL, this, "pictureviewer"));
	mainMenu->addItem(new CMenuForwarder("UPNPBrowser", true, NULL, this, "upnpbrowser"));

	mainMenu->addItem( new CMenuSeparator(CMenuSeparator::LINE) );
	mainMenu->addItem(new CMenuForwarder("PlayMovieURL", true, NULL, this, "playmovieurl"));
	mainMenu->addItem(new CMenuForwarder("PlayAudioURL", true, NULL, this, "playaudiourl"));
	mainMenu->addItem(new CMenuForwarder("ShowPictureURL", true, NULL, this, "showpictureurl"));
	mainMenu->addItem(new CMenuForwarder("PlayMovieFolder", true, NULL, this, "playmoviefolder"));
	mainMenu->addItem(new CMenuForwarder("PlayAudioFolder", true, NULL, this, "playaudiofolder"));
	mainMenu->addItem(new CMenuForwarder("ShowPictureFolder", true, NULL, this, "showpicturefolder"));

	mainMenu->addItem( new CMenuSeparator(CMenuSeparator::LINE) );
	mainMenu->addItem(new CMenuForwarder("StartPlugin(e.g: youtube)", true, NULL, this, "startplugin"));

	mainMenu->addItem( new CMenuSeparator(CMenuSeparator::LINE) );
	mainMenu->addItem(new CMenuForwarder("ShowActuellEPG", true, NULL, this, "showepg"));
	mainMenu->addItem(new CMenuForwarder("ChannelSelectWidget", true, NULL, this, "channelselect"));
	mainMenu->addItem(new CMenuForwarder("BEChannelSelectWidget", true, NULL, this, "bechannelselect"));
	mainMenu->addItem(new CMenuForwarder("AudioVideoSelectWidget", true, NULL, this, "avselect"));
	mainMenu->addItem(new CMenuForwarder("AudioSelectWidget", true, NULL, this, "aselect"));
	mainMenu->addItem(new CMenuForwarder("DVBSubSelectWidget", true, NULL, this, "dvbsubselect"));
	mainMenu->addItem(new CMenuForwarder("AlphaSetup", true, NULL, this, "alphasetup"));
	mainMenu->addItem(new CMenuForwarder("PSISetup", true, NULL, this, "psisetup"));
	mainMenu->addItem(new CMenuForwarder("RCLock", true, NULL, this, "rclock"));
	mainMenu->addItem(new CMenuForwarder("SleepTimerWidget", true, NULL, this, "sleeptimer"));
	mainMenu->addItem(new CMenuForwarder("MountGUI", true, NULL, this, "mountgui"));
	mainMenu->addItem(new CMenuForwarder("UmountGUI", true, NULL, this, "umountgui"));
	mainMenu->addItem(new CMenuForwarder("MountSmallMenu", true, NULL, this, "mountsmallmenu"));
	mainMenu->addItem(new CMenuForwarder("VFDController", true, NULL, this, "vfdcontroller"));
	mainMenu->addItem(new CMenuForwarder("ColorChooser", true, NULL, this, "colorchooser"));
	mainMenu->addItem(new CMenuForwarder("KeyChooser", true, NULL, this, "keychooser"));

	mainMenu->addItem( new CMenuSeparator(CMenuSeparator::LINE) );
	mainMenu->addItem(new CMenuForwarder("FrameBox", true, NULL, this, "framebox"));
	mainMenu->addItem(new CMenuForwarder("PluginsList", true, NULL, this, "pluginslist"));
	mainMenu->addItem(new CMenuForwarder("URIMovieBrowser", true, NULL, this, "urimoviebrowser"));
	mainMenu->addItem(new CMenuForwarder("URIRecordBrowser", true, NULL, this, "urirecordbrowser"));
	mainMenu->addItem(new CMenuForwarder("PlayMovieDir(without Browser)", true, NULL, this, "playmoviedir"));
	
	mainMenu->exec(NULL, "");
	mainMenu->hide();
	delete mainMenu;
}

void plugin_init(void)
{
	dprintf(DEBUG_NORMAL, "test: plugin_init\n");
}

void plugin_del(void)
{
	dprintf(DEBUG_NORMAL, "test: plugin_del\n");
}

void plugin_exec(void)
{
	CTestMenu* testMenu = new CTestMenu();
	
	testMenu->showTestMenu();
	
	delete testMenu;
}

