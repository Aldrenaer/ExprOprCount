#include "qtquestcode.h"

class QTQuestcodeData : public QSharedData
{
public:
};

QTQuestcode::QTQuestcode()
    : data(new QTQuestcodeData)
{}

QTQuestcode::QTQuestcode(const QTQuestcode &rhs)
    : data{rhs.data}
{}

QTQuestcode &QTQuestcode::operator=(const QTQuestcode &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

QTQuestcode::~QTQuestcode() {}
