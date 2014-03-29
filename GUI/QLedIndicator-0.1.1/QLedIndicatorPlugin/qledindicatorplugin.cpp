/***************************************************************************
 *   Copyright (C) 2010 by Tn                                              *
 *   thenobody@poczta.fm                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "qledindicatorplugin.h"
#include "../qledindicator.h"

 #include <QtPlugin>

 QLedIndicatorPlugin:: QLedIndicatorPlugin(QObject *parent) : QObject(parent)
 {
     initialized = false;
 }

 void QLedIndicatorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
 {
     if (initialized)
         return;

     initialized = true;
 }

 bool QLedIndicatorPlugin::isInitialized() const
 {
     return initialized;
 }

 QWidget *QLedIndicatorPlugin::createWidget(QWidget *parent)
 {
     return new QLedIndicator(parent);
 }

 QString QLedIndicatorPlugin::name() const
 {
     return "QLedIndicator";
 }

 QString QLedIndicatorPlugin::group() const
 {
     return "Tn's Indicators";
 }

 QIcon QLedIndicatorPlugin::icon() const
 {
     return QIcon();
 }

 QString QLedIndicatorPlugin::toolTip() const
 {
     return "";
 }

 QString QLedIndicatorPlugin::whatsThis() const
 {
     return "";
 }

 bool QLedIndicatorPlugin::isContainer() const
 {
     return false;
 }

 QString QLedIndicatorPlugin::domXml() const
 {
     return "<ui language=\"c++\">\n"
                "<widget class=\"QLedIndicator\" name=\"ledIndicator\">\n"
                " <property name=\"geometry\">\n"
                "  <rect>\n"
                "   <x>0</x>\n"
                "   <y>0</y>\n"
                "   <width>100</width>\n"
                "   <height>100</height>\n"
                "  </rect>\n"
                " </property>\n"
                " <property name=\"toolTip\" >\n"
                "  <string>Led indicator/button</string>\n"
                " </property>\n"
                " <property name=\"whatsThis\" >\n"
                "  <string>Led indicator/button</string>\n"
                " </property>\n"
                "</widget>\n"
            "</ui>\n";
 }

 QString QLedIndicatorPlugin::includeFile() const
 {
     return "qledindicator.h";
 }

 //Q_EXPORT_PLUGIN2(customwidgetplugin, QLedIndicatorPlugin)
