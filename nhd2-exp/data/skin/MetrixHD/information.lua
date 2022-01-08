-- information

local selected = 0

-- main
function main()
	local ret = neutrino.RETURN_REPAINT
	
	local fb = neutrino.CFrameBuffer_getInstance()
	local box = neutrino.CBox()
	
	box.iX = fb:getScreenX()
	box.iY = fb:getScreenY()
	box.iWidth = fb:getScreenWidth()
	box.iHeight = fb:getScreenHeight()
	
	local m = neutrino.CWidget(box)
	local w = neutrino.CWindow(box.iX + 60, box.iY + 50, box.iWidth/2 - 120, box.iHeight - 100)
	w:setColor(neutrino.convertSetupColor2Color(15,15,15,0))
	
	local w2 = neutrino.CWindow(box.iX + box.iWidth/2, box.iY + 50, box.iWidth/2, box.iHeight/2)
	w2:setColor(neutrino.convertSetupColor2Color(0,25,80,20))
	
	-- title
	title = neutrino.CCLabel()
	title:setText("Information");
	title:setPosition(box.iX + box.iWidth/2, box.iY + 50, box.iWidth/2, 50);
	title:setHAlign(neutrino.CC_ALIGN_CENTER)
	
	w2:addCCItem(title)
	
	-- logo
	logo = neutrino.CCImage(neutrino.CONFIGDIR .. "/skin/MetrixHD/picon_default.png")
	logo:setPosition(box.iX + box.iWidth/2, box.iY + 50 + 50 + 20, box.iWidth/2, 240)
	
	w2:addCCItem(logo)
	
	-- date
	local dateBox = neutrino.CWindow(box.iX + box.iWidth/2, box.iY + 50 + box.iHeight/2 + 50, box.iWidth/2, (box.iHeight/2 - 150)/2)
	dateBox:setColor(neutrino.convertSetupColor2Color(15,15,15,15))
	
	date = neutrino.CCTime(box.iX + box.iWidth/2, box.iY + 50 + box.iHeight/2 + 50, box.iWidth/2, (box.iHeight/2 - 150)/2)
	date:setFormat("%A %d.%m.%Y")
	
	dateBox:addCCItem(date)
	
	-- time
	local timeBox = neutrino.CWindow(box.iX + box.iWidth/2, box.iY + 50 + box.iHeight/2 + 50 + (box.iHeight/2 - 150)/2, box.iWidth/2, (box.iHeight/2 - 150)/2)
	timeBox:setColor(neutrino.convertSetupColor2Color(15,15,15,15))
	timeBox:enableRepaint()
	
	time = neutrino.CCTime(box.iX + box.iWidth/2, box.iY + 50 + box.iHeight/2 + 50 + (box.iHeight/2 - 150)/2, box.iWidth/2, (box.iHeight/2 - 150)/2)
	time:setFormat("%H:%M:%S")
	time:enableRepaint()
	
	timeBox:addCCItem(time)
	
	local list = neutrino.ClistBox(box.iX + 50, box.iY + 60, box.iWidth/2 - 100, box.iHeight - 120)
	list:paintMainFrame(false)
	
	item1 = neutrino.ClistBoxItem(neutrino.LOCALE_STREAMINFO_HEAD)
	item1:setItemIcon(neutrino.NEUTRINO_ICON_MENUITEM_SLEEPTIMER)
	item1:setActionKey(neutrino.CStreamInfo2Handler(), "")
	item1:set2lines()

	item2 = neutrino.ClistBoxItem(neutrino.LOCALE_DBOXINFO)
	item2:setItemIcon(neutrino.NEUTRINO_ICON_MENUITEM_RESTART)
	item2:setActionKey(neutrino.CDBoxInfoWidget(), "")
	item2:set2lines()

	item3 = neutrino.ClistBoxItem(neutrino.LOCALE_SERVICEMENU_IMAGEINFO)
	item3:setItemIcon(neutrino.NEUTRINO_ICON_MENUITEM_STANDBY)
	item3:setActionKey(neutrino.CImageInfo(), "")
	item3:set2lines()

	list:addItem(item1)
	list:addItem(item2)
	list:addItem(item3)
	list:integratePlugins(2, 0, true, neutrino.MODE_MENU, neutrino.WIDGET_TYPE_CLASSIC, true);
	
	m:addItem(w)
	m:addItem(dateBox)
	m:addItem(timeBox)
	m:addItem(list)
	m:addItem(w2)

	if selected < 0 then
		selected = 0
	end

	list:setSelected(selected)

	ret = m:exec(None, "")
	
	selected = list:getSelected()
	
	if m:getExitPressed() ~= true and ret == neutrino.RETURN_REPAINT then
		main()
	end

	return ret
end

main()




