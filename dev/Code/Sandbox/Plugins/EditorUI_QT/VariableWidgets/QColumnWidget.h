/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#ifndef CRYINCLUDE_EDITORUI_QT_VARIABLE_WIDGETS_QCOLUMNWIDGET_H
#define CRYINCLUDE_EDITORUI_QT_VARIABLE_WIDGETS_QCOLUMNWIDGET_H
#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "QCopyableWidget.h"
#include "BaseVariableWidget.h"

class CAttributeItem;
struct IVariable;
class QBitmapPreviewDialogImp;
class QToolTipWidget;
class QCheckBox;

class QColumnWidget
    : public QCopyableWidget
{
    Q_OBJECT
    class QCustomLabel
        : public QLabel
    {
    public:
        QCustomLabel(const QString& label, CAttributeItem* parent, bool collapsible = false);
        virtual ~QCustomLabel();

        void onVarChanged(IVariable* var);

        void SetCollapsible(bool val);
        void SignalHightlightUpdate(bool highlight){};

    protected:
        void setHighlight(const bool& isHighlight);

    private:
        void mouseMoveEvent(QMouseEvent* e);
        bool event(QEvent* e);
        bool eventFilter(QObject* obj, QEvent* e);

    private:
        CAttributeItem* m_parent;
        QToolTipWidget* m_tooltip;
        int m_propertyType;
        IVariable* m_variable;
        bool m_collapsible;
    };

public:
    QColumnWidget(CAttributeItem* parent, const QString& label, QWidget* widget, bool collapsible = false, bool fullWidth = true);
    ~QColumnWidget();
    void SetCollapsible(bool val);
    QVBoxLayout* GetChildLayout() { return m_layoutChildren; }
    QHBoxLayout* GetLeftLayout() { return m_leftLayout; }
    void SetAsCollapsible(CAttributeItem* item);
    void SetCollapsed(bool state);
private slots:
    void CollapseButton_clicked();

private:
    QCustomLabel* lbl;
    void mousePressEvent(QMouseEvent* e);
    void keyPressEvent(QKeyEvent* event);
    void onVarChanged(IVariable* var);
    void RecursiveStyleUpdate(QWidget* root);
    virtual void paintEvent(QPaintEvent*) override;
    CAttributeItem* m_parent;
    QVBoxLayout* m_topLayout;
    QHBoxLayout* m_containerLayout;
    QHBoxLayout* m_leftLayout;
    QHBoxLayout* m_rightLayout;
    QWidget* m_widgetChildren;
    QVBoxLayout* m_layoutChildren;
    QCheckBox* m_collapseButton;
    IVariable* m_variable;
    bool m_canReset; // Used to ignore redundant changes
    bool m_isCollapsible = false;
    CAttributeItem* m_attributeItem = nullptr;
};

#endif // CRYINCLUDE_EDITORUI_QT_VARIABLE_WIDGETS_QCOLUMNWIDGET_H
