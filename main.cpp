#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QtDebug>
#include <QImage>
#include <QSvgRenderer>
#include <QPainter>

#include <string>
#include <vector>

#include "QrCode.h"
#include "cqrcodeimgprovider.h"

using namespace qrcodegen;

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QrCode qr0 = QrCode::encodeText("255.255.255.255", QrCode::Ecc::MEDIUM);
	std::string svg = qr0.toSvgString(4);

	QByteArray byteArray(svg.data());
	QSvgRenderer svgRender(byteArray);

	QImage image(500, 500, QImage::Format_ARGB32);
	QPainter painter(&image);
	svgRender.render(&painter);

	CQrCodeImgProvider myProvider(image);
	QQmlApplicationEngine engine;
	engine.addImageProvider(QStringLiteral("QrCodeImgProvider"), &myProvider );

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}
