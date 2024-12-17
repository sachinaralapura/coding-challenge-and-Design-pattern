
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

bool contains(const std::list<string> &list, string value)
{
    return find(list.begin(), list.end(), value) != list.end();
}

// subject

class Server
{
public:
    // virtual ~Server() {}
    virtual void connectTo(string url) = 0;
    virtual void addBannedSites(string) = 0;
    virtual void removeBannedSite(string) = 0;
};

// RealSubject

class RealServer : public Server
{
public:
    void connectTo(string url) override
    {
        cout << "Opened Connetion to " << url << endl;
    }
    void addBannedSites(string) override{};
    void removeBannedSite(string) override{};
};

// Proxy
class ProxyServer : public Server
{
private:
    list<string> bannedSites;
    Server *server;

public:
    void connectTo(string url) override
    {
        if (contains(this->bannedSites, url))
        {
            cout << "Access Denied to " << url << endl;
            return;
        }
        server = new RealServer();
        server->connectTo(url);
        delete server;
    }

    void addBannedSites(string site) override
    {
        this->bannedSites.push_back(site);
    }

    void removeBannedSite(string site) override
    {
        this->bannedSites.remove(site);
    }
};