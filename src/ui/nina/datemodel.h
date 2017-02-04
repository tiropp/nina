#ifndef DATEMODEL_H
#define DATEMODEL_H

// Qt includes
#include <QObject>

// Nina domain includes
#include <nina/Date.h>



class DateModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool useDateToday READ useDateToday WRITE setUseDateToday NOTIFY useDateTodayChanged)
    Q_PROPERTY(bool useDateSpecified READ useDateSpecified WRITE setUseDateSpecified NOTIFY useDateSpecifiedChanged)
    Q_PROPERTY(unsigned day READ day WRITE setDay NOTIFY dayChanged)
    Q_PROPERTY(unsigned month READ month WRITE setMonth NOTIFY monthChanged)
    Q_PROPERTY(unsigned year READ year WRITE setYear NOTIFY yearChanged)

  public:
    DateModel();

  public:
    nina::domain::Date createDomain() const;

  public:
    void set(const nina::domain::Date& date);
    void setUseDateToday(bool useDateToday);
    void setUseDateSpecified(bool useDateSpecified);
    void setDay(unsigned day);
    void setMonth(unsigned month);
    void setYear(unsigned year);

  public:
    bool useDateToday() const { return m_useDateToday; }
    bool useDateSpecified() const { return m_useDateSpecified; }
    unsigned day() const { return m_day; }
    unsigned month() const { return m_month; }
    unsigned year() const { return m_year; }

  signals:
    void useDateTodayChanged();
    void useDateSpecifiedChanged();
    void dayChanged();
    void monthChanged();
    void yearChanged();

  private:
    bool m_useDateToday;
    bool m_useDateSpecified;
    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
};

#endif // DATEMODEL_H
