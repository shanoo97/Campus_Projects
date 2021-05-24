# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(903, 752)
        MainWindow.setAutoFillBackground(False)
        MainWindow.setStyleSheet("background-color: rgb(43, 43, 43);")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.td_server_response = QtWidgets.QTextBrowser(self.centralwidget)
        self.td_server_response.setGeometry(QtCore.QRect(370, 170, 511, 541))
        self.td_server_response.setStyleSheet("\n"
"background-color: rgb(255, 255, 255);")
        self.td_server_response.setObjectName("td_server_response")
        self.cb_show_password = QtWidgets.QCheckBox(self.centralwidget)
        self.cb_show_password.setGeometry(QtCore.QRect(600, 100, 101, 16))
        self.cb_show_password.setStyleSheet("color: rgb(255, 255, 255);")
        self.cb_show_password.setObjectName("cb_show_password")
        self.btn_connect = QtWidgets.QPushButton(self.centralwidget)
        self.btn_connect.setGeometry(QtCore.QRect(740, 70, 75, 23))
        self.btn_connect.setStyleSheet("background-color: rgb(170, 170, 170);")
        self.btn_connect.setObjectName("btn_connect")
        self.le_ftp_server_address = QtWidgets.QLineEdit(self.centralwidget)
        self.le_ftp_server_address.setGeometry(QtCore.QRect(170, 70, 121, 23))
        self.le_ftp_server_address.setStyleSheet("background-color: rgb(235, 235, 235);\n"
"")
        self.le_ftp_server_address.setObjectName("le_ftp_server_address")
        self.le_username = QtWidgets.QLineEdit(self.centralwidget)
        self.le_username.setGeometry(QtCore.QRect(390, 70, 121, 23))
        self.le_username.setStyleSheet("background-color: rgb(235, 235, 235);\n"
"")
        self.le_username.setObjectName("le_username")
        self.le_password = QtWidgets.QLineEdit(self.centralwidget)
        self.le_password.setGeometry(QtCore.QRect(600, 70, 121, 23))
        self.le_password.setStyleSheet("background-color: rgb(235, 235, 235);\n"
"")
        self.le_password.setObjectName("le_password")
        self.btn_list = QtWidgets.QPushButton(self.centralwidget)
        self.btn_list.setGeometry(QtCore.QRect(100, 150, 131, 31))
        self.btn_list.setStyleSheet("background-color: rgb(170, 170, 170);")
        self.btn_list.setObjectName("btn_list")
        self.line = QtWidgets.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(0, 120, 891, 16))
        self.line.setStyleSheet("background-color: rgb(62, 62, 62);")
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.gb_create = QtWidgets.QGroupBox(self.centralwidget)
        self.gb_create.setGeometry(QtCore.QRect(20, 560, 301, 71))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.gb_create.setFont(font)
        self.gb_create.setStyleSheet("color: rgb(255, 255, 255);")
        self.gb_create.setObjectName("gb_create")
        self.btn_create = QtWidgets.QPushButton(self.gb_create)
        self.btn_create.setGeometry(QtCore.QRect(220, 30, 75, 23))
        self.btn_create.setStyleSheet("background-color: rgb(170, 170, 170);\n"
"color: rgb(0, 0, 0);")
        self.btn_create.setObjectName("btn_create")
        self.le_create_file = QtWidgets.QLineEdit(self.gb_create)
        self.le_create_file.setGeometry(QtCore.QRect(100, 30, 113, 20))
        self.le_create_file.setStyleSheet("background-color: rgb(0, 0, 0);\n"
"")
        self.le_create_file.setObjectName("le_create_file")
        self.lb_create_file = QtWidgets.QLabel(self.gb_create)
        self.lb_create_file.setGeometry(QtCore.QRect(0, 30, 101, 21))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_create_file.setFont(font)
        self.lb_create_file.setObjectName("lb_create_file")
        self.gb_download = QtWidgets.QGroupBox(self.centralwidget)
        self.gb_download.setGeometry(QtCore.QRect(20, 420, 281, 121))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.gb_download.setFont(font)
        self.gb_download.setStyleSheet("color: rgb(255, 255, 255);")
        self.gb_download.setObjectName("gb_download")
        self.le_download_path = QtWidgets.QLineEdit(self.gb_download)
        self.le_download_path.setGeometry(QtCore.QRect(80, 30, 113, 20))
        self.le_download_path.setStyleSheet("background-color: rgb(0, 0, 0);\n"
"")
        self.le_download_path.setObjectName("le_download_path")
        self.pb_download = QtWidgets.QProgressBar(self.gb_download)
        self.pb_download.setGeometry(QtCore.QRect(160, 95, 118, 16))
        self.pb_download.setProperty("value", 24)
        self.pb_download.setObjectName("pb_download")
        self.btn_download = QtWidgets.QPushButton(self.gb_download)
        self.btn_download.setGeometry(QtCore.QRect(80, 60, 75, 23))
        self.btn_download.setStyleSheet("background-color: rgb(170, 170, 170);\n"
"color: rgb(0, 0, 0);")
        self.btn_download.setObjectName("btn_download")
        self.btn_saveto = QtWidgets.QPushButton(self.gb_download)
        self.btn_saveto.setGeometry(QtCore.QRect(200, 30, 75, 23))
        self.btn_saveto.setStyleSheet("background-color: rgb(170, 170, 170);\n"
"color: rgb(0, 0, 0);")
        self.btn_saveto.setObjectName("btn_saveto")
        self.lb_filename = QtWidgets.QLabel(self.gb_download)
        self.lb_filename.setGeometry(QtCore.QRect(10, 30, 71, 16))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_filename.setFont(font)
        self.lb_filename.setObjectName("lb_filename")
        self.gb_move = QtWidgets.QGroupBox(self.centralwidget)
        self.gb_move.setGeometry(QtCore.QRect(20, 190, 281, 71))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.gb_move.setFont(font)
        self.gb_move.setStyleSheet("color: rgb(255, 255, 255);")
        self.gb_move.setObjectName("gb_move")
        self.btn_move = QtWidgets.QPushButton(self.gb_move)
        self.btn_move.setGeometry(QtCore.QRect(200, 30, 75, 23))
        self.btn_move.setStyleSheet("background-color: rgb(170, 170, 170);\n"
"color: rgb(0, 0, 0);")
        self.btn_move.setObjectName("btn_move")
        self.le_move = QtWidgets.QLineEdit(self.gb_move)
        self.le_move.setGeometry(QtCore.QRect(80, 30, 113, 20))
        self.le_move.setStyleSheet("background-color: rgb(0, 0, 0);\n"
"")
        self.le_move.setObjectName("le_move")
        self.lb_movepath = QtWidgets.QLabel(self.gb_move)
        self.lb_movepath.setGeometry(QtCore.QRect(30, 30, 47, 13))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_movepath.setFont(font)
        self.lb_movepath.setObjectName("lb_movepath")
        self.gb_upload = QtWidgets.QGroupBox(self.centralwidget)
        self.gb_upload.setGeometry(QtCore.QRect(20, 280, 281, 121))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.gb_upload.setFont(font)
        self.gb_upload.setStyleSheet("color: rgb(255, 255, 255);")
        self.gb_upload.setObjectName("gb_upload")
        self.le_upload_path = QtWidgets.QLineEdit(self.gb_upload)
        self.le_upload_path.setGeometry(QtCore.QRect(80, 30, 113, 20))
        self.le_upload_path.setStyleSheet("background-color: rgb(0, 0, 0);\n"
"")
        self.le_upload_path.setObjectName("le_upload_path")
        self.pb_upload = QtWidgets.QProgressBar(self.gb_upload)
        self.pb_upload.setGeometry(QtCore.QRect(160, 95, 118, 16))
        self.pb_upload.setProperty("value", 24)
        self.pb_upload.setObjectName("pb_upload")
        self.btn_upload = QtWidgets.QPushButton(self.gb_upload)
        self.btn_upload.setGeometry(QtCore.QRect(80, 60, 75, 23))
        self.btn_upload.setStyleSheet("background-color: rgb(170, 170, 170);\n"
"color: rgb(0, 0, 0);\n"
"")
        self.btn_upload.setObjectName("btn_upload")
        self.btn_loadfile = QtWidgets.QPushButton(self.gb_upload)
        self.btn_loadfile.setGeometry(QtCore.QRect(200, 30, 75, 23))
        self.btn_loadfile.setStyleSheet("background-color: rgb(170, 170, 170);\n"
"color: rgb(0, 0, 0);")
        self.btn_loadfile.setObjectName("btn_loadfile")
        self.lb_upload_path = QtWidgets.QLabel(self.gb_upload)
        self.lb_upload_path.setGeometry(QtCore.QRect(10, 30, 71, 16))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_upload_path.setFont(font)
        self.lb_upload_path.setObjectName("lb_upload_path")
        self.gb_delete = QtWidgets.QGroupBox(self.centralwidget)
        self.gb_delete.setGeometry(QtCore.QRect(20, 650, 301, 61))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.gb_delete.setFont(font)
        self.gb_delete.setStyleSheet("color: rgb(255, 255, 255);")
        self.gb_delete.setObjectName("gb_delete")
        self.btn_delete = QtWidgets.QPushButton(self.gb_delete)
        self.btn_delete.setGeometry(QtCore.QRect(220, 30, 75, 23))
        self.btn_delete.setStyleSheet("background-color: rgb(170, 170, 170);\n"
"color: rgb(0, 0, 0);")
        self.btn_delete.setObjectName("btn_delete")
        self.le_delete_file = QtWidgets.QLineEdit(self.gb_delete)
        self.le_delete_file.setGeometry(QtCore.QRect(100, 30, 113, 20))
        self.le_delete_file.setStyleSheet("background-color: rgb(0, 0, 0);\n"
"")
        self.le_delete_file.setObjectName("le_delete_file")
        self.lb_delete_directory = QtWidgets.QLabel(self.gb_delete)
        self.lb_delete_directory.setGeometry(QtCore.QRect(0, 30, 101, 21))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_delete_directory.setFont(font)
        self.lb_delete_directory.setObjectName("lb_delete_directory")
        self.lb_ftp_server_address = QtWidgets.QLabel(self.centralwidget)
        self.lb_ftp_server_address.setGeometry(QtCore.QRect(80, 70, 91, 20))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_ftp_server_address.setFont(font)
        self.lb_ftp_server_address.setStyleSheet("color: rgb(255, 255, 255);")
        self.lb_ftp_server_address.setObjectName("lb_ftp_server_address")
        self.lb_username = QtWidgets.QLabel(self.centralwidget)
        self.lb_username.setGeometry(QtCore.QRect(320, 70, 71, 20))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_username.setFont(font)
        self.lb_username.setStyleSheet("color: rgb(255, 255, 255);")
        self.lb_username.setObjectName("lb_username")
        self.lb_password = QtWidgets.QLabel(self.centralwidget)
        self.lb_password.setGeometry(QtCore.QRect(530, 70, 71, 20))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_password.setFont(font)
        self.lb_password.setStyleSheet("color: rgb(255, 255, 255);")
        self.lb_password.setObjectName("lb_password")
        self.lb_server_response = QtWidgets.QLabel(self.centralwidget)
        self.lb_server_response.setGeometry(QtCore.QRect(570, 140, 101, 20))
        font = QtGui.QFont()
        font.setFamily("Palatino Linotype")
        font.setPointSize(10)
        self.lb_server_response.setFont(font)
        self.lb_server_response.setStyleSheet("color: rgb(255, 255, 255);")
        self.lb_server_response.setObjectName("lb_server_response")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(320, 0, 241, 61))
        font = QtGui.QFont()
        font.setFamily("Verdana")
        font.setPointSize(36)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setFont(font)
        self.label_2.setStyleSheet("color: rgb(255, 255, 255);")
        self.label_2.setObjectName("label_2")
        self.line_2 = QtWidgets.QFrame(self.centralwidget)
        self.line_2.setGeometry(QtCore.QRect(330, 130, 16, 601))
        self.line_2.setStyleSheet("background-color: rgb(65, 65, 65);")
        self.line_2.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_2.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_2.setObjectName("line_2")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionHello = QtWidgets.QAction(MainWindow)
        self.actionHello.setObjectName("actionHello")
        self.actioncunt = QtWidgets.QAction(MainWindow)
        self.actioncunt.setObjectName("actioncunt")
        self.actiontoh_boi = QtWidgets.QAction(MainWindow)
        self.actiontoh_boi.setObjectName("actiontoh_boi")

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Conectar FTP Client"))
        self.cb_show_password.setText(_translate("MainWindow", "Show Password"))
        self.btn_connect.setText(_translate("MainWindow", "Connect"))
        self.btn_list.setText(_translate("MainWindow", "List Directories"))
        self.gb_create.setTitle(_translate("MainWindow", "Create a Directory"))
        self.btn_create.setText(_translate("MainWindow", "Create"))
        self.lb_create_file.setText(_translate("MainWindow", "Directory Name:"))
        self.gb_download.setTitle(_translate("MainWindow", "Download"))
        self.btn_download.setText(_translate("MainWindow", "Download"))
        self.btn_saveto.setText(_translate("MainWindow", "Save to"))
        self.lb_filename.setText(_translate("MainWindow", "File Name:"))
        self.gb_move.setTitle(_translate("MainWindow", "Move"))
        self.btn_move.setText(_translate("MainWindow", "Move to"))
        self.lb_movepath.setText(_translate("MainWindow", "Path:"))
        self.gb_upload.setTitle(_translate("MainWindow", "Upload"))
        self.btn_upload.setText(_translate("MainWindow", "Upload"))
        self.btn_loadfile.setText(_translate("MainWindow", "Load File"))
        self.lb_upload_path.setText(_translate("MainWindow", "File Name:"))
        self.gb_delete.setTitle(_translate("MainWindow", "Delete Directory"))
        self.btn_delete.setText(_translate("MainWindow", "Delete"))
        self.lb_delete_directory.setText(_translate("MainWindow", "Directory Name:"))
        self.lb_ftp_server_address.setText(_translate("MainWindow", "Host Address:"))
        self.lb_username.setText(_translate("MainWindow", "Username:"))
        self.lb_password.setText(_translate("MainWindow", "Password:"))
        self.lb_server_response.setText(_translate("MainWindow", "Server Response"))
        self.label_2.setText(_translate("MainWindow", "Conectar"))

