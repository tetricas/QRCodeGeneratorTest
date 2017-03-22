#include "cqrcodeimgprovider.h"
#include <QtDebug>

CQrCodeImgProvider::CQrCodeImgProvider(QImage img) :
    QQuickImageProvider(QQuickImageProvider::Image),
    m_img(img)
{}

QImage CQrCodeImgProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
	if (size)
	{
		size->setWidth(m_img.width());
		size->setHeight(m_img.height());
	}

	return m_img;
}
