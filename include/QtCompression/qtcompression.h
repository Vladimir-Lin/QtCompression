/****************************************************************************
 *
 * Copyright (C) 2001~2016 Neutrino International Inc.
 *
 * Author   : Brian Lin ( Foxman , Vladimir Lin , Vladimir Forest )
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

#ifndef QT_COMPRESSION_H
#define QT_COMPRESSION_H

#include <QtCore>
#ifndef QT_STATIC
#include <QtScript>
#endif
#include <QtGZip>
#include <QtBZip2>
#include <QtLzo>
#include <QtLZ4>
#include <QtQuickLZ>
#include <QtUCL>
#include <QtXz>
#include <QtLZip>
#include <QtTransformers>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(QT_BUILD_QTCOMPRESSION_LIB)
#    define Q_COMPRESSION_EXPORT Q_DECL_EXPORT
#  else
#    define Q_COMPRESSION_EXPORT Q_DECL_IMPORT
#  endif
#else
#    define Q_COMPRESSION_EXPORT
#endif

#define QT_COMPRESSION_LIB 1

class Q_COMPRESSION_EXPORT QtFileDetail ;
class Q_COMPRESSION_EXPORT QtCompressor ;

namespace Compressors
{



}

class Q_COMPRESSION_EXPORT QtFileDetail : public QFileInfo
{
  public:

    typedef enum     {
      None      =  0 ,
      Regular   =  1 ,
      Link      =  2 ,
      Symbol    =  3 ,
      Char      =  4 ,
      Block     =  5 ,
      Directory =  6 ,
      FIFO      =  7 ,
      Reserved  =  8 ,
      Next      =  9 ,
      Extended  = 10 }
      FileTypes      ;

    bool      Archive  ; /* inside a Tar file or Zip file, and so on */
    QString   URL      ; /* URL Address */
    QString   Host     ; /* Hostname */
    QString   Root     ; /* Root directory */
    QString   Filename ; /* Filename or directory name of this entry */
    QString   System   ; /* Normally, this is operation system */
    qint64    mode     ; /* Unix only */
    qint64    uid      ; /* Unix only */
    qint64    gid      ; /* Unix only */
    qint64    size     ; /* File size, for directory, it is 0 */
    qint32    mime     ; /* MIME type number */
    QDateTime Time     ; /* Creation time */
    QDateTime Lastest  ; /* Last modified */
    QString   CheckSum ; /* CheckSum of this file */
    FileTypes Type     ; /* File Type */
    QString   LinkName ; /* Unix only */
    QString   uname    ; /* Unix only */
    QString   gname    ; /* Unix only */
    qint64    Major    ; /* Unix only */
    qint64    Minor    ; /* Unix only */
    QString   Prefix   ; /* Normally, this is prefix directory */
    QString   Comment  ; /* This is from GZIP format, however, sometimes it is useful */

    explicit               QtFileDetail  (void) ;
                           QtFileDetail  (QString filename) ;
                           QtFileDetail  (const QtFileDetail & fi) ;
    virtual               ~QtFileDetail  (void) ;

    virtual QtFileDetail & operator =    (const QtFileDetail & fi) ;

    virtual QString        FullPath      (void) ;

    virtual bool           changeOwner   (QDir & root) ;
    virtual bool           changeGroup   (QDir & root) ;
    virtual bool           changeMode    (QDir & root) ;
    virtual bool           makeNode      (QDir & root) ;
    virtual bool           createLink    (QDir & root) ;
    virtual bool           createFIFO    (QDir & root) ;
    virtual bool           createChar    (QDir & root) ;
    virtual bool           createBlock   (QDir & root) ;
    virtual bool           makeDirectory (QDir & root) ;
    virtual bool           Obtain        (QDir & root) ;

  protected:

  private:

} ;

class Q_COMPRESSION_EXPORT QtCompressor
{
  public:

    QMap<QString,QVariant> Information ;

    explicit     QtCompressor       (void) ;
    virtual     ~QtCompressor       (void) ;

    virtual int  type               (void) const = 0 ;
    virtual void clean              (void) = 0 ;

    virtual int  suffixes           (QStringList & names) = 0;
    virtual bool containSuffix      (QString filename) = 0 ;

    virtual int  MimeTypes          (QList<int>  & mimetypes) = 0 ;
    virtual bool containMime        (int mime) = 0 ;

    virtual bool isCorrect          (int returnCode) = 0 ;
    virtual bool isEnd              (int returnCode) = 0 ;
    virtual bool isFault            (int returnCode) = 0 ;
    virtual int  Footer             (void) = 0 ;

    virtual int  PrepareCompress    (QVariantList arguments = QVariantList() ) = 0 ;
    virtual int  Compress           (const QByteArray & Source                ,
                                           QByteArray & Compressed  )     = 0 ;
    virtual int  SectionCompress    (      QByteArray & Source                ,
                                           QByteArray & Compressed  )     = 0 ;
    virtual int  CompressFinished   (QByteArray & Compressed  )           = 0 ;

    virtual int  PrepareDecompress  (QVariantList arguments = QVariantList() ) = 0 ;
    virtual int  Decompress         (const QByteArray & Source                ,
                                           QByteArray & Decompressed)     = 0 ;
    virtual int  SectionDecompress  (      QByteArray & Source                ,
                                           QByteArray & Decompressed)     = 0 ;
    virtual int  DecompressFinished (void)                                = 0 ;

    virtual bool EncodeHeader       (QtFileDetail & file,QByteArray & header) = 0 ;
    virtual bool DecodeHeader       (QtFileDetail & file,QByteArray & header) = 0 ;
    virtual bool EncodeTail         (QByteArray & header) = 0 ;
    virtual bool DecodeTail         (QByteArray & header) = 0 ;

  protected:

  private:

} ;

namespace Compressors
{



}

Q_COMPRESSION_EXPORT void RegisterCompressors (void) ;
Q_COMPRESSION_EXPORT void AddCompressors      (QtTransformers & transformers) ;

Q_DECLARE_INTERFACE(QtCompressor,"com.neutrino.data.qtcompressor")

QT_END_NAMESPACE

#endif
