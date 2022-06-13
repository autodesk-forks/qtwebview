/****************************************************************************
**
** Copyright (C) 2022 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebView module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
******************************************************************************/

#ifndef QQUICKVIEWCONTROLLER_H
#define QQUICKVIEWCONTROLLER_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtWebViewQuick/private/qtwebviewquickglobal_p.h>
#include <QtQuick/QQuickItem>
#include <QtGui/qwindow.h>

QT_BEGIN_NAMESPACE

class QNativeViewController;
class QQuickViewChangeListener;

class Q_WEBVIEWQUICK_EXPORT QQuickViewController : public QQuickItem
{
    Q_OBJECT
public:
    explicit QQuickViewController(QQuickItem *parent = nullptr);
    ~QQuickViewController();

public Q_SLOTS:
    void onWindowChanged(QQuickWindow *window);
    void onVisibleChanged();

protected:
    void componentComplete() override;
    void updatePolish() override;
    void geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry) override;
    void setView(QNativeViewController *view);

private:
    friend class QQuickWebView;
    QNativeViewController *m_view;
    QScopedPointer<QQuickViewChangeListener> m_changeListener;

private Q_SLOTS:
    void scheduleUpdatePolish();
    void onSceneGraphInvalidated();
};

QT_END_NAMESPACE

#endif // QTWINDOWCONTROLLERITEM_H
