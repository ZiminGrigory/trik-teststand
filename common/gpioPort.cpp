/* Copyright 2014 CyberTech Labs Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#include "gpioPort.h"

#include <QtCore/QDebug>
#include <QtCore/QByteArray>

GpioPort::GpioPort(int number, const QString &path, QObject *parent)
	: QObject(parent)
	, mNumber(number)
	, mDirectionFile(path + "direction")
	, mValueFile(path + "value")
{
	if (!mDirectionFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Unbuffered | QIODevice::Text)) {
		qDebug() << "Can't open " << mDirectionFile.fileName();
	}
}

GpioPort::~GpioPort()
{
	mDirectionFile.close();
}

int GpioPort::number() const
{
	return mNumber;
}

void GpioPort::setValue(int value)
{
	mDirectionFile.write("out");
	mDirectionFile.flush();

	if (!mValueFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Unbuffered | QIODevice::Text)) {
		qDebug() << "Can't open " << mValueFile.fileName();
	} else {
		mValueFile.write(QByteArray::number(value));
		mValueFile.close();
	}
}

int GpioPort::getValue()
{
	mDirectionFile.write("in");
	mDirectionFile.flush();

	int value = -1;

	if (!mValueFile.open(QIODevice::ReadOnly | QIODevice::Unbuffered | QIODevice::Text)) {
		qDebug() << "Can't open " << mValueFile.fileName();
	} else {
		value = mValueFile.readAll().toInt();
		mValueFile.close();
	}

	return value;
}
