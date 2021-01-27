/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * ClipBoard Project
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */


#include "clipboardmanager.h"

#include <QApplication>
#include <QMimeData>

#include <QDebug>


ClipboardManager::ClipboardManager (QObject *parent)
    : QObject (parent)
    , _clip(QApplication::clipboard())
    , _guard(true)
{
    connect(_clip, &QClipboard::changed, this, &ClipboardManager::dataChanged);
}


void ClipboardManager::dataChanged(QClipboard::Mode mode)
{
    // the boolean guard is needed to prevent enter in an infinite loop
    // calling QClipboard::setMimeData that triggers QClipboard::changed signal
    // that triggers this function...
    if (!_guard) {
        _guard = true;
        return;
    }

    // we try support just this (for now)
    if (mode != QClipboard::Clipboard) {
        return;
    }

    const QMimeData *mimeData = _clip->mimeData(mode);

    if (mimeData->formats().count() == 0) {
        return;
    }

    if (!mimeData->hasText()) {
        return;
    }

    QString text = mimeData->text();
    qDebug() << "clip text:" << _clip->text();
    qDebug() << "mime text:" << text;

    _contents << text;
    qDebug() << "contents: " << _contents;
    qDebug() << "------------------------";
    QMimeData *mime = new QMimeData();
    mime->setText(text);
    _guard = false;
    _clip->setMimeData(mime, mode);
}
