/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * ClipBoard Project
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */


#include "clipboardtray.h"
#include "settingsdialog.h"

#include <QApplication>
#include <QAction>
#include <QIcon>
#include <QMessageBox>


ClipboardTray::ClipboardTray (QObject *parent)
    : QSystemTrayIcon (parent)
    , _clipboard( new ClipboardManager(this) )
    , _contextMenu( new QMenu )
{
    setIcon( QIcon::fromTheme("edit-copy") );
    
    setToolTip("clipboard");
    
    setupContextMenu();
}


ClipboardTray::~ClipboardTray()
{
    delete _contextMenu;
}


void ClipboardTray::setupContextMenu()
{
    QAction* actionShowSettings = new QAction( QIcon::fromTheme("settings-configure"), "Settings", this);
    connect(actionShowSettings, &QAction::triggered, this, &ClipboardTray::showSettings);
    _contextMenu->addAction(actionShowSettings);

    QAction* actionAboutApp = new QAction( QIcon::fromTheme("help-about"), "About", this );
    connect(actionAboutApp, &QAction::triggered, this, &ClipboardTray::aboutApp);
    _contextMenu->addAction(actionAboutApp);

    QAction* actionQuit = new QAction( QIcon::fromTheme("application-exit"), "Quit", this );
    connect(actionQuit, &QAction::triggered, qApp, &QApplication::quit, Qt::QueuedConnection);
    _contextMenu->addAction(actionQuit);

    setContextMenu(_contextMenu);
}


void ClipboardTray::showSettings()
{
    SettingsDialog* dialog = new SettingsDialog;
    dialog->exec();
    dialog->deleteLater();

//    loadSettings();
}


void ClipboardTray::aboutApp()
{
    QString version = qApp->applicationVersion();

    QMessageBox::about(nullptr,
                       "About clipboard",
                        "Clipboard " + version + "\n\nMinimal Clipboard Manager, based on Qt libraries");
}
