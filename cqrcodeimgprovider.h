#ifndef CQRCODEIMGPROVIDER_H
#define CQRCODEIMGPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>

class CQrCodeImgProvider : public QQuickImageProvider
{
	//Q_OBJECT
public:
	explicit CQrCodeImgProvider(QImage img);
	QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
signals:

public slots:
private:

	QImage m_img;
};

#endif // CQRCODEIMGPROVIDER_H
