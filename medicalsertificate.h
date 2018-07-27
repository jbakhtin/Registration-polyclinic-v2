#ifndef MEDICALSERTIFICATE_H
#define MEDICALSERTIFICATE_H

#include <QString>

class MedicalSertificate
{
public:
    MedicalSertificate();
    void setLogin(const QString &str);
    void setTitle(const QString &str);
    void setText(const QString &str);
    void setAutor(const QString &str);

    void load(QDataStream &ds);
    void save(QDataStream &ds) const;

    const QString &getLogin() const;
    const QString &getTitle() const;
    const QString &getText() const;
    const QString &getAutor() const;

private:
    QString mLogin;
    QString mTitle;
    QString mText;
    QString mAutor;
};

#endif // MEDICALSERTIFICATE_H
