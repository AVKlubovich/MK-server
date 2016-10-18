#pragma once

#ifdef _MSC_VER
#   pragma warning(push)
#   pragma warning(disable:4180) // QtCore/qmap.h(72): warning C4180: qualifier applied to function type has no meaning; ignored
#   pragma warning(disable:4005) // QtCore/qcompilerdetection.h(896): warning C4005: 'Q_COMPILER_INITIALIZER_LISTS' : macro redefinition
#   pragma warning(disable:4251) // qtsql\qsqlindex.h(66) : warning C4251 : 'QSqlIndex::sorts' : class 'QList<bool>' needs to have dll - interface to be used by clients of class 'QSqlIndex'
#   pragma warning(disable:4244) // QtGui/qvector2d.h(131): warning C4244: 'initializing' : conversion from 'int' to 'float', possible loss of data
#endif

#ifdef QT_CORE_LIB
# include <QtCore>
#endif

#ifdef QT_CONCURRENT_LIB
# include <QtConcurrent>
#endif

#ifdef QT_GUI_LIB
# include <QtGui>
#endif

#ifdef QT_WIDGETS_LIB
# include <QtWidgets>
#endif

#ifdef QT_MULTIMEDIA_LIB
# include <QtMultimedia>
#endif

#ifdef QT_NETWORK_LIB
# include <QtNetwork>
#endif

#ifdef QT_XML_LIB
# include <QtXml>
#endif

#ifdef QT_QML_LIB
# include <QtQml>
#endif

#ifdef QT_QUICK_LIB
# include <QtQuick>
#endif

#ifdef QT_SQL_LIB
# include <QtSql>
#endif

#ifdef QT_PRINTSUPPORT_LIB
# include <QtPrintSupport>
#endif

#ifdef QT_XLSX_LIB
# include <QtXlsx>
#endif

#ifdef _MSC_VER
#   pragma warning(pop)
#endif
