#include "qled_plugin.h"
#include "qled.h"

#include <qdeclarative.h>

void QLEDPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<QLED>(uri, 1, 0, "QLED");
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(QLED, QLEDPlugin)
#endif

