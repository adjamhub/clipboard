/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * ClipBoard Project
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */


#ifndef CLIPBOARD_TRAY_H
#define CLIPBOARD_TRAY_H


#include "clipboardmanager.h"

#include <QSystemTrayIcon>
#include <QMenu>


class ClipboardTray : public QSystemTrayIcon
{
    Q_OBJECT

public:
    ClipboardTray (QObject *parent = nullptr);
    ~ClipboardTray();

private:
    void loadContextMenu();

private Q_SLOTS:
    void showSettings();
    void aboutApp();

private:
    ClipboardManager* _clipboard;
    QMenu* _contextMenu;
};


#endif // CLIPBOARD_TRAY_H
