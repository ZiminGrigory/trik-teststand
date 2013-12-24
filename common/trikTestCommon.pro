# Copyright 2013 Roman Kurbatov
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

QT += core gui

TARGET = trikTestCommon
TEMPLATE = lib

QMAKE_LIBS += -lusb-1.0

CONFIG(debug, debug | release) {
	CONFIGURATION = debug
} else {
	CONFIGURATION = release
}

DESTDIR = ../build/$$CONFIGURATION

OBJECTS_DIR = .build/$$CONFIGURATION/obj
MOC_DIR = .build/$$CONFIGURATION/moc

DEFINES += TRIKTESTCOMMON_LIBRARY

SOURCES += \
	usbCommunicator.cpp \
	yesNoBox.cpp \
	messageBox.cpp

HEADERS += \
	usbCommunicator.h \
	yesNoBox.h \
	testInterface.h \
	messageBox.h
