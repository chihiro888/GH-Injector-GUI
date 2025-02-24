#pragma once

/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#include "..\pch.h"

class WindowDocker;

#include "ui_framelesswindow.h"
#include "..\WindowDocker.h"

namespace Ui
{
	class FramelessWindow;
}

class FramelessWindow : public QWidget
{
	Q_OBJECT

	const static int dock_range = 25;

private:
	QWidget * content;

	bool resize_left;
	bool resize_right;
	bool resize_top;
	bool resize_bottom;

	bool m_bDockButton;

public:
	explicit FramelessWindow(QWidget * parent = Q_NULLPTR);
	virtual ~FramelessWindow();
	void setContent(QWidget * w);
	void setTitleBar(bool active);
	void setMinimizeButton(bool active);
	void setDockButton(bool active, bool docked, int direction);

	void setResizeLeft	(bool enabled = false);
	void setResizeRight	(bool enabled = false);
	void setResizeTop	(bool enabled = false);
	void setResizeBottom(bool enabled = false);
	void setResizeHorizontal(bool enabled = false);
	void setResizeVertical	(bool enabled = false);
	void setResize(bool enabled = false);
	void setBorderStyle(QString style);

private:
	bool leftBorderHit(const QPoint & pos);
	bool rightBorderHit(const QPoint & pos);
	bool topBorderHit(const QPoint & pos);
	bool bottomBorderHit(const QPoint & pos);
	void styleWindow(bool bActive, bool bNoState);

	void updateSizePolicy();

public slots:
	void setWindowTitle(const QString & text);
	void setWindowIcon(const QIcon & ico);
	
	void on_applicationStateChanged(Qt::ApplicationState state);
	void on_dockButton_clicked();
	void on_minimizeButton_clicked();
	void on_closeButton_clicked();

signals:
	void closeButton_clicked();
	void dockButton_clicked();
	void windowTitlebar_clicked();
	void windowTitlebar_released();

protected:
	virtual void changeEvent(QEvent * event);
	virtual void checkBorderDragging(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual bool eventFilter(QObject * obj, QEvent * event);

private:

	Ui::FramelessWindow * ui;

	QRect m_StartGeometry;
	const quint8 CONST_DRAG_BORDER_SIZE = 15;

	bool m_bMousePressed;
	bool m_bDragTop;
	bool m_bDragLeft;
	bool m_bDragRight;
	bool m_bDragBottom;
	bool m_bDragged;
};