/****************************************************************************
 *
 * Copyright (C) 2016 Neutrino International Inc.
 *
 * Author   : Brian Lin ( Vladimir Lin , Vladimir Forest )
 * E-mail   : lin.foxman@gmail.com
 *          : lin.vladimir@gmail.com
 *          : wolfram_lin@yahoo.com
 *          : wolfram_lin@sina.com
 *          : wolfram_lin@163.com
 * Skype    : wolfram_lin
 * WeChat   : 153-0271-7160
 * WhatsApp : 153-0271-7160
 * QQ       : lin.vladimir@gmail.com (2107437784)
 * URL      : http://qtcompression.sourceforge.net/
 *
 * QtCompression acts as an interface between Qt and compresions library.
 *
 * Copyright 2001 ~ 2016
 *
 ****************************************************************************/

#include <qtcompression.h>

#define nMemberCopy(Object,Member) Member = Object . Member

QtFileDetail:: QtFileDetail (void)
             : QFileInfo    (    )
{
  Archive  = false                        ;
  Filename = ""                           ;
  mode     = 0                            ;
  uid      = 0                            ;
  gid      = 0                            ;
  size     = 0                            ;
  mime     = 0                            ;
  Time     = QDateTime::currentDateTime() ;
  Lastest  = QDateTime::currentDateTime() ;
  CheckSum = ""                           ;
  Type     = QtFileDetail::None           ;
  LinkName = ""                           ;
  uname    = ""                           ;
  gname    = ""                           ;
  Major    = 0                            ;
  Minor    = 0                            ;
  Prefix   = ""                           ;
  #if   defined(Q_OS_IOS)
  System   = "iPhoneOS"                   ;
  #elif defined(Q_OS_ANDROID)
  System   = "Android"                    ;
  #elif defined(Q_OS_MACX)
  System   = "MacOSX"                     ;
  #elif defined(Q_OS_LINUX)
  System   = "Linux"                      ;
  #elif defined(Q_OS_WIN)
  System   = "Windows"                    ;
  #else
  System   = "Unknown"                    ;
  #endif
}

QtFileDetail:: QtFileDetail (QString filename)
             : QFileInfo    (        filename)
{
  Archive  = false                        ;
  Filename = ""                           ;
  mode     = 0                            ;
  uid      = 0                            ;
  gid      = 0                            ;
  size     = 0                            ;
  mime     = 0                            ;
  Time     = QDateTime::currentDateTime() ;
  Lastest  = QDateTime::currentDateTime() ;
  CheckSum = ""                           ;
  Type     = QtFileDetail::None           ;
  LinkName = ""                           ;
  uname    = ""                           ;
  gname    = ""                           ;
  Major    = 0                            ;
  Minor    = 0                            ;
  Prefix   = ""                           ;
  #if   defined(Q_OS_IOS)
  System   = "iPhoneOS"                   ;
  #elif defined(Q_OS_ANDROID)
  System   = "Android"                    ;
  #elif defined(Q_OS_MACX)
  System   = "MacOSX"                     ;
  #elif defined(Q_OS_LINUX)
  System   = "Linux"                      ;
  #elif defined(Q_OS_WIN)
  System   = "Windows"                    ;
  #else
  System   = "Unknown"                    ;
  #endif
}

QtFileDetail:: QtFileDetail(const QtFileDetail & fi)
{
  (*this) = fi ;
}

QtFileDetail::~QtFileDetail(void)
{
}

QtFileDetail & QtFileDetail::operator = (const QtFileDetail & fi)
{
  (*((QFileInfo *)this)) = (*((QFileInfo *)&fi)) ;
  nMemberCopy ( fi , Archive  )                  ;
  nMemberCopy ( fi , Filename )                  ;
  nMemberCopy ( fi , System   )                  ;
  nMemberCopy ( fi , mode     )                  ;
  nMemberCopy ( fi , uid      )                  ;
  nMemberCopy ( fi , gid      )                  ;
  nMemberCopy ( fi , size     )                  ;
  nMemberCopy ( fi , mime     )                  ;
  nMemberCopy ( fi , Time     )                  ;
  nMemberCopy ( fi , Lastest  )                  ;
  nMemberCopy ( fi , CheckSum )                  ;
  nMemberCopy ( fi , Type     )                  ;
  nMemberCopy ( fi , LinkName )                  ;
  nMemberCopy ( fi , uname    )                  ;
  nMemberCopy ( fi , gname    )                  ;
  nMemberCopy ( fi , Major    )                  ;
  nMemberCopy ( fi , Minor    )                  ;
  nMemberCopy ( fi , Prefix   )                  ;
  return (*this)                                 ;
}

QString QtFileDetail::FullPath(void)
{
  QString m = Prefix         ;
  if (m.length()>0) m += "/" ;
  m += Filename              ;
  return m                   ;
}

bool QtFileDetail::changeOwner(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::changeGroup(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::changeMode(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::makeNode(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::createLink(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::createFIFO(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::createChar(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::createBlock(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::makeDirectory(QDir & root)
{
  #ifdef WIN32
  #else
  #endif
  return true ;
}

bool QtFileDetail::Obtain(QDir & root)
{
  QString fn = absoluteFilePath()              ;
  Filename   = root.relativeFilePath   (fn)    ;
  uname      = QFileInfo::owner        (  )    ;
  gname      = QFileInfo::group        (  )    ;
  size       = QFileInfo::size         (  )    ;
  Time       = QFileInfo::created      (  )    ; /* Creation time */
  Lastest    = QFileInfo::lastModified (  )    ; /* Last modified */
  if (isDir())                                 {
    Type     = QtFileDetail::Directory         ;
    #ifdef WIN32
    mode     = 01755                           ;
    #else
    #endif
  } else
  if (isSymLink())                             {
    Type     = QtFileDetail::Link              ;
    LinkName = symLinkTarget()                 ;
    LinkName = root.relativeFilePath(LinkName) ;
  } else
  if (isFile())                                {
    Type     = QtFileDetail::Regular           ;
    mode     = 0664                            ;
  } else                                       {
    Type     = QtFileDetail::Regular           ;
    mode     = 0664                            ;
  }                                            ;
  #ifdef WIN32
  Major = 0 ;
  Minor = 0 ;
  uid   = 0 ;
  gid   = 0 ;
  #else
  Major = 0 ;
  Minor = 0 ;
  uid   = QFileInfo::ownerId ( ) ;
  gid   = QFileInfo::groupId ( ) ;
  #endif
  return true ;
}
