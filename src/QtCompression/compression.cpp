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

QT_BEGIN_NAMESPACE

//////////////////////////////////////////////////////////////////////////////

void RegisterCompressors(void)
{
  qRegisterMetaType<QtFileDetail>("QtFileDetail") ;
}

void AddCompressors(QtTransformers & t)
{
}

//////////////////////////////////////////////////////////////////////////////

QtCompressor:: QtCompressor(void)
{
}

QtCompressor::~QtCompressor(void)
{
}

//////////////////////////////////////////////////////////////////////////////

QT_END_NAMESPACE
