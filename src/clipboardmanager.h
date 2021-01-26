/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * ClipBoard Project
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */


#ifndef CLIPBOARD_MANAGER_H
#define CLIPBOARD_MANAGER_H


#include <QObject>


class ClipboardManager : public QObject
{
    Q_OBJECT

public:
    ClipboardManager (QObject *parent = nullptr);
};


#endif // CLIPBOARD_MANAGER_H
