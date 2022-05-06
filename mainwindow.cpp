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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tsharkdecoder.h"
#include "umtsrlcdecoder.h"
#include "aboutdialog.h"
#include "helpdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 3;

    move ( x, y );
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    on_radioButtonLte_toggled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonDecode_clicked()
{
    QString encoded_pdu;
    QString protocol_selected;
    int pdu_length = 0;
    QMessageBox* message_box 	= new QMessageBox();    
    encoded_pdu = ui->lineEditData->text();
    protocol_selected = ui->comboBoxProtocol->currentText();
    pdu_length = encoded_pdu.length();
    if(pdu_length == 0)
    {
        message_box->setText("Enter a HEX string to decode");
        message_box->setWindowTitle("Error...");
        message_box->show();
    }
    else
    {
        if(protocol_selected != NULL)
        {
            if(protocol_selected.contains("RLC"))
            {
                encoded_pdu = encoded_pdu.remove(" ");
                encoded_pdu = encoded_pdu.remove("\n");
                if((encoded_pdu.length()%2) != 0)
                {
                    message_box->setText("Check entered data: RLC PDUs are octect aligned.");
                }
                else
                {
                    if(ui->radioButtonUmts->isChecked())
                    {
                        UmtsRlcDecoder* umts_rlc_decoder = new UmtsRlcDecoder();
                        umts_rlc_decoder->start_decoder(encoded_pdu, protocol_selected);
                    }
                }
            }
            else
            {
                //Decode as RRC with TShark
                TSharkDecoder* tshark_decoder = new TSharkDecoder();
                if(protocol_selected == "NAS")
                {
                    protocol_selected = "gsm_a_dtap";
                }
                tshark_decoder->startDecoder(encoded_pdu, protocol_selected);
            }
            readfile();
        }
    }
}

void MainWindow::readfile(){
    QString filename = "decode_output_temp.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "No files found "<<filename;
    }else{
        qDebug() << filename<<" File read sucess...";
    }
    QString line;
    ui->textEditDecoded->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->textEditDecoded->setText(ui->textEditDecoded->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }    
    file.close();

    system("rm decode_output_temp.txt");
}

void MainWindow::on_radioButtonGsm_toggled(bool checked)
{
    if(checked)
    {
        ui->comboBoxProtocol->clear();
         QStringList strProtocols;
         strProtocols.append("GAN.TCP");
         strProtocols.append("GAN.UDP");
         strProtocols.append("LLC");
         strProtocols.append("NAS");
         strProtocols.append("RR");
         strProtocols.append("GSM_A_CCCH");
         strProtocols.append("GSM_A_SACCH");
         strProtocols.append("SNDCP");
         strProtocols.append("SNDCPXID");
         ui->comboBoxProtocol->addItems(strProtocols);     
    }
}

void MainWindow::on_radioButtonUmts_toggled(bool checked)
{
    if(checked)
    {
        ui->comboBoxProtocol->clear();
        QStringList strProtocols;
        strProtocols.append("RLC-AM");
        strProtocols.append("RLC-UM");
        strProtocols.append("NAS");
        strProtocols.append("RRC.BCCH.BCH");
        strProtocols.append("RRC.BCCH.FACH");
        strProtocols.append("RRC.DL.CCCH");
        strProtocols.append("RRC.DL.DCCH");
        strProtocols.append("RRC.DL.SHCCH");
        strProtocols.append("RRC.MCCH");
        strProtocols.append("RRC.MSCH");
        strProtocols.append("RRC.PCCH");
        strProtocols.append("RRC.SI.MIB");
        strProtocols.append("RRC.SI.SB1");
        strProtocols.append("RRC.SI.SB2");
        strProtocols.append("RRC.SI.SIB1");
        strProtocols.append("RRC.SI.SIB10");
        strProtocols.append("RRC.SI.SIB11");
        strProtocols.append("RRC.SI.SIB11bis");
        strProtocols.append("RRC.SI.SIB12");
        strProtocols.append("RRC.SI.SIB13");
        strProtocols.append("RRC.SI.SIB13-1");
        strProtocols.append("RRC.SI.SIB13-2");
        strProtocols.append("RRC.SI.SIB13-3");
        strProtocols.append("RRC.SI.SIB13-4");
        strProtocols.append("RRC.SI.SIB14");
        strProtocols.append("RRC.SI.SIB15");
        strProtocols.append("RRC.SI.SIB15bis");
        strProtocols.append("RRC.SI.SIB15-1");
        strProtocols.append("RRC.SI.SIB15-1bis");
        strProtocols.append("RRC.SI.SIB15-2");
        strProtocols.append("RRC.SI.SIB15-2bis");
        strProtocols.append("RRC.SI.SIB15-3");
        strProtocols.append("RRC.SI.SIB15-3bis");
        strProtocols.append("RRC.SI.SIB15-4");
        strProtocols.append("RRC.SI.SIB15-5");
        strProtocols.append("RRC.SI.SIB15-6");
        strProtocols.append("RRC.SI.SIB15-7");
        strProtocols.append("RRC.SI.SIB15-8");
        strProtocols.append("RRC.SI.SIB18");
        strProtocols.append("RRC.SI.SIB17");
        strProtocols.append("RRC.SI.SIB18");
        strProtocols.append("RRC.SI.SIB2");
        strProtocols.append("RRC.SI.SIB3");
        strProtocols.append("RRC.SI.SIB4");
        strProtocols.append("RRC.SI.SIB5");
        strProtocols.append("RRC.SI.SIB5bis");
        strProtocols.append("RRC.SI.SIB6");
        strProtocols.append("RRC.SI.SIB7");
        strProtocols.append("RRC.SI.SIB8");
        strProtocols.append("RRC.SI.SIB9");
        strProtocols.append("RRC.UL.CCCH");
        strProtocols.append("RRC.UL.DCCH");
        strProtocols.append("RRC.UL.SHCCH");
        ui->comboBoxProtocol->addItems(strProtocols);
    }
}


void MainWindow::on_radioButtonLte_toggled(bool checked)
{
    if(checked)
    {
        ui->comboBoxProtocol->clear();
        QStringList strProtocols;
        strProtocols.append("LTE-RRC.BCCH.BCH");
        strProtocols.append("LTE-RRC.BCCH.DL.SCH");
        strProtocols.append("LTE-RRC.DL.CCCH");
        strProtocols.append("LTE-RRC.DL.DCCH");
        strProtocols.append("LTE-RRC.PCCH");
        strProtocols.append("LTE-RRC.UL.CCCH");
        strProtocols.append("LTE-RRC.UL.DCCH");
        strProtocols.append("NAS-EPS");
        ui->comboBoxProtocol->addItems(strProtocols);
    }
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->textEditDecoded->clear();
    ui->lineEditData->clear();
}

void MainWindow::on_action_Exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_About_Decoder_triggered()
{
    AboutDialog about;
    about.setModal(true);
    about.exec();
}

void MainWindow::on_action_Support_triggered()
{
    HelpDialog help;
    help.setModal(true);
    help.exec();
}
