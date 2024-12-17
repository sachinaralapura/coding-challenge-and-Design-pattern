#include "proxy.h"

int main()
{
    Server *server = new ProxyServer();
    list<string> bannedSites = {"https://www.vpnbook.com/", "https://psiphon.ca/", "Phishing.org", "Fraud.org", "Darknetlive.com", "https://www.spokeo.com/"};
    for (string site : bannedSites)
        server->addBannedSites(site);

    server->connectTo("https://www.vpnbook.com/");
    server->connectTo("www.google.com");
    server->removeBannedSite("https://www.vpnbook.com/");
    server->connectTo("https://www.vpnbook.com/");

    return 0;
}
