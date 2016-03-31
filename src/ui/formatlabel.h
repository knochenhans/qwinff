#ifndef FORMATLABEL_H
#define FORMATLABEL_H

#include <QLabel>
#include <QString>

class FormatLabel : public QLabel
{
    Q_OBJECT
public:
    explicit FormatLabel(const QString &fileExt, QWidget *parent = 0);
    QMap<QString, QString> getColorMap(const QString &fileExt);
};



#endif // FORMATLABEL_H
