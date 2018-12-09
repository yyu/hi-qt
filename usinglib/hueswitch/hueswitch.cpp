#include "hueswitch.h"

#include <cstring>
#include <curl/curl.h>

#include <QtGui>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>

#define HUE_IP "192.168.10.110"
#define HUE_USER "sUvh09ovb7BgQnPjONJB19jsZuoEMMb91tI0nCAm"

/*
 * payload is tiny; safely assuming data size < (size * nmemb)
 */
static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *stream)
{
    (void)size;
    (void)nmemb;

    char * s = static_cast<char*>(stream);
    size_t len = ::strlen(s);
    memcpy(ptr, stream, len);
    return len;
}

static bool do_curl(const char * url, const char * payload)
{
    bool ok = true;

    curl_global_init(CURL_GLOBAL_ALL); /* In windows, this will init the winsock stuff */

    CURL * curl = curl_easy_init(); /* get a curl handle */
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3L); /* timeout: 3s */
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L); /* enable uploading */
        curl_easy_setopt(curl, CURLOPT_PUT, 1L); /* HTTP PUT please */
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_READDATA, payload);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, static_cast<long>(strlen(payload)));

        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            ok = false;
        }

        curl_easy_cleanup(curl); /* always cleanup */
    } else {
        ok = false;
    }

    curl_global_cleanup();
    return ok;
}

static bool switch_hue(bool on)
{
    return do_curl("http://" HUE_IP "/api/" HUE_USER "/lights/2/state", on ? "{\"on\":true}" : "{\"on\":false}");
}

void HueSwitch::switchOn()
{
    if (switch_hue(true)) {
        trayIcon->setIcon(iconMap["on"]);
    }
}

void HueSwitch::switchOff()
{
    if (switch_hue(false)) {
        trayIcon->setIcon(iconMap["off"]);
    }
}

HueSwitch::HueSwitch(QWidget *parent) :
    QDialog(parent)
{
    qDebug() << "starting ...";

    iconMap["__"] = QIcon(":/images/bulb.png");
    iconMap["on"] = QIcon(":/images/table-light-white.png");
    iconMap["off"] = QIcon(":/images/table-light-black.png");

    QAction* switchOnAction = new QAction(tr("Switch O&n"), this);
    QAction* switchOffAction = new QAction(tr("Switch O&ff"), this);
    QAction* quitAction = new QAction(tr("&Quit"), this);

    connect(switchOnAction, SIGNAL(triggered()), this, SLOT(switchOn()));
    connect(switchOffAction, SIGNAL(triggered()), this, SLOT(switchOff()));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(switchOnAction);
    trayIconMenu->addAction(switchOffAction);
    trayIconMenu->addAction(quitAction);
    trayIconMenu->addSeparator();

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(iconMap["__"]);
    trayIcon->show();

    switchOn();

    qDebug() << "started";
}

HueSwitch::~HueSwitch()
{
}
