#ifndef QTQUESTCODE_H
#define QTQUESTCODE_H

#include <QSharedDataPointer>

class QTQuestcodeData;

class QTQuestcode
{
public:
    QTQuestcode();
    QTQuestcode(const QTQuestcode &);
    QTQuestcode &operator=(const QTQuestcode &);
    ~QTQuestcode();

private:
    QSharedDataPointer<QTQuestcodeData> data;
};

#endif // QTQUESTCODE_H
