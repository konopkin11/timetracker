#include <QProcess>
#include <QString>

QString executeAppleScript(const QString &script) {
    QProcess process;
    process.start("osascript", QStringList() << "-e" << script);
    process.waitForFinished();
    QByteArray result = process.readAll();
    return QString::fromUtf8(result).trimmed();
}

std::tuple<QString, QString, QString> getActiveWindowAndApp() {
    QString getActiveAppNameScript = R"(
        tell application "System Events"
            set frontmostProcess to first process whose frontmost is true
            set frontmostApplication to application file of frontmostProcess
            return displayed name of frontmostApplication
        end tell
    )";

    QString getActiveWindowNameScript = R"(
        tell application "System Events"
            set frontAppWindows to name of every window of (first application process whose frontmost is true)
        end tell
    )";

    QString getOperaGXUrlScript = R"(
        tell application "Opera GX"
            return URL of active tab of front window
        end tell
    )";

    QString appName = executeAppleScript(getActiveAppNameScript);
    QString windowName = executeAppleScript(getActiveWindowNameScript);
    QString url = "";

    if (appName == "Opera GX.app") {
        url = executeAppleScript(getOperaGXUrlScript);
    }

    return std::make_tuple(appName, windowName, url);
}
