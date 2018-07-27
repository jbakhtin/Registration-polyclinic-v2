#-------------------------------------------------
#
# Project created by QtCreator 2017-10-24T19:08:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Registration_Polyclinic
TEMPLATE = app


SOURCES += main.cpp\
    authorization.cpp \
    user.cpp \
    userlists.cpp \
    editwindow.cpp \
    patient.cpp \
    doctor.cpp \
    registrator.cpp \
    specialty.cpp \
    mainwindow.cpp \
    certificatewindow.cpp \
    medicalsertificate.cpp \
    patientcard.cpp \
    medicalrecordwindow.cpp \
    medicalrecord.cpp

HEADERS  += mainwindow.h \
    authorization.h \
    user.h \
    userlists.h \
    editwindow.h \
    patient.h \
    doctor.h \
    registrator.h \
    specialty.h \
    certificatewindow.h \
    medicalsertificate.h \
    patientcard.h \
    medicalrecordwindow.h \
    medicalrecord.h

FORMS    += mainwindow.ui \
    authorization.ui \
    editwindow.ui \
    specialty.ui \
    certificatewindow.ui \
    patientcard.ui \
    medicalrecordwindow.ui

DISTFILES += \
    userLists/certificates.txt \
    userLists/doctor.txt \
    userLists/patient.txt \
    userLists/registrator.txt \
    userLists/specialities.txt \
    userLists/user.txt \
    images/edit.svg \
    images/key.svg \
    images/key2.svg \
    images/key3.svg \
    images/key4.svg \
    images/key5.svg \
    images/private.svg \
    images/user.svg \
    images/user1.svg \
    images/user2.svg \
    images/user3.svg \
    images/users.svg \
    images/users2.svg
