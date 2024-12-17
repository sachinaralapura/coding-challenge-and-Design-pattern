#include <iostream>
using namespace std;
//  ------------------------- Handler Interface -------------------------

enum REQ
{
    PASS,
    TOKEN,
    CERTI
};

class Request
{
private:
    REQ request;

public:
    Request() {}
    Request(REQ req) : request(req) {}
    void setKind(REQ req) { this->request = req; }
    REQ getKind() const { return this->request; }
};

class AuthenticationHandler
{
public:
    virtual void setHandler(AuthenticationHandler *handler) = 0;
    virtual void handleRequest(Request *req) = 0;
};

// ------------------------- Concrete Handlers -------------------------
class PasswordAuthenticationHandler : public AuthenticationHandler
{
public:
    void setHandler(AuthenticationHandler *handler) override { this->next = handler; }
    void handleRequest(Request *req) override
    {
        if (req->getKind() == REQ::PASS)
        {
            cout << "Handling Password request" << endl;
        }
        else if (this->next)
            next->handleRequest(req);
        else
            cout << "Handler not set" << endl;
    }

private:
    AuthenticationHandler *next;
};

// ------------------------- Concrete Handlers -------------------------
class TokenAuthenticationHandler : public AuthenticationHandler
{
public:
    void setHandler(AuthenticationHandler *handler) override { this->next = handler; }
    void handleRequest(Request *req) override
    {
        if (req->getKind() == REQ::TOKEN)
        {
            cout << "Handler Token request" << endl;
        }
        else if (this->next)
            next->handleRequest(req);
        else
            cout << "Handler not set" << endl;
    }

private:
    AuthenticationHandler *next;
};

// ------------------------- Concrete Handlers -------------------------
class CertificateAuthenticationHandler : public AuthenticationHandler
{
public:
    void setHandler(AuthenticationHandler *handler) override { this->next = handler; }
    void handleRequest(Request *req) override
    {
        if (req->getKind() == REQ::CERTI)
        {
            cout << "Handler Certificate request" << endl;
        }
        else if (this->next)
            next->handleRequest(req);
        else
            cout << "Handler not set" << endl;
    }

private:
    AuthenticationHandler *next;
};

void chain(Request *req)
{
    AuthenticationHandler *phandler = new PasswordAuthenticationHandler();
    AuthenticationHandler *Thandler = new TokenAuthenticationHandler();
    AuthenticationHandler *Chandler = new CertificateAuthenticationHandler();
    phandler->setHandler(Thandler);
    Thandler->setHandler(Chandler);

    phandler->handleRequest(req);
}

int main()
{
    Request *request = new Request(REQ::CERTI);
    chain(request);
    return 0;
}
