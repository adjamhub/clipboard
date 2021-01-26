/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * Clipboard project
 *
 * @license GPL-3.0 <https://www.gnu.org/licenses/gpl-3.0.txt>
 */


#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H


#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE


class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private:
    void loadSettings();

private slots:
    void saveSettings();

private:
    Ui::Dialog *ui;
};

#endif // SETTINGSDIALOG_H
