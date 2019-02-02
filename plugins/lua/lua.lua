print("lua: Hello World")

neutrino = require 'neutrino'

-- messagebox
mBox = neutrino.CMessageBox("CMessageBox: lua","first test\ntesting CMessageBox\ndas ist alles ;-)")
mBox:exec(-1)

-- helpbox
--[[
hbox = neutrino.CHelpBox()
hbox:addLine("neutrino: lua")
hbox:addSeparator(hbox)
hbox:addLine("first test")
hbox:addLine("testing CHelpBox\ndas ist alles ;-)")
hbox:show("CHelpBox: lua")
]]

-- filebrowser
--[[
fbox= neutrino.CFileBrowser('/')
fbox:exec('/')
]]

-- headers
--[[
head = neutrino.CHeaders()
head:paintHead(150,10,550,35,neutrino.NEUTRINO_ICON_MP3,"test", true,0,null,false)
head:paintFoot(150, 570,550,35,550)
]]

-- window
--[[
w = neutrino.CWindow(150,45,550,525)
w:paint()
]]

-- scrollbar
--[[
sb = neutrino.CScrollBar()
sb:paint(150,45,525,10,1)
]]

-- itemsdetailsline
--[[
il = neutrino.CItems2DetailsLine()
il:paint(150,10,550,615,80,35,30,1)
]]

-- listboxEntry
--[[
listbox = neutrino.ClistBoxEntry(150,10,550,615)
listbox:setTitle("test", neutrino.NEUTRINO_ICON_MOVIE)
listbox:enablePaintHead()
listbox:enablePaintDate()
listbox:enablePaintFoot()
listbox:paint()
]]

-- hintbox
--[[
hint = neutrino.CHintBox("neutrino: lua","first test\ntesting CHintBox\ndas ist alles ;-)")
hint:exec()
]]

-- infobox
--[[
info = neutrino.CInfoBox("first test\ntesting CHintBox\ndas ist alles ;-)")
info:exec()
]]

-- framebuffer
--[[
frame = neutrino.CFrameBuffer()
frame:paintBackground()
]]

-- listbox
--listbox = neutrino.ClistBox("test", neutrino.NEUTRINO_ICON_MOVIE)
--listbox:enablePaintDate()
--listbox:addWidget(neutrino.WIDGET_CLASSIC)
--listbox:addWidget(neutrino.WIDGET_FRAME)
--listbox:enableWidgetChange()
--listbox:exec(null, "")

-- menuwidget
--[[
listbox = neutrino.CMenuWidget("test", neutrino.NEUTRINO_ICON_MOVIE)
listbox:enableWidgetChange()
listbox:exec(null, "")
]]

-- playback
--[[
playback = neutrino.cPlayback()
playback:Close()
playback:Open()
playback:Start("/home/mohousch/Music/AUD-20160209-WA0000.mp3")
playback:Play()
]]

-- audioplayergui
--[[
aplay = neutrino.CAudioPlayerGui()
aplay:addToPlaylist('/home/mohousch/Music/AUD-20160209-WA0000.mp3')
aplay:exec(null,"")
]]

-- movieplayergui
--[[
mplay=neutrino.CMoviePlayerGui()
mplay:addToPlaylist('/home/mohousch/Videos/ProSieben_20150619_201430.ts')
mplay:exec(null,"")
]]

-- pictureviewergui
--[[
pic=neutrino.CPictureViewerGui()
pic:addToPlaylist("/home/mohousch/funart.png")
pic:exec(null,"")
]]







