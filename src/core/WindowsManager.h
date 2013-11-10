#ifndef OTTER_WINDOWSMANAGER_H
#define OTTER_WINDOWSMANAGER_H

#include <QtCore/QUrl>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets/QMdiArea>

namespace Otter
{

class Window;
class TabBarWidget;

class WindowsManager : public QObject
{
	Q_OBJECT

public:
	explicit WindowsManager(QMdiArea *area, TabBarWidget *tabBar);

	Window* getWindow(int index = -1) const;
	int getCurrentWindow() const;
	int getZoom() const;
	bool canUndo() const;
	bool canRedo() const;

public slots:
	void open(const QUrl &url = QUrl());
	void close(int index = -1);
	void closeOther(int index = -1);
	void print(int index = -1);
	void printPreview(int index = -1);
	void undo();
	void redo();
	void cut();
	void copy();
	void paste();
	void remove();
	void selectAll();
	void zoomIn();
	void zoomOut();
	void zoomOriginal();
	void setZoom(int zoom);

protected slots:
	void printPreview(QPrinter *printer);
	void closeWindow(int index);
	void setCurrentWindow(int index);
	void setTitle(const QString &title) const;
	void setIcon(const QIcon &icon) const;

private:
	QMdiArea *m_area;
	TabBarWidget *m_tabBar;
	QList<Window*> m_windows;
	int m_currentWindow;
	int m_printedWindow;

signals:
	void windowAdded(int index);
	void windowRemoved(int index);
	void currentWindowChanged(int index);
	void undoTextChanged(QString undoText);
	void redoTextChanged(QString redoText);
	void canUndoChanged(bool canUndo);
	void canRedoChanged(bool canRedo);
};

}

#endif