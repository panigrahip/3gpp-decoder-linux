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

#include "tsharkdecoder.h"
#include <string>

using namespace std;

TSharkDecoder::TSharkDecoder()
{

}

TSharkDecoder::~TSharkDecoder()
{

}

/* Decoding starts here
 */

void TSharkDecoder::startDecoder(QString strEncodedData, QString strProtocol)
{
    QString strData;    
    strData = preformatData(strEncodedData);    
    formatFiletext2pcap(strData);
    callText2pacp();
    callTshark(strProtocol);
    cleanOutput();
}

/* Make the incoming packets in HEX format.
 * The packets are encoded in this format:
 * ab - ab
 * a - 0a
 * abcd - ab cd
 */

QString TSharkDecoder::preformatData(QString strEncodedData){

    QString strReturnData;
    QStringList strListData;

    strListData = strEncodedData.split(" ");
    for(int i = 0; i < strListData.length(); i++ )
    {
        if(strListData[i].length() == 2)
        {
            strReturnData.append(" ");
            strReturnData.append(strListData[i]);
        }
        else if(strListData[i].length() == 1)
        {
            strReturnData.append(" 0");
            strReturnData.append(strListData[i]);
        }
        else if(strListData[i].length() > 2)
        {
            for(int j = 0; j < strListData[i].length(); j = j+2)
            {
                QStringRef strTempData = strListData[i].midRef(j, 2);
                strReturnData.append(" ");
                strReturnData.append(strTempData);
            }

        }
    }
    return strReturnData;
}



/*Create a Textfile which text2pcap can understand.
 * 0000 are added to the beginning of the HEX data
 * to make it text2pacp type
*/

void TSharkDecoder::formatFiletext2pcap(QString strData)
{
    QFile textFile("textdata.txt");
    if (textFile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&textFile);
        stream << "0000";
        stream <<strData;
        qDebug() << strData;
    }
}

/* Make a PCAP file from the textdata.
 * Function calls text2pack.exe from wireshark folder.
 */

void TSharkDecoder::callText2pacp()
{
    QString command= "text2pcap -q -l 147 textdata.txt decode_temp.pcap";
    system(qPrintable(command));
    qDebug() << command;
}

/* Call Tshark to decode the PCAP file.
 * RRC messages are decoded directly
 * NAS messages embeded are also parsed by Tshark.
 */

void TSharkDecoder::callTshark(QString strProtocol)
{
    //tshark -o "uat:user_dlts:\"User 0 (DLT=147)\",\"LTE-RRC.BCCH.BCH\",\"0\",\"\",\"0\",\"\"" -r decode_temp.pcap  -V > decode_output_temp.txt
    //tshark -o \"uat:user_dlts:\\\"User 0 (DLT=147)\\\",\\\"

    QString command;
        //command = command.append(strTsharkPath);
        command = command.append("tshark -o \"uat:user_dlts:\\\"User 0 (DLT=147)\\\",\\\"");
        command = command.append(strProtocol);
        command = command.append("\\\",\\\"0\\\",\\\"\\\",\\\"0\\\",\\\"\\\"\" -r decode_temp.pcap\  -V > decode_output_temp.txt");
        qDebug() << command;
        system(qPrintable(command));
        system("rm textdata.txt decode_temp.pcap");
}

/* After decode the first 15 lines are useless data for us.
 * These lines can be removed for a clean presentation
 */

void TSharkDecoder::cleanOutput()
{
    QFile f("decode_output_temp.txt");
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString s;
        QTextStream t(&f);
        int i = 0;
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(i>=15)
                s.append(line + "\n");
            i++;
        }
        f.resize(0);
        t << s;
        f.close();
    }
}
