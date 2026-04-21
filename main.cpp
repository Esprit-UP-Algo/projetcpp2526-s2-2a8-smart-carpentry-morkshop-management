#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

#include "connection.h"
#include "mainwindow.h"

#ifdef _WIN32
  #include <windows.h>

// Force Windows to load OpenCV DLLs from ./opencv next to the exe (avoid PATH mismatches)
static void forceOpenCVDllDir()
{
    const QString dllDir = QDir(QCoreApplication::applicationDirPath()).filePath("opencv");
    SetDllDirectoryW(reinterpret_cast<LPCWSTR>(dllDir.utf16()));
    qDebug() << "OpenCV DLL dir forced to:" << dllDir;
}

// Print which OpenCV DLL is actually loaded (helps confirm mismatch)
static void dumpLoadedOpenCV()
{
    const char* dlls[] = {
        "opencv_world4100.dll","opencv_world4100d.dll",
        "opencv_world490.dll","opencv_world490d.dll",
        "opencv_world480.dll","opencv_world480d.dll",
        "opencv_world470.dll","opencv_world470d.dll",
        "opencv_world460.dll","opencv_world460d.dll"
    };

    for (auto name : dlls) {
        HMODULE h = GetModuleHandleA(name);
        if (!h) continue;
        char path[MAX_PATH]{0};
        GetModuleFileNameA(h, path, MAX_PATH);
        qDebug() << "Loaded" << name << "from" << path;
    }
}
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef _WIN32
    // ✅ Call this BEFORE any OpenCV code runs
    forceOpenCVDllDir();
#endif

    Connection c;
    if (c.createconnect()) {
        QMessageBox::information(nullptr, "DONE", "Connection successful");
    } else {
        QMessageBox::critical(nullptr, "ERROR", "Connection failed");
    }

    MainWindow w;
    w.show();

#ifdef _WIN32
    // Useful diagnostic after startup (once OpenCV is loaded)
    dumpLoadedOpenCV();
#endif

    return a.exec();
}
