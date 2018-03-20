/* This file is part of 3GPP Decoder project.
 * Copyright (C) 2015  Prashant Panigrahi prashant@3glteinfo.com
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TSHARKDECODER_H
#define TSHARKDECODER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringRef>
#include <QDebug>
#include <QProcess>


class TSharkDecoder
{
public:
    TSharkDecoder();
    ~TSharkDecoder();
    void startDecoder(QString strEncodedData, QString strProtocol);
protected:

private:
    void formatFiletext2pcap(QString strData);
    QString preformatData(QString strEncodedData);
    void callText2pacp();
    void callTshark(QString strProtocol);
    void cleanOutput();
};

#endif // TSHARKDECODER_H
