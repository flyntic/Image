#ifndef QIMAGEWIDGET_H
#define QIMAGEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMargins>

class QImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QImageWidget(QWidget *parent = nullptr);
    ~QImageWidget(){};
private:
    QPixmap _originalImage;
    QString _noImageMessage;
    int _margin;
    QMargins _margins;
    QColor _backgroundColor;
    QRect _rect;
public:
    void setPixmap(QPixmap pixmap);
    QPixmap pixmap(){return _originalImage;};
    int margin(){return _margin;}
    QRect actualImageRect();
    QRect rect() {return _rect; }
signals:
    void pixmapChanged();
    void marginChanged();

    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
public slots:
    void setMargin(int value);
    void setRect(QRect rect) {_rect=rect;}



};


#endif // QIMAGEWIDGET_H
