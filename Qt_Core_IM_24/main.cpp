#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <qloggingcategory.h>

// Declare a logging category
Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "network_");

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	qInfo() << "test";

	qInfo(network) << "test1";

	// turn it off
	QLoggingCategory::setFilterRules("network_.debug=false");

	// will not log : because turn off
	qDebug(network) << "test2";


	if (!network().isDebugEnabled()) {
		// turn it on
		QLoggingCategory::setFilterRules("network_.debug=true");

		qDebug(network) << "test3";
	}

	return a.exec();
}
