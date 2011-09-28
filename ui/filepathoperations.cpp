#include "filepathoperations.h"
#include <QCoreApplication>

FilePathOperations::FilePathOperations()
{
}

QString FilePathOperations::GenerateUniqueFileName(const QDir& output_dir, const QString& input_file_basename
                               , const QString& ext)
{
    int filename_index = 1;
    QString result;
    do {
        // The index part of the file
        QString str_index("");
        if (filename_index > 1) {
            // If the index is larger than 1, append -index to the filename.
            str_index = QString("-%1").arg(filename_index);
        }

        // Fill in output filename.
        result =
                output_dir.absoluteFilePath(input_file_basename)   // filename
                + str_index                                        // index
                + '.'                                              // point
                + ext;                                             // extension

        ++filename_index;
    } while (QFileInfo(result).exists()); // If file(n) exists, try file(n+1).
    return result;
}

QString FilePathOperations::GenerateTempFileName(const QString& filename)
{
    QString result;
    do {
        // Generate temporary file name.
        result = QString("%1-%2-temp-%3.%4").arg(filename)
                .arg(qrand()).arg(QCoreApplication::applicationPid())
                .arg(QFileInfo(filename).suffix());
    } while (QFileInfo(result).exists()); // Regenerate if exists.

    return result;
}
